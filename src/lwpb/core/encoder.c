/** @file encoder.c
 * 
 * Implementation of the protocol buffers encoder.
 * 
 * Copyright 2009 Simon Kallweit
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <lwpb/lwpb.h>

#include "private.h"

#define MSG_RESERVE_BYTES 10

// Encoder utilities

/**
 * Encodes a variable integer in base-128 format.
 * See http://code.google.com/apis/protocolbuffers/docs/encoding.html for more
 * information.
 * @param buf Memory buffer
 * @param varint Value to encode
 * @return Returns LWPB_ERR_OK if successful or LWPB_ERR_END_OF_BUF if there
 * was not enough space left in the memory buffer. 
 */
static lwpb_err_t encode_varint(struct lwpb_nested_buf *buf, u64_t varint)
{
    do {        
        u8_t val;
        if (varint > 127) {
            val = 0x80 | (varint & 0x7F);
        } else {
            val  = (varint & 0x7F);
        }
        if(!lwpb_nested_buf_push_bytes(buf, &val, 1)) return LWPB_ERR_END_OF_BUF;

        varint >>= 7;
    } while (varint);
    
    return LWPB_ERR_OK;
}

/**
 * Encodes a 32 bit integer.
 * @param buf Memory buffer
 * @param value Value to encode
 * @return Returns LWPB_ERR_OK if successful or LWPB_ERR_END_OF_BUF if there
 * was not enough space left in the memory buffer. 
 */
static lwpb_err_t encode_32bit(struct lwpb_nested_buf *buf, u32_t value)
{
    if (!lwpb_buf_make_space(buf->parent, buf->pos + 4))
        return LWPB_ERR_END_OF_BUF;

    u8_t bigEndian[4];
    
    bigEndian[0] = (value) & 0xff;
    bigEndian[1] = (value >> 8) & 0xff;
    bigEndian[2] = (value >> 16) & 0xff;
    bigEndian[3] = (value >> 24) & 0xff;

    if(!lwpb_nested_buf_push_bytes(buf, bigEndian, 4)) return LWPB_ERR_END_OF_BUF;
    
    return LWPB_ERR_OK;
}

/**
 * Encodes a 64 bit integer.
 * @param buf Memory buffer
 * @param value Value to encode
 * @return Returns LWPB_ERR_OK if successful or LWPB_ERR_END_OF_BUF if there
 * was not enough space left in the memory buffer. 
 */
static lwpb_err_t encode_64bit(struct lwpb_nested_buf *buf, u64_t value)
{
    u8_t buffer[8];
    
    buffer[0] = (value) & 0xff;
    buffer[1] = (value >> 8) & 0xff;
    buffer[2] = (value >> 16) & 0xff;
    buffer[3] = (value >> 24) & 0xff;
    value >>= 32;
    buffer[4] = (value) & 0xff;
    buffer[5] = (value >> 8) & 0xff;
    buffer[6] = (value >> 16) & 0xff;
    buffer[7] = (value >> 24) & 0xff;
    if(!lwpb_nested_buf_push_bytes(buf, buffer, 8)) return LWPB_ERR_END_OF_BUF;    
    
    return LWPB_ERR_OK;
}

/**
 * Pushes the encoder stack.
 * @param encoder Encoder
 * @return Returns the top stack frame.
 */
static struct lwpb_encoder_stack_frame *push_stack_frame(struct lwpb_encoder *encoder)
{
    encoder->depth++;
    LWPB_ASSERT(encoder->depth <= LWPB_MAX_DEPTH, "Message nesting too deep");
    return &encoder->stack[encoder->depth - 1];
}

/**
 * Pops the encoder stack.
 * @param encoder Encoder
 * @return Returns the top stack frame.
 */
static struct lwpb_encoder_stack_frame *pop_stack_frame(struct lwpb_encoder *encoder)
{
    encoder->depth--;
    LWPB_ASSERT(encoder->depth > 0, "Message nesting too shallow");
    return &encoder->stack[encoder->depth - 1];
}

// Encoder

/**
 * Initializes the encoder.
 * @param encoder Encoder
 */
void lwpb_encoder_init(struct lwpb_encoder *encoder)
{
    encoder->depth = 0;
}

void lwpb_encoder_start_common(struct lwpb_encoder *encoder,
                               const struct lwpb_msg_desc *msg_desc){

    struct lwpb_encoder_stack_frame *frame = &encoder->stack[0];
    
    encoder->depth = 1;
    encoder->packed = 0;
    
    lwpb_nested_buf_init(&frame->nested_buf, &encoder->buf, 0);
    frame->field_desc = NULL;
    frame->msg_desc = msg_desc;
}

/**
 * Starts encoding a message.
 * @param encoder Encoder
 * @param msg_desc Root message descriptor
 * @param data Data buffer to encode into
 * @param len Length of data buffer
 */
void lwpb_encoder_start(struct lwpb_encoder *encoder,
                        const struct lwpb_msg_desc *msg_desc,
                        void *data, size_t len)
{
    lwpb_encoder_start_common(encoder, msg_desc);
    lwpb_buf_init(&encoder->buf, data, len, 0);
}

/* Just like lwpb_encoder_start, but allocated memory dynamically, starting with 
 * initial length bytes */
void lwpb_encoder_start_dynamic_with_length(struct lwpb_encoder *encoder, 
                                            const struct lwpb_msg_desc *msg_desc,
                                            size_t initial_len){
    lwpb_encoder_start_common(encoder, msg_desc);    
    lwpb_buf_init(&encoder->buf, malloc(initial_len), initial_len, 0);
}

/* Start encoding with dynamic buffer using a default length
 */
void lwpb_encoder_start_dynamic(struct lwpb_encoder *encoder, 
                                const struct lwpb_msg_desc *msg_desc)
{
    lwpb_encoder_start_dynamic_with_length(encoder, msg_desc, 128);
}
    


/**
 * Finishes encoding a message.
 * @param encoder Encoder
 * @return Returns the total size of the encoded message.
 */
size_t lwpb_encoder_finish(struct lwpb_encoder *encoder)
{
    return lwpb_nested_buf_used(&encoder->stack[0].nested_buf);
}

/**
 * Finished encoding a message using a dynamic buffer
 * @param encoder Encoder
 * @param size - Populated with size of buffer on return
 * @return Returns the buffer.  This transfers pointer ownership, so you must free the buffer when done.
 */

u8_t *lwpb_encoder_finish_dynamic(struct lwpb_encoder *encoder, size_t *size){
    *size = lwpb_nested_buf_used(&encoder->stack[0].nested_buf);
    return encoder->buf.base;
}


/**
 * Starts encoding a nested message.
 * @param encoder Encoder
 * @param field_desc Field descriptor holding the nested message
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_nested_start(struct lwpb_encoder *encoder,
                                     const struct lwpb_field_desc *field_desc)
{
    struct lwpb_encoder_stack_frame *frame, *new_frame;
    
    LWPB_ASSERT(field_desc->opts.typ == LWPB_MESSAGE, "Field is not a message");

    // Get parent frame
    frame = &encoder->stack[encoder->depth - 1];

    // Create a new frame
    new_frame = push_stack_frame(encoder);
    new_frame->field_desc = field_desc;
    new_frame->msg_desc = field_desc->msg_desc;
    
    // Reserve a few bytes for the field on the parent frame. This is where
    // the field key (message) and the message length will be stored, once it
    // is known.
    if (!lwpb_buf_make_space(frame->nested_buf.parent, frame->nested_buf.pos + MSG_RESERVE_BYTES))
        return LWPB_ERR_END_OF_BUF;

    lwpb_nested_buf_init(&new_frame->nested_buf, frame->nested_buf.parent, frame->nested_buf.pos + MSG_RESERVE_BYTES);
    
    return LWPB_ERR_OK;
}

/**
 * Ends encoding a nested message.
 * @param encoder Encoder
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_nested_end(struct lwpb_encoder *encoder)
{
    struct lwpb_encoder_stack_frame *frame;
    union lwpb_value value;
    
    // Get current frame
    frame = &encoder->stack[encoder->depth - 1];

    // Pop the stack
    pop_stack_frame(encoder);

    value.message.data = frame->nested_buf.parent->base + frame->nested_buf.start;
    value.message.len = lwpb_nested_buf_used(&frame->nested_buf);
    return lwpb_encoder_add_field(encoder, frame->field_desc, &value);
}

/**
 * Starts encoding a packed repeated field.
 * @param encoder Encoder
 * @param field_desc Field descriptor of packed repeated field
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_packed_repeated_start(struct lwpb_encoder *encoder,
                                              const struct lwpb_field_desc *field_desc)
{
    struct lwpb_encoder_stack_frame *frame, *new_frame;

    LWPB_ASSERT(LWPB_IS_PACKED_REPEATED(field_desc),
                "Field is not repeated packed");
    
    LWPB_ASSERT(!encoder->packed, "Packed repeated fields must not be nested");
    
    // Get parent frame
    frame = &encoder->stack[encoder->depth - 1];

    // Create a new frame
    new_frame = push_stack_frame(encoder);
    new_frame->field_desc = field_desc;
    new_frame->msg_desc = NULL;
    
    // Reserve a few bytes for the field on the parent frame. This is where
    // the field key (type) and the message length will be stored, once it
    // is known.
    if (!lwpb_buf_make_space(frame->nested_buf.parent, frame->nested_buf.pos + MSG_RESERVE_BYTES))
        return LWPB_ERR_END_OF_BUF;

    lwpb_nested_buf_init(&new_frame->nested_buf, frame->nested_buf.parent, frame->nested_buf.pos + MSG_RESERVE_BYTES);
    
    // Enter packed repeated mode
    encoder->packed = 1;
    
    return LWPB_ERR_OK;
}

/**
 * Ends encoding a packed repeated field.
 * @param encoder Encoder
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_packed_repeated_end(struct lwpb_encoder *encoder)
{
    struct lwpb_encoder_stack_frame *frame;
    union lwpb_value value;
    
    LWPB_ASSERT(encoder->packed, "Not in packed repeated mode");

    // Get current frame
    frame = &encoder->stack[encoder->depth - 1];

    // Pop the stack
    pop_stack_frame(encoder);
    
    // Leave packed repeated mode
    encoder->packed = 0;
    
    value.message.data = frame->nested_buf.parent->base + frame->nested_buf.start;
    value.message.len = lwpb_nested_buf_used(&frame->nested_buf);
    return lwpb_encoder_add_field(encoder, frame->field_desc, &value);
}

/**
 * Encodes a field.
 * @note This method should not normally be used. Use the lwpb_encoder_add_xxx()
 * methods to directly add a field of a given type.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param value Field value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_field(struct lwpb_encoder *encoder,
                                  const struct lwpb_field_desc *field_desc,
                                  union lwpb_value *value)
{
    lwpb_err_t ret;
    struct lwpb_encoder_stack_frame *frame;
    int i;
    u64_t key;
    enum wire_type wire_type = 0;
    union wire_value wire_value;
    
    LWPB_ASSERT(encoder->depth > 0, "Fields can only be added inside a message");
    
    // Get current frame
    frame = &encoder->stack[encoder->depth - 1];
    
    if (encoder->packed) {
        // Check that packed repeated field is not interleaved with other fields
        LWPB_ASSERT(field_desc == frame->field_desc,
                    "Packed repeated fields must not be interleaved with other"
                    "fields");
        if (field_desc != frame->field_desc)
            return LWPB_ERR_INVALID_FIELD;
    } else {
        // Check that field belongs to the current message
        for (i = 0; i < frame->msg_desc->num_fields; i++)
            if (field_desc == &frame->msg_desc->fields[i])
                break;
        if (i == frame->msg_desc->num_fields)
            return LWPB_ERR_UNKNOWN_FIELD;
    }
    
    // Encode wire value
    switch (field_desc->opts.typ) {
    case LWPB_DOUBLE:
        wire_type = WT_64BIT;
        LWPB_MEMCPY(&wire_value.int64, &value->double_, sizeof(double));
        break;
    case LWPB_FLOAT:
        wire_type = WT_32BIT;
        LWPB_MEMCPY(&wire_value.int32, &value->float_, sizeof(float));
        break;
    case LWPB_INT32:
        wire_type = WT_VARINT;
        wire_value.varint = value->int32;
        break;
    case LWPB_UINT32:
        wire_type = WT_VARINT;
        wire_value.varint = value->uint32;
        break;
    case LWPB_SINT32:
        // Zig-zag encoding
        wire_type = WT_VARINT;
        wire_value.varint = (u32_t) ((value->int32 << 1) ^ (value->int32 >> 31));
        break;
    case LWPB_INT64:
        wire_type = WT_VARINT;
        wire_value.varint = value->int64;
        break;
    case LWPB_UINT64:
        wire_type = WT_VARINT;
        wire_value.varint = value->uint64;
        break;
    case LWPB_SINT64:
        // Zig-zag encoding
        wire_type = WT_VARINT;
        wire_value.varint = (u64_t) ((value->int64 << 1) ^ (value->int64 >> 63));
        break;
    case LWPB_FIXED32:
        wire_type = WT_32BIT;
        wire_value.int32 = value->uint32;
        break;
    case LWPB_FIXED64:
        wire_type = WT_64BIT;
        wire_value.int64 = value->uint64;
        break;
    case LWPB_SFIXED32:
        wire_type = WT_32BIT;
        wire_value.int32 = value->int32;
        break;
    case LWPB_SFIXED64:
        wire_type = WT_64BIT;
        wire_value.int64 = value->int64;
        break;
    case LWPB_BOOL:
        wire_type = WT_VARINT;
        wire_value.varint = value->boolean;
        break;
    case LWPB_ENUM:
        wire_type = WT_VARINT;
        wire_value.varint = value->enum_;
        break;
    case LWPB_STRING:
        wire_type = WT_STRING;
        wire_value.string.data = value->string.str;
        wire_value.string.len = value->string.len;
        break;
    case LWPB_BYTES:
        wire_type = WT_STRING;
        wire_value.string.data = value->bytes.data;
        wire_value.string.len = value->bytes.len;
        break;
    case LWPB_MESSAGE:
        wire_type = WT_STRING;
        wire_value.string.data = value->message.data;
        wire_value.string.len = value->message.len;
        break;
    }
    
    // Do not encode field key for packed repeated fields
    if (!encoder->packed) {
        // Override wire value if this is a packed repeated field
        if (LWPB_IS_PACKED_REPEATED(field_desc)) {
            wire_type = WT_STRING;
            wire_value.string.data = value->message.data;
            wire_value.string.len = value->message.len;
        }
        
        key = wire_type | (field_desc->number << 3);
        ret = encode_varint(&frame->nested_buf, key);
        if (ret != LWPB_ERR_OK)
            return ret;
    }
    
    switch (wire_type) {
    case WT_VARINT:
        ret = encode_varint(&frame->nested_buf, wire_value.varint);
        if (ret != LWPB_ERR_OK)
            return ret;
        break;
    case WT_64BIT:
        ret = encode_64bit(&frame->nested_buf, wire_value.int64);
        if (ret != LWPB_ERR_OK)
            return ret;
        break;
    case WT_STRING:
        ret = encode_varint(&frame->nested_buf, wire_value.string.len);
        if (ret != LWPB_ERR_OK)
            return ret;
        if (!lwpb_buf_make_space(frame->nested_buf.parent, frame->nested_buf.pos + wire_value.string.len))
            return LWPB_ERR_END_OF_BUF;
        // Use memmove() when writing a message or packed repeated field as the
        // memory areas are overlapping.
        if ((field_desc->opts.typ == LWPB_MESSAGE) ||
            LWPB_IS_PACKED_REPEATED(field_desc)) {
            LWPB_MEMMOVE(frame->nested_buf.parent->base + frame->nested_buf.pos, wire_value.string.data, wire_value.string.len);
        } else {
            LWPB_MEMCPY(frame->nested_buf.parent->base + frame->nested_buf.pos, wire_value.string.data, wire_value.string.len);
        }
        frame->nested_buf.pos += wire_value.string.len;
        break;
    case WT_32BIT:
        ret = encode_32bit(&frame->nested_buf, wire_value.int32);
        if (ret != LWPB_ERR_OK)
            return ret;
        break;
    default:
        LWPB_ASSERT(1, "Unknown wire type");
        break;
    }
    
    return LWPB_ERR_OK;
}

/**
 * Encodes a field of type 'double'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param double_ Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_double(struct lwpb_encoder *encoder,
                                   const struct lwpb_field_desc *field_desc,
                                   double double_)
{
    union lwpb_value value;
    value.double_ = double_;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'float'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param float_ Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_float(struct lwpb_encoder *encoder,
                                  const struct lwpb_field_desc *field_desc,
                                  float float_)
{
    union lwpb_value value;
    value.float_ = float_;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'int32'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param int32 Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_int32(struct lwpb_encoder *encoder,
                                  const struct lwpb_field_desc *field_desc,
                                  s32_t int32)
{
    union lwpb_value value;
    value.int32 = int32;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'uint32'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param uint32 Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_uint32(struct lwpb_encoder *encoder,
                                   const struct lwpb_field_desc *field_desc,
                                   u32_t uint32)
{
    union lwpb_value value;
    value.uint32 = uint32;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'int64'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param int64 Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_int64(struct lwpb_encoder *encoder,
                                  const struct lwpb_field_desc *field_desc,
                                  s64_t int64)
{
    union lwpb_value value;
    value.int64 = int64;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'uint64'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param uint64 Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_uint64(struct lwpb_encoder *encoder,
                                   const struct lwpb_field_desc *field_desc,
                                   u64_t uint64)
{
    union lwpb_value value;
    value.uint64 = uint64;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'bool'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param bool Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_bool(struct lwpb_encoder *encoder,
                                 const struct lwpb_field_desc *field_desc,
                                 lwpb_bool_t boolean)
{
    union lwpb_value value;
    value.boolean = boolean;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'enum'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param enum_ Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_enum(struct lwpb_encoder *encoder,
                                 const struct lwpb_field_desc *field_desc,
                                 lwpb_enum_t enum_)
{
    union lwpb_value value;
    value.enum_ = enum_;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'string'.
 * @note The string must be null-termiated.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param str Value
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_string(struct lwpb_encoder *encoder,
                                   const struct lwpb_field_desc *field_desc,
                                   char *str)
{
    union lwpb_value value;
    value.string.str = str;
    value.string.len = LWPB_STRLEN(str);
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/**
 * Encodes a field of type 'bytes'.
 * @param encoder Encoder
 * @param field_desc Field descriptor of field to encode
 * @param data Bytes to encode
 * @param len Number of bytes to encode
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_encoder_add_bytes(struct lwpb_encoder *encoder,
                                  const struct lwpb_field_desc *field_desc,
                                  u8_t *data, size_t len)
{
    union lwpb_value value;
    value.string.str = (char *) data;
    value.string.len = len;
    return lwpb_encoder_add_field(encoder, field_desc, &value);
}

/** @file buf.c
 * 
 * Simple memory buffers.
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

/**
 * Initializes a memory buffer. Sets the position to the base address.
 * @param buf Memory buffer
 * @param data Base address of memory
 * @param len Length of memory
 */
void lwpb_buf_init(struct lwpb_buf *buf, void *data, size_t len, lwpb_bool_t resizable)
{
    buf->base = data;
    buf->size = len;
    buf->resizable = resizable;
}

void lwpb_old_buf_init(struct lwpb_old_buf *buf, void *data, size_t len){
    buf->pos = buf->base = data;
    buf->end = data + len;    
}

void lwpb_nested_buf_init(struct lwpb_nested_buf *buf, struct lwpb_buf *parent, size_t start) {
    buf->parent = parent;
    buf->start = start;
    buf->pos = start;
}



/**
 * Returns the number of used bytes in the buffer.
 * @param buf Memory buffer
 * @return Returns the number of used bytes.
 */
size_t lwpb_nested_buf_used(struct lwpb_nested_buf *buf)
{
    return buf->pos - buf->start;
}

size_t lwpb_old_buf_used(struct lwpb_old_buf *buf) {
    return buf->pos - buf->base;
}

size_t lwpb_nested_buf_left(struct lwpb_nested_buf *buf){
    return buf->parent->size - buf->pos;
}

size_t lwpb_old_buf_left(struct lwpb_old_buf *buf) {
    return buf->end - buf->pos;
}

lwpb_bool_t lwpb_buf_resize(struct lwpb_buf *buf, size_t grow_atleast){        
    if(!buf->resizable) return 0;

    size_t new_size = MAX(buf->size <<1, buf->size + grow_atleast); // double size, but make sure we allocate minimum needed

    buf->base = realloc(buf->base, new_size);
  
    if(buf->base) buf->size = new_size;

    return(buf->base != 0);
}

lwpb_bool_t lwpb_buf_make_space(struct lwpb_buf *buf, size_t bytes){
    if(bytes > buf->size) return lwpb_buf_resize(buf, bytes - buf->size);
    else return 1;
}

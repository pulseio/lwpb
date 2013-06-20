// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include <lwpb/lwpb.h>

#include "test_full_pb2.h"

// 'SubMess' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_submess[] = {
    {
        .number = 4,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
};

// 'TestFieldNo15' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testfieldno15[] = {
    {
        .number = 15,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestFieldNo16' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testfieldno16[] = {
    {
        .number = 16,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestFieldNo2047' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testfieldno2047[] = {
    {
        .number = 2047,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestFieldNo2048' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testfieldno2048[] = {
    {
        .number = 2048,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestFieldNo262143' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testfieldno262143[] = {
    {
        .number = 262143,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestFieldNo262144' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testfieldno262144[] = {
    {
        .number = 262144,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestFieldNo33554431' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testfieldno33554431[] = {
    {
        .number = 33554431,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestFieldNo33554432' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testfieldno33554432[] = {
    {
        .number = 33554432,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestMess' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmess[] = {
    {
        .number = 1,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_int32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 2,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_SINT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sint32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 3,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_SFIXED32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sfixed32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 4,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_INT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_int64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 5,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_SINT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sint64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 6,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_SFIXED64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sfixed64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 7,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_UINT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_uint32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 8,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_FIXED32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_fixed32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 9,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_UINT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_uint64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 10,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_FIXED64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_fixed64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 11,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_FLOAT,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_float",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 12,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_DOUBLE,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_double",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 13,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_BOOL,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_boolean",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 14,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_ENUM,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_enum_small",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 15,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_ENUM,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_enum",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 16,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_string",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 17,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_BYTES,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_bytes",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 18,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_MESSAGE,
        .opts.flags = 0,
        .msg_desc = foo_SubMess,
#if LWPB_FIELD_NAMES
        .name = "test_message",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
};

// 'TestMessPacked' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmesspacked[] = {
    {
        .number = 1,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_int32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 2,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_SINT32,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sint32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 3,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_SFIXED32,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sfixed32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 4,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_INT64,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_int64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 5,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_SINT64,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sint64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 6,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_SFIXED64,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sfixed64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 7,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_UINT32,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_uint32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 8,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_FIXED32,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_fixed32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 9,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_UINT64,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_uint64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 10,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_FIXED64,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_fixed64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 11,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_FLOAT,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_float",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 12,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_DOUBLE,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_double",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 13,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_BOOL,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_boolean",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 14,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_ENUM,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_enum_small",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 15,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_ENUM,
        .opts.flags = 0 | LWPB_IS_PACKED,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_enum",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
};

// 'TestMessOptional' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessoptional[] = {
    {
        .number = 1,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_int32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
    {
        .number = 2,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_SINT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sint32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
    {
        .number = 3,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_SFIXED32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sfixed32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
    {
        .number = 4,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_INT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_int64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int64 = 0,
#endif
    },
    {
        .number = 5,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_SINT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sint64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int64 = 0,
#endif
    },
    {
        .number = 6,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_SFIXED64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_sfixed64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int64 = 0,
#endif
    },
    {
        .number = 7,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_UINT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_uint32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint32 = 0,
#endif
    },
    {
        .number = 8,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_FIXED32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_fixed32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint32 = 0,
#endif
    },
    {
        .number = 9,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_UINT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_uint64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint64 = 0,
#endif
    },
    {
        .number = 10,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_FIXED64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_fixed64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint64 = 0,
#endif
    },
    {
        .number = 11,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_FLOAT,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_float",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.float_ = 0,
#endif
    },
    {
        .number = 12,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_DOUBLE,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_double",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.double_ = 0,
#endif
    },
    {
        .number = 13,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_BOOL,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_boolean",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.boolean = 0,
#endif
    },
    {
        .number = 14,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_ENUM,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_enum_small",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
    {
        .number = 15,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_ENUM,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_enum",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
    {
        .number = 16,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_string",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
    {
        .number = 17,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_BYTES,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test_bytes",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
    {
        .number = 18,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_MESSAGE,
        .opts.flags = 0,
        .msg_desc = foo_SubMess,
#if LWPB_FIELD_NAMES
        .name = "test_message",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
};

// 'TestMessRequiredInt32' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredint32[] = {
    {
        .number = 42,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
};

// 'TestMessRequiredSInt32' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredsint32[] = {
    {
        .number = 43,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_SINT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
};

// 'TestMessRequiredSFixed32' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredsfixed32[] = {
    {
        .number = 100,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_SFIXED32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
};

// 'TestMessRequiredInt64' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredint64[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_INT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int64 = 0,
#endif
    },
};

// 'TestMessRequiredSInt64' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredsint64[] = {
    {
        .number = 11,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_SINT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int64 = 0,
#endif
    },
};

// 'TestMessRequiredSFixed64' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredsfixed64[] = {
    {
        .number = 12,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_SFIXED64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int64 = 0,
#endif
    },
};

// 'TestMessRequiredUInt32' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequireduint32[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_UINT32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint32 = 0,
#endif
    },
};

// 'TestMessRequiredFixed32' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredfixed32[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_FIXED32,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint32 = 0,
#endif
    },
};

// 'TestMessRequiredUInt64' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequireduint64[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_UINT64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint64 = 0,
#endif
    },
};

// 'TestMessRequiredFixed64' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredfixed64[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_FIXED64,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint64 = 0,
#endif
    },
};

// 'TestMessRequiredFloat' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredfloat[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_FLOAT,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.float_ = 0,
#endif
    },
};

// 'TestMessRequiredDouble' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequireddouble[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_DOUBLE,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.double_ = 0,
#endif
    },
};

// 'TestMessRequiredBool' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredbool[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_BOOL,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.boolean = 0,
#endif
    },
};

// 'TestMessRequiredEnum' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredenum[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_ENUM,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
};

// 'TestMessRequiredEnumSmall' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredenumsmall[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_ENUM,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 0,
#endif
    },
};

// 'TestMessRequiredString' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredstring[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestMessRequiredBytes' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredbytes[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_BYTES,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
};

// 'TestMessRequiredMessage' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_testmessrequiredmessage[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_MESSAGE,
        .opts.flags = 0,
        .msg_desc = foo_SubMess,
#if LWPB_FIELD_NAMES
        .name = "test",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
};

// 'EmptyMess' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_emptymess[] = {
};

// 'DefaultRequiredValues' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_defaultrequiredvalues[] = {
    {
        .number = 1,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_int32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = -42,
#endif
    },
    {
        .number = 2,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_UINT32,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_uint32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint32 = 666,
#endif
    },
    {
        .number = 3,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_int64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 100000,
#endif
    },
    {
        .number = 4,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_UINT32,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_uint64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint32 = 100001,
#endif
    },
    {
        .number = 5,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_FLOAT,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_float",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.float_ = 0,
#endif
    },
    {
        .number = 6,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_DOUBLE,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_double",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.double_ = 4.5,
#endif
    },
    {
        .number = 7,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_string",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "hi mom\n",
#endif
    },
    {
        .number = 8,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_BYTES,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_bytes",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "a \000 character",
#endif
    },
};

// 'DefaultOptionalValues' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_defaultoptionalvalues[] = {
    {
        .number = 1,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_int32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = -42,
#endif
    },
    {
        .number = 2,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_UINT32,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_uint32",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint32 = 666,
#endif
    },
    {
        .number = 3,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_INT32,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_int64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.int32 = 100000,
#endif
    },
    {
        .number = 4,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_UINT32,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_uint64",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.uint32 = 100001,
#endif
    },
    {
        .number = 5,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_FLOAT,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_float",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.float_ = 0,
#endif
    },
    {
        .number = 6,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_DOUBLE,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_double",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.double_ = 4.5,
#endif
    },
    {
        .number = 7,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_string",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "hi mom\n",
#endif
    },
    {
        .number = 8,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_BYTES,
        .opts.flags = 0 | LWPB_HAS_DEFAULT,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "v_bytes",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "a \000 character",
#endif
    },
};

// 'AllocValues' field descriptors
const struct lwpb_field_desc lwpb_fields_foo_allocvalues[] = {
    {
        .number = 1,
        .opts.label = LWPB_OPTIONAL,
        .opts.typ = LWPB_BYTES,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "o_bytes",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
    {
        .number = 2,
        .opts.label = LWPB_REPEATED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "r_string",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
    {
        .number = 3,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_STRING,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "a_string",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
    {
        .number = 4,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_BYTES,
        .opts.flags = 0,
        .msg_desc = 0,
#if LWPB_FIELD_NAMES
        .name = "a_bytes",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.string.str = "",
#endif
    },
    {
        .number = 5,
        .opts.label = LWPB_REQUIRED,
        .opts.typ = LWPB_MESSAGE,
        .opts.flags = 0,
        .msg_desc = foo_DefaultRequiredValues,
#if LWPB_FIELD_NAMES
        .name = "a_mess",
#endif
#if LWPB_FIELD_DEFAULTS
        .def.null = 0,
#endif
    },
};

// Message descriptors
const struct lwpb_msg_desc lwpb_messages_foo[] = {
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_submess,
#if LWPB_MESSAGE_NAMES
        .name = "SubMess",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testfieldno15,
#if LWPB_MESSAGE_NAMES
        .name = "TestFieldNo15",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testfieldno16,
#if LWPB_MESSAGE_NAMES
        .name = "TestFieldNo16",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testfieldno2047,
#if LWPB_MESSAGE_NAMES
        .name = "TestFieldNo2047",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testfieldno2048,
#if LWPB_MESSAGE_NAMES
        .name = "TestFieldNo2048",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testfieldno262143,
#if LWPB_MESSAGE_NAMES
        .name = "TestFieldNo262143",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testfieldno262144,
#if LWPB_MESSAGE_NAMES
        .name = "TestFieldNo262144",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testfieldno33554431,
#if LWPB_MESSAGE_NAMES
        .name = "TestFieldNo33554431",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testfieldno33554432,
#if LWPB_MESSAGE_NAMES
        .name = "TestFieldNo33554432",
#endif
    },
    {
        .num_fields = 18,
        .fields = lwpb_fields_foo_testmess,
#if LWPB_MESSAGE_NAMES
        .name = "TestMess",
#endif
    },
    {
        .num_fields = 15,
        .fields = lwpb_fields_foo_testmesspacked,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessPacked",
#endif
    },
    {
        .num_fields = 18,
        .fields = lwpb_fields_foo_testmessoptional,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessOptional",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredint32,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredInt32",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredsint32,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredSInt32",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredsfixed32,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredSFixed32",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredint64,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredInt64",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredsint64,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredSInt64",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredsfixed64,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredSFixed64",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequireduint32,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredUInt32",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredfixed32,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredFixed32",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequireduint64,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredUInt64",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredfixed64,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredFixed64",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredfloat,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredFloat",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequireddouble,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredDouble",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredbool,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredBool",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredenum,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredEnum",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredenumsmall,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredEnumSmall",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredstring,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredString",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredbytes,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredBytes",
#endif
    },
    {
        .num_fields = 1,
        .fields = lwpb_fields_foo_testmessrequiredmessage,
#if LWPB_MESSAGE_NAMES
        .name = "TestMessRequiredMessage",
#endif
    },
    {
        .num_fields = 0,
        .fields = lwpb_fields_foo_emptymess,
#if LWPB_MESSAGE_NAMES
        .name = "EmptyMess",
#endif
    },
    {
        .num_fields = 8,
        .fields = lwpb_fields_foo_defaultrequiredvalues,
#if LWPB_MESSAGE_NAMES
        .name = "DefaultRequiredValues",
#endif
    },
    {
        .num_fields = 8,
        .fields = lwpb_fields_foo_defaultoptionalvalues,
#if LWPB_MESSAGE_NAMES
        .name = "DefaultOptionalValues",
#endif
    },
    {
        .num_fields = 5,
        .fields = lwpb_fields_foo_allocvalues,
#if LWPB_MESSAGE_NAMES
        .name = "AllocValues",
#endif
    },
};

// Service descriptors
const struct lwpb_service_desc lwpb_services_foo[] = {
};


// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef __TEST_STRUCT_MAP_PB2_H__
#define __TEST_STRUCT_MAP_PB2_H__

#include <lwpb/lwpb.h>


// 'StructTest.TestEnum' enumeration values
#define TEST_STRUCTTEST_VALUE1 1
#define TEST_STRUCTTEST_VALUE2 2
#define TEST_STRUCTTEST_VALUE3 3

extern const struct lwpb_msg_desc lwpb_messages_test[];

// Message descriptor pointers
#define test_StructTest (&lwpb_messages_test[0])
#define test_StructTest_Nested1 (&lwpb_messages_test[1])
#define test_StructTest_Nested2 (&lwpb_messages_test[2])

extern const struct lwpb_field_desc lwpb_fields_test_structtest[];

// 'StructTest' field descriptor pointers
#define test_StructTest_field_int32 (&lwpb_fields_test_structtest[0])
#define test_StructTest_field_int64 (&lwpb_fields_test_structtest[1])
#define test_StructTest_field_bool (&lwpb_fields_test_structtest[2])
#define test_StructTest_field_enum (&lwpb_fields_test_structtest[3])
#define test_StructTest_field_string (&lwpb_fields_test_structtest[4])
#define test_StructTest_field_bytes (&lwpb_fields_test_structtest[5])
#define test_StructTest_nested1 (&lwpb_fields_test_structtest[6])
#define test_StructTest_nested2 (&lwpb_fields_test_structtest[7])

extern const struct lwpb_field_desc lwpb_fields_test_structtest_nested1[];

// 'Nested1' field descriptor pointers
#define test_StructTest_Nested1_field_int32 (&lwpb_fields_test_structtest_nested1[0])
#define test_StructTest_Nested1_field_int64 (&lwpb_fields_test_structtest_nested1[1])

extern const struct lwpb_field_desc lwpb_fields_test_structtest_nested2[];

// 'Nested2' field descriptor pointers
#define test_StructTest_Nested2_field_string (&lwpb_fields_test_structtest_nested2[0])

extern const struct lwpb_service_desc lwpb_services_test[];

// Service descriptor pointers

#endif // __TEST_STRUCT_MAP_PB2_H__
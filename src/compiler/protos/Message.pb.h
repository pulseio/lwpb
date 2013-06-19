// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef __MESSAGE_PB2_H__
#define __MESSAGE_PB2_H__

#include <lwpb/lwpb.h>

#include "Trace.pb.h"
#include "Event.pb.h"
#include "Sample.pb.h"

// 'PulseMessage.Type' enumeration values
#define PULSEMESSAGE_TRACE 1
#define PULSEMESSAGE_EVENT 2
#define PULSEMESSAGE_SAMPLE_STREAM 3

extern const struct lwpb_msg_desc lwpb_messages_[];

// Message descriptor pointers
#define PulseMessage (&lwpb_messages_[0])
#define PulseMessageStream (&lwpb_messages_[1])

extern const struct lwpb_field_desc lwpb_fields_pulsemessage[];

// 'PulseMessage' field descriptor pointers
#define PulseMessage_type (&lwpb_fields_pulsemessage[0])
#define PulseMessage_trace (&lwpb_fields_pulsemessage[1])
#define PulseMessage_event (&lwpb_fields_pulsemessage[2])
#define PulseMessage_samples (&lwpb_fields_pulsemessage[3])

extern const struct lwpb_field_desc lwpb_fields_pulsemessagestream[];

// 'PulseMessageStream' field descriptor pointers
#define PulseMessageStream_message (&lwpb_fields_pulsemessagestream[0])
#define PulseMessageStream_sessionID (&lwpb_fields_pulsemessagestream[1])
#define PulseMessageStream_clientID (&lwpb_fields_pulsemessagestream[2])
#define PulseMessageStream_timezoneOffset (&lwpb_fields_pulsemessagestream[3])
#define PulseMessageStream_timezoneAbbreviation (&lwpb_fields_pulsemessagestream[4])

extern const struct lwpb_service_desc lwpb_services_[];

// Service descriptor pointers

#endif // __MESSAGE_PB2_H__

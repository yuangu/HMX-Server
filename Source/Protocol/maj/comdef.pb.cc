// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: comdef.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "comdef.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace comdef {

namespace {

const ::google::protobuf::EnumDescriptor* cmd_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_comdef_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_comdef_2eproto() {
  protobuf_AddDesc_comdef_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "comdef.proto");
  GOOGLE_CHECK(file != NULL);
  cmd_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_comdef_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_comdef_2eproto() {
}

void protobuf_AddDesc_comdef_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_comdef_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014comdef.proto\022\006comdef*\376\001\n\003cmd\022\r\n\tmsg_lo"
    "gin\020\001\022\n\n\006msg_ss\020\002\022\014\n\010msg_base\020\n\022\014\n\010msg_r"
    "ole\020\025\022\016\n\nmsg_friend\020\026\022\014\n\010msg_room\020\027\022\014\n\010m"
    "sg_rank\020\030\022\021\n\rmsg_broadcast\020\031\022\014\n\010msg_shop"
    "\020\032\022\014\n\010msg_mail\020\033\022\020\n\014msg_activity\020\034\022\017\n\013ms"
    "g_achieve\020\035\022\r\n\tmsg_event\020\036\022\013\n\007msg_maj\020\037\022"
    "\014\n\010msg_test\020 \022\014\n\010msg_hist\020!\022\n\n\006msg_gm\020\"", 279);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "comdef.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_comdef_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_comdef_2eproto {
  StaticDescriptorInitializer_comdef_2eproto() {
    protobuf_AddDesc_comdef_2eproto();
  }
} static_descriptor_initializer_comdef_2eproto_;
const ::google::protobuf::EnumDescriptor* cmd_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return cmd_descriptor_;
}
bool cmd_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 10:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace comdef

// @@protoc_insertion_point(global_scope)
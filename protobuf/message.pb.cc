// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#include "message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace message {
class StartReqDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<StartReq>
      _instance;
} _StartReq_default_instance_;
}  // namespace message
namespace protobuf_message_2eproto {
static void InitDefaultsStartReq() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::message::_StartReq_default_instance_;
    new (ptr) ::message::StartReq();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::message::StartReq::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_StartReq =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsStartReq}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_StartReq.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::message::StartReq, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::message::StartReq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::message::StartReq, local_ip_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::message::StartReq, local_port_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::message::StartReq, remote_ip_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::message::StartReq, remote_port_),
  0,
  1,
  2,
  3,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::message::StartReq)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::message::_StartReq_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "message.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rmessage.proto\022\007message\"X\n\010StartReq\022\020\n\010"
      "local_ip\030\001 \002(\r\022\022\n\nlocal_port\030\002 \002(\r\022\021\n\tre"
      "mote_ip\030\003 \002(\r\022\023\n\013remote_port\030\004 \002(\r"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 114);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "message.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_message_2eproto
namespace message {

// ===================================================================

void StartReq::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int StartReq::kLocalIpFieldNumber;
const int StartReq::kLocalPortFieldNumber;
const int StartReq::kRemoteIpFieldNumber;
const int StartReq::kRemotePortFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

StartReq::StartReq()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_message_2eproto::scc_info_StartReq.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:message.StartReq)
}
StartReq::StartReq(const StartReq& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&local_ip_, &from.local_ip_,
    static_cast<size_t>(reinterpret_cast<char*>(&remote_port_) -
    reinterpret_cast<char*>(&local_ip_)) + sizeof(remote_port_));
  // @@protoc_insertion_point(copy_constructor:message.StartReq)
}

void StartReq::SharedCtor() {
  ::memset(&local_ip_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&remote_port_) -
      reinterpret_cast<char*>(&local_ip_)) + sizeof(remote_port_));
}

StartReq::~StartReq() {
  // @@protoc_insertion_point(destructor:message.StartReq)
  SharedDtor();
}

void StartReq::SharedDtor() {
}

void StartReq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* StartReq::descriptor() {
  ::protobuf_message_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_message_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const StartReq& StartReq::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_message_2eproto::scc_info_StartReq.base);
  return *internal_default_instance();
}


void StartReq::Clear() {
// @@protoc_insertion_point(message_clear_start:message.StartReq)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 15u) {
    ::memset(&local_ip_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&remote_port_) -
        reinterpret_cast<char*>(&local_ip_)) + sizeof(remote_port_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool StartReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:message.StartReq)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 local_ip = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_local_ip();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &local_ip_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint32 local_port = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_local_port();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &local_port_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint32 remote_ip = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_remote_ip();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &remote_ip_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint32 remote_port = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_remote_port();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &remote_port_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:message.StartReq)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:message.StartReq)
  return false;
#undef DO_
}

void StartReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:message.StartReq)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 local_ip = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->local_ip(), output);
  }

  // required uint32 local_port = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->local_port(), output);
  }

  // required uint32 remote_ip = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->remote_ip(), output);
  }

  // required uint32 remote_port = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->remote_port(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:message.StartReq)
}

::google::protobuf::uint8* StartReq::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:message.StartReq)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 local_ip = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->local_ip(), target);
  }

  // required uint32 local_port = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->local_port(), target);
  }

  // required uint32 remote_ip = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->remote_ip(), target);
  }

  // required uint32 remote_port = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->remote_port(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:message.StartReq)
  return target;
}

size_t StartReq::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:message.StartReq)
  size_t total_size = 0;

  if (has_local_ip()) {
    // required uint32 local_ip = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->local_ip());
  }

  if (has_local_port()) {
    // required uint32 local_port = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->local_port());
  }

  if (has_remote_ip()) {
    // required uint32 remote_ip = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->remote_ip());
  }

  if (has_remote_port()) {
    // required uint32 remote_port = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->remote_port());
  }

  return total_size;
}
size_t StartReq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:message.StartReq)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x0000000f) ^ 0x0000000f) == 0) {  // All required fields are present.
    // required uint32 local_ip = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->local_ip());

    // required uint32 local_port = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->local_port());

    // required uint32 remote_ip = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->remote_ip());

    // required uint32 remote_port = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->remote_port());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void StartReq::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:message.StartReq)
  GOOGLE_DCHECK_NE(&from, this);
  const StartReq* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const StartReq>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:message.StartReq)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:message.StartReq)
    MergeFrom(*source);
  }
}

void StartReq::MergeFrom(const StartReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:message.StartReq)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      local_ip_ = from.local_ip_;
    }
    if (cached_has_bits & 0x00000002u) {
      local_port_ = from.local_port_;
    }
    if (cached_has_bits & 0x00000004u) {
      remote_ip_ = from.remote_ip_;
    }
    if (cached_has_bits & 0x00000008u) {
      remote_port_ = from.remote_port_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void StartReq::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:message.StartReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void StartReq::CopyFrom(const StartReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:message.StartReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StartReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;
  return true;
}

void StartReq::Swap(StartReq* other) {
  if (other == this) return;
  InternalSwap(other);
}
void StartReq::InternalSwap(StartReq* other) {
  using std::swap;
  swap(local_ip_, other->local_ip_);
  swap(local_port_, other->local_port_);
  swap(remote_ip_, other->remote_ip_);
  swap(remote_port_, other->remote_port_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata StartReq::GetMetadata() const {
  protobuf_message_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_message_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace message
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::message::StartReq* Arena::CreateMaybeMessage< ::message::StartReq >(Arena* arena) {
  return Arena::CreateInternal< ::message::StartReq >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

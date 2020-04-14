// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PlayerReadyS2C.proto

#include "PlayerReadyS2C.pb.h"

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
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
class PlayerReadyS2CDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PlayerReadyS2C>
      _instance;
} _PlayerReadyS2C_default_instance_;
namespace protobuf_PlayerReadyS2C_2eproto {
void InitDefaultsPlayerReadyS2CImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::_PlayerReadyS2C_default_instance_;
    new (ptr) ::PlayerReadyS2C();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::PlayerReadyS2C::InitAsDefaultInstance();
}

void InitDefaultsPlayerReadyS2C() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsPlayerReadyS2CImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PlayerReadyS2C, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PlayerReadyS2C, error_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PlayerReadyS2C, uid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::PlayerReadyS2C, isready_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::PlayerReadyS2C)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_PlayerReadyS2C_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "PlayerReadyS2C.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\024PlayerReadyS2C.proto\"=\n\016PlayerReadyS2C"
      "\022\r\n\005error\030\001 \001(\005\022\013\n\003uid\030\002 \001(\005\022\017\n\007isReady\030"
      "\003 \001(\010b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 93);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "PlayerReadyS2C.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_PlayerReadyS2C_2eproto

// ===================================================================

void PlayerReadyS2C::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PlayerReadyS2C::kErrorFieldNumber;
const int PlayerReadyS2C::kUidFieldNumber;
const int PlayerReadyS2C::kIsReadyFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PlayerReadyS2C::PlayerReadyS2C()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_PlayerReadyS2C_2eproto::InitDefaultsPlayerReadyS2C();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:PlayerReadyS2C)
}
PlayerReadyS2C::PlayerReadyS2C(const PlayerReadyS2C& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&error_, &from.error_,
    static_cast<size_t>(reinterpret_cast<char*>(&isready_) -
    reinterpret_cast<char*>(&error_)) + sizeof(isready_));
  // @@protoc_insertion_point(copy_constructor:PlayerReadyS2C)
}

void PlayerReadyS2C::SharedCtor() {
  ::memset(&error_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&isready_) -
      reinterpret_cast<char*>(&error_)) + sizeof(isready_));
  _cached_size_ = 0;
}

PlayerReadyS2C::~PlayerReadyS2C() {
  // @@protoc_insertion_point(destructor:PlayerReadyS2C)
  SharedDtor();
}

void PlayerReadyS2C::SharedDtor() {
}

void PlayerReadyS2C::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PlayerReadyS2C::descriptor() {
  ::protobuf_PlayerReadyS2C_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_PlayerReadyS2C_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PlayerReadyS2C& PlayerReadyS2C::default_instance() {
  ::protobuf_PlayerReadyS2C_2eproto::InitDefaultsPlayerReadyS2C();
  return *internal_default_instance();
}

PlayerReadyS2C* PlayerReadyS2C::New(::google::protobuf::Arena* arena) const {
  PlayerReadyS2C* n = new PlayerReadyS2C;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PlayerReadyS2C::Clear() {
// @@protoc_insertion_point(message_clear_start:PlayerReadyS2C)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&error_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&isready_) -
      reinterpret_cast<char*>(&error_)) + sizeof(isready_));
  _internal_metadata_.Clear();
}

bool PlayerReadyS2C::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PlayerReadyS2C)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int32 error = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &error_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 uid = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &uid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool isReady = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &isready_)));
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
  // @@protoc_insertion_point(parse_success:PlayerReadyS2C)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PlayerReadyS2C)
  return false;
#undef DO_
}

void PlayerReadyS2C::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PlayerReadyS2C)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 error = 1;
  if (this->error() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->error(), output);
  }

  // int32 uid = 2;
  if (this->uid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->uid(), output);
  }

  // bool isReady = 3;
  if (this->isready() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->isready(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:PlayerReadyS2C)
}

::google::protobuf::uint8* PlayerReadyS2C::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:PlayerReadyS2C)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 error = 1;
  if (this->error() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->error(), target);
  }

  // int32 uid = 2;
  if (this->uid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->uid(), target);
  }

  // bool isReady = 3;
  if (this->isready() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->isready(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PlayerReadyS2C)
  return target;
}

size_t PlayerReadyS2C::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:PlayerReadyS2C)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // int32 error = 1;
  if (this->error() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->error());
  }

  // int32 uid = 2;
  if (this->uid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->uid());
  }

  // bool isReady = 3;
  if (this->isready() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PlayerReadyS2C::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:PlayerReadyS2C)
  GOOGLE_DCHECK_NE(&from, this);
  const PlayerReadyS2C* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PlayerReadyS2C>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:PlayerReadyS2C)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:PlayerReadyS2C)
    MergeFrom(*source);
  }
}

void PlayerReadyS2C::MergeFrom(const PlayerReadyS2C& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PlayerReadyS2C)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.error() != 0) {
    set_error(from.error());
  }
  if (from.uid() != 0) {
    set_uid(from.uid());
  }
  if (from.isready() != 0) {
    set_isready(from.isready());
  }
}

void PlayerReadyS2C::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:PlayerReadyS2C)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PlayerReadyS2C::CopyFrom(const PlayerReadyS2C& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PlayerReadyS2C)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerReadyS2C::IsInitialized() const {
  return true;
}

void PlayerReadyS2C::Swap(PlayerReadyS2C* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PlayerReadyS2C::InternalSwap(PlayerReadyS2C* other) {
  using std::swap;
  swap(error_, other->error_);
  swap(uid_, other->uid_);
  swap(isready_, other->isready_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PlayerReadyS2C::GetMetadata() const {
  protobuf_PlayerReadyS2C_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_PlayerReadyS2C_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

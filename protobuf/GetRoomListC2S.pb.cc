// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GetRoomListC2S.proto

#include "GetRoomListC2S.pb.h"

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
class GetRoomListC2SDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<GetRoomListC2S>
      _instance;
} _GetRoomListC2S_default_instance_;
namespace protobuf_GetRoomListC2S_2eproto {
void InitDefaultsGetRoomListC2SImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::_GetRoomListC2S_default_instance_;
    new (ptr) ::GetRoomListC2S();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::GetRoomListC2S::InitAsDefaultInstance();
}

void InitDefaultsGetRoomListC2S() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsGetRoomListC2SImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::GetRoomListC2S, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::GetRoomListC2S)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_GetRoomListC2S_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "GetRoomListC2S.proto", schemas, file_default_instances, TableStruct::offsets, factory,
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
      "\n\024GetRoomListC2S.proto\"\020\n\016GetRoomListC2S"
      "b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 48);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "GetRoomListC2S.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_GetRoomListC2S_2eproto

// ===================================================================

void GetRoomListC2S::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GetRoomListC2S::GetRoomListC2S()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_GetRoomListC2S_2eproto::InitDefaultsGetRoomListC2S();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:GetRoomListC2S)
}
GetRoomListC2S::GetRoomListC2S(const GetRoomListC2S& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:GetRoomListC2S)
}

void GetRoomListC2S::SharedCtor() {
  _cached_size_ = 0;
}

GetRoomListC2S::~GetRoomListC2S() {
  // @@protoc_insertion_point(destructor:GetRoomListC2S)
  SharedDtor();
}

void GetRoomListC2S::SharedDtor() {
}

void GetRoomListC2S::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GetRoomListC2S::descriptor() {
  ::protobuf_GetRoomListC2S_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_GetRoomListC2S_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GetRoomListC2S& GetRoomListC2S::default_instance() {
  ::protobuf_GetRoomListC2S_2eproto::InitDefaultsGetRoomListC2S();
  return *internal_default_instance();
}

GetRoomListC2S* GetRoomListC2S::New(::google::protobuf::Arena* arena) const {
  GetRoomListC2S* n = new GetRoomListC2S;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GetRoomListC2S::Clear() {
// @@protoc_insertion_point(message_clear_start:GetRoomListC2S)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_metadata_.Clear();
}

bool GetRoomListC2S::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GetRoomListC2S)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, _internal_metadata_.mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:GetRoomListC2S)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GetRoomListC2S)
  return false;
#undef DO_
}

void GetRoomListC2S::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GetRoomListC2S)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:GetRoomListC2S)
}

::google::protobuf::uint8* GetRoomListC2S::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:GetRoomListC2S)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GetRoomListC2S)
  return target;
}

size_t GetRoomListC2S::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GetRoomListC2S)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GetRoomListC2S::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GetRoomListC2S)
  GOOGLE_DCHECK_NE(&from, this);
  const GetRoomListC2S* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GetRoomListC2S>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GetRoomListC2S)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GetRoomListC2S)
    MergeFrom(*source);
  }
}

void GetRoomListC2S::MergeFrom(const GetRoomListC2S& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GetRoomListC2S)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void GetRoomListC2S::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GetRoomListC2S)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetRoomListC2S::CopyFrom(const GetRoomListC2S& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GetRoomListC2S)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetRoomListC2S::IsInitialized() const {
  return true;
}

void GetRoomListC2S::Swap(GetRoomListC2S* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GetRoomListC2S::InternalSwap(GetRoomListC2S* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GetRoomListC2S::GetMetadata() const {
  protobuf_GetRoomListC2S_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_GetRoomListC2S_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
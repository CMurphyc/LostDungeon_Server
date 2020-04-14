// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CreateRoomC2S.proto

#include "CreateRoomC2S.pb.h"

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
class CreateRoomC2SDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<CreateRoomC2S>
      _instance;
} _CreateRoomC2S_default_instance_;
namespace protobuf_CreateRoomC2S_2eproto {
void InitDefaultsCreateRoomC2SImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::_CreateRoomC2S_default_instance_;
    new (ptr) ::CreateRoomC2S();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::CreateRoomC2S::InitAsDefaultInstance();
}

void InitDefaultsCreateRoomC2S() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsCreateRoomC2SImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CreateRoomC2S, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CreateRoomC2S, roomsize_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::CreateRoomC2S)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_CreateRoomC2S_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "CreateRoomC2S.proto", schemas, file_default_instances, TableStruct::offsets, factory,
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
      "\n\023CreateRoomC2S.proto\"!\n\rCreateRoomC2S\022\020"
      "\n\010roomSize\030\001 \001(\005b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 64);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "CreateRoomC2S.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_CreateRoomC2S_2eproto

// ===================================================================

void CreateRoomC2S::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CreateRoomC2S::kRoomSizeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CreateRoomC2S::CreateRoomC2S()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_CreateRoomC2S_2eproto::InitDefaultsCreateRoomC2S();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:CreateRoomC2S)
}
CreateRoomC2S::CreateRoomC2S(const CreateRoomC2S& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  roomsize_ = from.roomsize_;
  // @@protoc_insertion_point(copy_constructor:CreateRoomC2S)
}

void CreateRoomC2S::SharedCtor() {
  roomsize_ = 0;
  _cached_size_ = 0;
}

CreateRoomC2S::~CreateRoomC2S() {
  // @@protoc_insertion_point(destructor:CreateRoomC2S)
  SharedDtor();
}

void CreateRoomC2S::SharedDtor() {
}

void CreateRoomC2S::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CreateRoomC2S::descriptor() {
  ::protobuf_CreateRoomC2S_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_CreateRoomC2S_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const CreateRoomC2S& CreateRoomC2S::default_instance() {
  ::protobuf_CreateRoomC2S_2eproto::InitDefaultsCreateRoomC2S();
  return *internal_default_instance();
}

CreateRoomC2S* CreateRoomC2S::New(::google::protobuf::Arena* arena) const {
  CreateRoomC2S* n = new CreateRoomC2S;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void CreateRoomC2S::Clear() {
// @@protoc_insertion_point(message_clear_start:CreateRoomC2S)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  roomsize_ = 0;
  _internal_metadata_.Clear();
}

bool CreateRoomC2S::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CreateRoomC2S)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int32 roomSize = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &roomsize_)));
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
  // @@protoc_insertion_point(parse_success:CreateRoomC2S)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CreateRoomC2S)
  return false;
#undef DO_
}

void CreateRoomC2S::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CreateRoomC2S)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 roomSize = 1;
  if (this->roomsize() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->roomsize(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:CreateRoomC2S)
}

::google::protobuf::uint8* CreateRoomC2S::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:CreateRoomC2S)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 roomSize = 1;
  if (this->roomsize() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->roomsize(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CreateRoomC2S)
  return target;
}

size_t CreateRoomC2S::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CreateRoomC2S)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // int32 roomSize = 1;
  if (this->roomsize() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->roomsize());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CreateRoomC2S::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:CreateRoomC2S)
  GOOGLE_DCHECK_NE(&from, this);
  const CreateRoomC2S* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const CreateRoomC2S>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:CreateRoomC2S)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:CreateRoomC2S)
    MergeFrom(*source);
  }
}

void CreateRoomC2S::MergeFrom(const CreateRoomC2S& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CreateRoomC2S)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.roomsize() != 0) {
    set_roomsize(from.roomsize());
  }
}

void CreateRoomC2S::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:CreateRoomC2S)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CreateRoomC2S::CopyFrom(const CreateRoomC2S& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CreateRoomC2S)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CreateRoomC2S::IsInitialized() const {
  return true;
}

void CreateRoomC2S::Swap(CreateRoomC2S* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CreateRoomC2S::InternalSwap(CreateRoomC2S* other) {
  using std::swap;
  swap(roomsize_, other->roomsize_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata CreateRoomC2S::GetMetadata() const {
  protobuf_CreateRoomC2S_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_CreateRoomC2S_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
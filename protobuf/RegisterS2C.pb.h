// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RegisterS2C.proto

#ifndef PROTOBUF_RegisterS2C_2eproto__INCLUDED
#define PROTOBUF_RegisterS2C_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_RegisterS2C_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsRegisterS2CImpl();
void InitDefaultsRegisterS2C();
inline void InitDefaults() {
  InitDefaultsRegisterS2C();
}
}  // namespace protobuf_RegisterS2C_2eproto
class RegisterS2C;
class RegisterS2CDefaultTypeInternal;
extern RegisterS2CDefaultTypeInternal _RegisterS2C_default_instance_;

enum RegisterS2C_RegisterRet {
  RegisterS2C_RegisterRet_REGISTER_SUCCESS = 0,
  RegisterS2C_RegisterRet_EXIST_USERNAME = 1,
  RegisterS2C_RegisterRet_RegisterS2C_RegisterRet_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  RegisterS2C_RegisterRet_RegisterS2C_RegisterRet_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool RegisterS2C_RegisterRet_IsValid(int value);
const RegisterS2C_RegisterRet RegisterS2C_RegisterRet_RegisterRet_MIN = RegisterS2C_RegisterRet_REGISTER_SUCCESS;
const RegisterS2C_RegisterRet RegisterS2C_RegisterRet_RegisterRet_MAX = RegisterS2C_RegisterRet_EXIST_USERNAME;
const int RegisterS2C_RegisterRet_RegisterRet_ARRAYSIZE = RegisterS2C_RegisterRet_RegisterRet_MAX + 1;

const ::google::protobuf::EnumDescriptor* RegisterS2C_RegisterRet_descriptor();
inline const ::std::string& RegisterS2C_RegisterRet_Name(RegisterS2C_RegisterRet value) {
  return ::google::protobuf::internal::NameOfEnum(
    RegisterS2C_RegisterRet_descriptor(), value);
}
inline bool RegisterS2C_RegisterRet_Parse(
    const ::std::string& name, RegisterS2C_RegisterRet* value) {
  return ::google::protobuf::internal::ParseNamedEnum<RegisterS2C_RegisterRet>(
    RegisterS2C_RegisterRet_descriptor(), name, value);
}
// ===================================================================

class RegisterS2C : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:RegisterS2C) */ {
 public:
  RegisterS2C();
  virtual ~RegisterS2C();

  RegisterS2C(const RegisterS2C& from);

  inline RegisterS2C& operator=(const RegisterS2C& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RegisterS2C(RegisterS2C&& from) noexcept
    : RegisterS2C() {
    *this = ::std::move(from);
  }

  inline RegisterS2C& operator=(RegisterS2C&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RegisterS2C& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RegisterS2C* internal_default_instance() {
    return reinterpret_cast<const RegisterS2C*>(
               &_RegisterS2C_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(RegisterS2C* other);
  friend void swap(RegisterS2C& a, RegisterS2C& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RegisterS2C* New() const PROTOBUF_FINAL { return New(NULL); }

  RegisterS2C* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const RegisterS2C& from);
  void MergeFrom(const RegisterS2C& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(RegisterS2C* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef RegisterS2C_RegisterRet RegisterRet;
  static const RegisterRet REGISTER_SUCCESS =
    RegisterS2C_RegisterRet_REGISTER_SUCCESS;
  static const RegisterRet EXIST_USERNAME =
    RegisterS2C_RegisterRet_EXIST_USERNAME;
  static inline bool RegisterRet_IsValid(int value) {
    return RegisterS2C_RegisterRet_IsValid(value);
  }
  static const RegisterRet RegisterRet_MIN =
    RegisterS2C_RegisterRet_RegisterRet_MIN;
  static const RegisterRet RegisterRet_MAX =
    RegisterS2C_RegisterRet_RegisterRet_MAX;
  static const int RegisterRet_ARRAYSIZE =
    RegisterS2C_RegisterRet_RegisterRet_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  RegisterRet_descriptor() {
    return RegisterS2C_RegisterRet_descriptor();
  }
  static inline const ::std::string& RegisterRet_Name(RegisterRet value) {
    return RegisterS2C_RegisterRet_Name(value);
  }
  static inline bool RegisterRet_Parse(const ::std::string& name,
      RegisterRet* value) {
    return RegisterS2C_RegisterRet_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // int32 error = 1;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  ::google::protobuf::int32 error() const;
  void set_error(::google::protobuf::int32 value);

  // .RegisterS2C.RegisterRet registerRet = 2;
  void clear_registerret();
  static const int kRegisterRetFieldNumber = 2;
  ::RegisterS2C_RegisterRet registerret() const;
  void set_registerret(::RegisterS2C_RegisterRet value);

  // @@protoc_insertion_point(class_scope:RegisterS2C)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 error_;
  int registerret_;
  mutable int _cached_size_;
  friend struct ::protobuf_RegisterS2C_2eproto::TableStruct;
  friend void ::protobuf_RegisterS2C_2eproto::InitDefaultsRegisterS2CImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RegisterS2C

// int32 error = 1;
inline void RegisterS2C::clear_error() {
  error_ = 0;
}
inline ::google::protobuf::int32 RegisterS2C::error() const {
  // @@protoc_insertion_point(field_get:RegisterS2C.error)
  return error_;
}
inline void RegisterS2C::set_error(::google::protobuf::int32 value) {
  
  error_ = value;
  // @@protoc_insertion_point(field_set:RegisterS2C.error)
}

// .RegisterS2C.RegisterRet registerRet = 2;
inline void RegisterS2C::clear_registerret() {
  registerret_ = 0;
}
inline ::RegisterS2C_RegisterRet RegisterS2C::registerret() const {
  // @@protoc_insertion_point(field_get:RegisterS2C.registerRet)
  return static_cast< ::RegisterS2C_RegisterRet >(registerret_);
}
inline void RegisterS2C::set_registerret(::RegisterS2C_RegisterRet value) {
  
  registerret_ = value;
  // @@protoc_insertion_point(field_set:RegisterS2C.registerRet)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::RegisterS2C_RegisterRet> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::RegisterS2C_RegisterRet>() {
  return ::RegisterS2C_RegisterRet_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_RegisterS2C_2eproto__INCLUDED

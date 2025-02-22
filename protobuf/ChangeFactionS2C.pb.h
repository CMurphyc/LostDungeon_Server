// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ChangeFactionS2C.proto

#ifndef PROTOBUF_ChangeFactionS2C_2eproto__INCLUDED
#define PROTOBUF_ChangeFactionS2C_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_ChangeFactionS2C_2eproto {
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
void InitDefaultsChangeFactionS2CImpl();
void InitDefaultsChangeFactionS2C();
inline void InitDefaults() {
  InitDefaultsChangeFactionS2C();
}
}  // namespace protobuf_ChangeFactionS2C_2eproto
class ChangeFactionS2C;
class ChangeFactionS2CDefaultTypeInternal;
extern ChangeFactionS2CDefaultTypeInternal _ChangeFactionS2C_default_instance_;

// ===================================================================

class ChangeFactionS2C : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ChangeFactionS2C) */ {
 public:
  ChangeFactionS2C();
  virtual ~ChangeFactionS2C();

  ChangeFactionS2C(const ChangeFactionS2C& from);

  inline ChangeFactionS2C& operator=(const ChangeFactionS2C& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ChangeFactionS2C(ChangeFactionS2C&& from) noexcept
    : ChangeFactionS2C() {
    *this = ::std::move(from);
  }

  inline ChangeFactionS2C& operator=(ChangeFactionS2C&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ChangeFactionS2C& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ChangeFactionS2C* internal_default_instance() {
    return reinterpret_cast<const ChangeFactionS2C*>(
               &_ChangeFactionS2C_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ChangeFactionS2C* other);
  friend void swap(ChangeFactionS2C& a, ChangeFactionS2C& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ChangeFactionS2C* New() const PROTOBUF_FINAL { return New(NULL); }

  ChangeFactionS2C* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ChangeFactionS2C& from);
  void MergeFrom(const ChangeFactionS2C& from);
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
  void InternalSwap(ChangeFactionS2C* other);
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

  // accessors -------------------------------------------------------

  // int32 error = 1;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  ::google::protobuf::int32 error() const;
  void set_error(::google::protobuf::int32 value);

  // int32 uid = 2;
  void clear_uid();
  static const int kUidFieldNumber = 2;
  ::google::protobuf::int32 uid() const;
  void set_uid(::google::protobuf::int32 value);

  // int32 faction = 3;
  void clear_faction();
  static const int kFactionFieldNumber = 3;
  ::google::protobuf::int32 faction() const;
  void set_faction(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ChangeFactionS2C)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 error_;
  ::google::protobuf::int32 uid_;
  ::google::protobuf::int32 faction_;
  mutable int _cached_size_;
  friend struct ::protobuf_ChangeFactionS2C_2eproto::TableStruct;
  friend void ::protobuf_ChangeFactionS2C_2eproto::InitDefaultsChangeFactionS2CImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChangeFactionS2C

// int32 error = 1;
inline void ChangeFactionS2C::clear_error() {
  error_ = 0;
}
inline ::google::protobuf::int32 ChangeFactionS2C::error() const {
  // @@protoc_insertion_point(field_get:ChangeFactionS2C.error)
  return error_;
}
inline void ChangeFactionS2C::set_error(::google::protobuf::int32 value) {
  
  error_ = value;
  // @@protoc_insertion_point(field_set:ChangeFactionS2C.error)
}

// int32 uid = 2;
inline void ChangeFactionS2C::clear_uid() {
  uid_ = 0;
}
inline ::google::protobuf::int32 ChangeFactionS2C::uid() const {
  // @@protoc_insertion_point(field_get:ChangeFactionS2C.uid)
  return uid_;
}
inline void ChangeFactionS2C::set_uid(::google::protobuf::int32 value) {
  
  uid_ = value;
  // @@protoc_insertion_point(field_set:ChangeFactionS2C.uid)
}

// int32 faction = 3;
inline void ChangeFactionS2C::clear_faction() {
  faction_ = 0;
}
inline ::google::protobuf::int32 ChangeFactionS2C::faction() const {
  // @@protoc_insertion_point(field_get:ChangeFactionS2C.faction)
  return faction_;
}
inline void ChangeFactionS2C::set_faction(::google::protobuf::int32 value) {
  
  faction_ = value;
  // @@protoc_insertion_point(field_set:ChangeFactionS2C.faction)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ChangeFactionS2C_2eproto__INCLUDED

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: HeartbeatS2C.proto

#ifndef PROTOBUF_HeartbeatS2C_2eproto__INCLUDED
#define PROTOBUF_HeartbeatS2C_2eproto__INCLUDED

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

namespace protobuf_HeartbeatS2C_2eproto {
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
void InitDefaultsHeartbeatS2CImpl();
void InitDefaultsHeartbeatS2C();
inline void InitDefaults() {
  InitDefaultsHeartbeatS2C();
}
}  // namespace protobuf_HeartbeatS2C_2eproto
class HeartbeatS2C;
class HeartbeatS2CDefaultTypeInternal;
extern HeartbeatS2CDefaultTypeInternal _HeartbeatS2C_default_instance_;

// ===================================================================

class HeartbeatS2C : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:HeartbeatS2C) */ {
 public:
  HeartbeatS2C();
  virtual ~HeartbeatS2C();

  HeartbeatS2C(const HeartbeatS2C& from);

  inline HeartbeatS2C& operator=(const HeartbeatS2C& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HeartbeatS2C(HeartbeatS2C&& from) noexcept
    : HeartbeatS2C() {
    *this = ::std::move(from);
  }

  inline HeartbeatS2C& operator=(HeartbeatS2C&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const HeartbeatS2C& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HeartbeatS2C* internal_default_instance() {
    return reinterpret_cast<const HeartbeatS2C*>(
               &_HeartbeatS2C_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(HeartbeatS2C* other);
  friend void swap(HeartbeatS2C& a, HeartbeatS2C& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HeartbeatS2C* New() const PROTOBUF_FINAL { return New(NULL); }

  HeartbeatS2C* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const HeartbeatS2C& from);
  void MergeFrom(const HeartbeatS2C& from);
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
  void InternalSwap(HeartbeatS2C* other);
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

  // @@protoc_insertion_point(class_scope:HeartbeatS2C)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 error_;
  mutable int _cached_size_;
  friend struct ::protobuf_HeartbeatS2C_2eproto::TableStruct;
  friend void ::protobuf_HeartbeatS2C_2eproto::InitDefaultsHeartbeatS2CImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HeartbeatS2C

// int32 error = 1;
inline void HeartbeatS2C::clear_error() {
  error_ = 0;
}
inline ::google::protobuf::int32 HeartbeatS2C::error() const {
  // @@protoc_insertion_point(field_get:HeartbeatS2C.error)
  return error_;
}
inline void HeartbeatS2C::set_error(::google::protobuf::int32 value) {
  
  error_ = value;
  // @@protoc_insertion_point(field_set:HeartbeatS2C.error)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_HeartbeatS2C_2eproto__INCLUDED

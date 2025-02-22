// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: EnterRoomC2S.proto

#ifndef PROTOBUF_EnterRoomC2S_2eproto__INCLUDED
#define PROTOBUF_EnterRoomC2S_2eproto__INCLUDED

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

namespace protobuf_EnterRoomC2S_2eproto {
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
void InitDefaultsEnterRoomC2SImpl();
void InitDefaultsEnterRoomC2S();
inline void InitDefaults() {
  InitDefaultsEnterRoomC2S();
}
}  // namespace protobuf_EnterRoomC2S_2eproto
class EnterRoomC2S;
class EnterRoomC2SDefaultTypeInternal;
extern EnterRoomC2SDefaultTypeInternal _EnterRoomC2S_default_instance_;

// ===================================================================

class EnterRoomC2S : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:EnterRoomC2S) */ {
 public:
  EnterRoomC2S();
  virtual ~EnterRoomC2S();

  EnterRoomC2S(const EnterRoomC2S& from);

  inline EnterRoomC2S& operator=(const EnterRoomC2S& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  EnterRoomC2S(EnterRoomC2S&& from) noexcept
    : EnterRoomC2S() {
    *this = ::std::move(from);
  }

  inline EnterRoomC2S& operator=(EnterRoomC2S&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const EnterRoomC2S& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EnterRoomC2S* internal_default_instance() {
    return reinterpret_cast<const EnterRoomC2S*>(
               &_EnterRoomC2S_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(EnterRoomC2S* other);
  friend void swap(EnterRoomC2S& a, EnterRoomC2S& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline EnterRoomC2S* New() const PROTOBUF_FINAL { return New(NULL); }

  EnterRoomC2S* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const EnterRoomC2S& from);
  void MergeFrom(const EnterRoomC2S& from);
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
  void InternalSwap(EnterRoomC2S* other);
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

  // int32 roomId = 1;
  void clear_roomid();
  static const int kRoomIdFieldNumber = 1;
  ::google::protobuf::int32 roomid() const;
  void set_roomid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:EnterRoomC2S)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 roomid_;
  mutable int _cached_size_;
  friend struct ::protobuf_EnterRoomC2S_2eproto::TableStruct;
  friend void ::protobuf_EnterRoomC2S_2eproto::InitDefaultsEnterRoomC2SImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EnterRoomC2S

// int32 roomId = 1;
inline void EnterRoomC2S::clear_roomid() {
  roomid_ = 0;
}
inline ::google::protobuf::int32 EnterRoomC2S::roomid() const {
  // @@protoc_insertion_point(field_get:EnterRoomC2S.roomId)
  return roomid_;
}
inline void EnterRoomC2S::set_roomid(::google::protobuf::int32 value) {
  
  roomid_ = value;
  // @@protoc_insertion_point(field_set:EnterRoomC2S.roomId)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_EnterRoomC2S_2eproto__INCLUDED

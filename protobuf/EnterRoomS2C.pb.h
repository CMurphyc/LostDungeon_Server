// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: EnterRoomS2C.proto

#ifndef PROTOBUF_EnterRoomS2C_2eproto__INCLUDED
#define PROTOBUF_EnterRoomS2C_2eproto__INCLUDED

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
#include "PlayerInfo.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_EnterRoomS2C_2eproto {
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
void InitDefaultsEnterRoomS2CImpl();
void InitDefaultsEnterRoomS2C();
inline void InitDefaults() {
  InitDefaultsEnterRoomS2C();
}
}  // namespace protobuf_EnterRoomS2C_2eproto
class EnterRoomS2C;
class EnterRoomS2CDefaultTypeInternal;
extern EnterRoomS2CDefaultTypeInternal _EnterRoomS2C_default_instance_;

// ===================================================================

class EnterRoomS2C : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:EnterRoomS2C) */ {
 public:
  EnterRoomS2C();
  virtual ~EnterRoomS2C();

  EnterRoomS2C(const EnterRoomS2C& from);

  inline EnterRoomS2C& operator=(const EnterRoomS2C& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  EnterRoomS2C(EnterRoomS2C&& from) noexcept
    : EnterRoomS2C() {
    *this = ::std::move(from);
  }

  inline EnterRoomS2C& operator=(EnterRoomS2C&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const EnterRoomS2C& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EnterRoomS2C* internal_default_instance() {
    return reinterpret_cast<const EnterRoomS2C*>(
               &_EnterRoomS2C_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(EnterRoomS2C* other);
  friend void swap(EnterRoomS2C& a, EnterRoomS2C& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline EnterRoomS2C* New() const PROTOBUF_FINAL { return New(NULL); }

  EnterRoomS2C* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const EnterRoomS2C& from);
  void MergeFrom(const EnterRoomS2C& from);
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
  void InternalSwap(EnterRoomS2C* other);
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

  // .PlayerInfo playerInfo = 2;
  bool has_playerinfo() const;
  void clear_playerinfo();
  static const int kPlayerInfoFieldNumber = 2;
  const ::PlayerInfo& playerinfo() const;
  ::PlayerInfo* release_playerinfo();
  ::PlayerInfo* mutable_playerinfo();
  void set_allocated_playerinfo(::PlayerInfo* playerinfo);

  // int32 error = 1;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  ::google::protobuf::int32 error() const;
  void set_error(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:EnterRoomS2C)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::PlayerInfo* playerinfo_;
  ::google::protobuf::int32 error_;
  mutable int _cached_size_;
  friend struct ::protobuf_EnterRoomS2C_2eproto::TableStruct;
  friend void ::protobuf_EnterRoomS2C_2eproto::InitDefaultsEnterRoomS2CImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EnterRoomS2C

// int32 error = 1;
inline void EnterRoomS2C::clear_error() {
  error_ = 0;
}
inline ::google::protobuf::int32 EnterRoomS2C::error() const {
  // @@protoc_insertion_point(field_get:EnterRoomS2C.error)
  return error_;
}
inline void EnterRoomS2C::set_error(::google::protobuf::int32 value) {
  
  error_ = value;
  // @@protoc_insertion_point(field_set:EnterRoomS2C.error)
}

// .PlayerInfo playerInfo = 2;
inline bool EnterRoomS2C::has_playerinfo() const {
  return this != internal_default_instance() && playerinfo_ != NULL;
}
inline const ::PlayerInfo& EnterRoomS2C::playerinfo() const {
  const ::PlayerInfo* p = playerinfo_;
  // @@protoc_insertion_point(field_get:EnterRoomS2C.playerInfo)
  return p != NULL ? *p : *reinterpret_cast<const ::PlayerInfo*>(
      &::_PlayerInfo_default_instance_);
}
inline ::PlayerInfo* EnterRoomS2C::release_playerinfo() {
  // @@protoc_insertion_point(field_release:EnterRoomS2C.playerInfo)
  
  ::PlayerInfo* temp = playerinfo_;
  playerinfo_ = NULL;
  return temp;
}
inline ::PlayerInfo* EnterRoomS2C::mutable_playerinfo() {
  
  if (playerinfo_ == NULL) {
    playerinfo_ = new ::PlayerInfo;
  }
  // @@protoc_insertion_point(field_mutable:EnterRoomS2C.playerInfo)
  return playerinfo_;
}
inline void EnterRoomS2C::set_allocated_playerinfo(::PlayerInfo* playerinfo) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(playerinfo_);
  }
  if (playerinfo) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      playerinfo = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, playerinfo, submessage_arena);
    }
    
  } else {
    
  }
  playerinfo_ = playerinfo;
  // @@protoc_insertion_point(field_set_allocated:EnterRoomS2C.playerInfo)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_EnterRoomS2C_2eproto__INCLUDED
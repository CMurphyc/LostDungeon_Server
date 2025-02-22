// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CreateRoomS2C.proto

#ifndef PROTOBUF_CreateRoomS2C_2eproto__INCLUDED
#define PROTOBUF_CreateRoomS2C_2eproto__INCLUDED

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

namespace protobuf_CreateRoomS2C_2eproto {
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
void InitDefaultsCreateRoomS2CImpl();
void InitDefaultsCreateRoomS2C();
inline void InitDefaults() {
  InitDefaultsCreateRoomS2C();
}
}  // namespace protobuf_CreateRoomS2C_2eproto
class CreateRoomS2C;
class CreateRoomS2CDefaultTypeInternal;
extern CreateRoomS2CDefaultTypeInternal _CreateRoomS2C_default_instance_;

// ===================================================================

class CreateRoomS2C : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CreateRoomS2C) */ {
 public:
  CreateRoomS2C();
  virtual ~CreateRoomS2C();

  CreateRoomS2C(const CreateRoomS2C& from);

  inline CreateRoomS2C& operator=(const CreateRoomS2C& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CreateRoomS2C(CreateRoomS2C&& from) noexcept
    : CreateRoomS2C() {
    *this = ::std::move(from);
  }

  inline CreateRoomS2C& operator=(CreateRoomS2C&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CreateRoomS2C& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CreateRoomS2C* internal_default_instance() {
    return reinterpret_cast<const CreateRoomS2C*>(
               &_CreateRoomS2C_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(CreateRoomS2C* other);
  friend void swap(CreateRoomS2C& a, CreateRoomS2C& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CreateRoomS2C* New() const PROTOBUF_FINAL { return New(NULL); }

  CreateRoomS2C* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CreateRoomS2C& from);
  void MergeFrom(const CreateRoomS2C& from);
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
  void InternalSwap(CreateRoomS2C* other);
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

  // .PlayerInfo roomOwnerInfo = 4;
  bool has_roomownerinfo() const;
  void clear_roomownerinfo();
  static const int kRoomOwnerInfoFieldNumber = 4;
  const ::PlayerInfo& roomownerinfo() const;
  ::PlayerInfo* release_roomownerinfo();
  ::PlayerInfo* mutable_roomownerinfo();
  void set_allocated_roomownerinfo(::PlayerInfo* roomownerinfo);

  // int32 error = 1;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  ::google::protobuf::int32 error() const;
  void set_error(::google::protobuf::int32 value);

  // bool succeed = 2;
  void clear_succeed();
  static const int kSucceedFieldNumber = 2;
  bool succeed() const;
  void set_succeed(bool value);

  // int32 roomId = 3;
  void clear_roomid();
  static const int kRoomIdFieldNumber = 3;
  ::google::protobuf::int32 roomid() const;
  void set_roomid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:CreateRoomS2C)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::PlayerInfo* roomownerinfo_;
  ::google::protobuf::int32 error_;
  bool succeed_;
  ::google::protobuf::int32 roomid_;
  mutable int _cached_size_;
  friend struct ::protobuf_CreateRoomS2C_2eproto::TableStruct;
  friend void ::protobuf_CreateRoomS2C_2eproto::InitDefaultsCreateRoomS2CImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CreateRoomS2C

// int32 error = 1;
inline void CreateRoomS2C::clear_error() {
  error_ = 0;
}
inline ::google::protobuf::int32 CreateRoomS2C::error() const {
  // @@protoc_insertion_point(field_get:CreateRoomS2C.error)
  return error_;
}
inline void CreateRoomS2C::set_error(::google::protobuf::int32 value) {
  
  error_ = value;
  // @@protoc_insertion_point(field_set:CreateRoomS2C.error)
}

// bool succeed = 2;
inline void CreateRoomS2C::clear_succeed() {
  succeed_ = false;
}
inline bool CreateRoomS2C::succeed() const {
  // @@protoc_insertion_point(field_get:CreateRoomS2C.succeed)
  return succeed_;
}
inline void CreateRoomS2C::set_succeed(bool value) {
  
  succeed_ = value;
  // @@protoc_insertion_point(field_set:CreateRoomS2C.succeed)
}

// int32 roomId = 3;
inline void CreateRoomS2C::clear_roomid() {
  roomid_ = 0;
}
inline ::google::protobuf::int32 CreateRoomS2C::roomid() const {
  // @@protoc_insertion_point(field_get:CreateRoomS2C.roomId)
  return roomid_;
}
inline void CreateRoomS2C::set_roomid(::google::protobuf::int32 value) {
  
  roomid_ = value;
  // @@protoc_insertion_point(field_set:CreateRoomS2C.roomId)
}

// .PlayerInfo roomOwnerInfo = 4;
inline bool CreateRoomS2C::has_roomownerinfo() const {
  return this != internal_default_instance() && roomownerinfo_ != NULL;
}
inline const ::PlayerInfo& CreateRoomS2C::roomownerinfo() const {
  const ::PlayerInfo* p = roomownerinfo_;
  // @@protoc_insertion_point(field_get:CreateRoomS2C.roomOwnerInfo)
  return p != NULL ? *p : *reinterpret_cast<const ::PlayerInfo*>(
      &::_PlayerInfo_default_instance_);
}
inline ::PlayerInfo* CreateRoomS2C::release_roomownerinfo() {
  // @@protoc_insertion_point(field_release:CreateRoomS2C.roomOwnerInfo)
  
  ::PlayerInfo* temp = roomownerinfo_;
  roomownerinfo_ = NULL;
  return temp;
}
inline ::PlayerInfo* CreateRoomS2C::mutable_roomownerinfo() {
  
  if (roomownerinfo_ == NULL) {
    roomownerinfo_ = new ::PlayerInfo;
  }
  // @@protoc_insertion_point(field_mutable:CreateRoomS2C.roomOwnerInfo)
  return roomownerinfo_;
}
inline void CreateRoomS2C::set_allocated_roomownerinfo(::PlayerInfo* roomownerinfo) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(roomownerinfo_);
  }
  if (roomownerinfo) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      roomownerinfo = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, roomownerinfo, submessage_arena);
    }
    
  } else {
    
  }
  roomownerinfo_ = roomownerinfo;
  // @@protoc_insertion_point(field_set_allocated:CreateRoomS2C.roomOwnerInfo)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CreateRoomS2C_2eproto__INCLUDED

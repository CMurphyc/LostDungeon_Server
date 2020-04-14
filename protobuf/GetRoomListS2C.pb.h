// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GetRoomListS2C.proto

#ifndef PROTOBUF_GetRoomListS2C_2eproto__INCLUDED
#define PROTOBUF_GetRoomListS2C_2eproto__INCLUDED

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

namespace protobuf_GetRoomListS2C_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsRoomInfoImpl();
void InitDefaultsRoomInfo();
void InitDefaultsGetRoomListS2CImpl();
void InitDefaultsGetRoomListS2C();
inline void InitDefaults() {
  InitDefaultsRoomInfo();
  InitDefaultsGetRoomListS2C();
}
}  // namespace protobuf_GetRoomListS2C_2eproto
class GetRoomListS2C;
class GetRoomListS2CDefaultTypeInternal;
extern GetRoomListS2CDefaultTypeInternal _GetRoomListS2C_default_instance_;
class RoomInfo;
class RoomInfoDefaultTypeInternal;
extern RoomInfoDefaultTypeInternal _RoomInfo_default_instance_;

// ===================================================================

class RoomInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:RoomInfo) */ {
 public:
  RoomInfo();
  virtual ~RoomInfo();

  RoomInfo(const RoomInfo& from);

  inline RoomInfo& operator=(const RoomInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RoomInfo(RoomInfo&& from) noexcept
    : RoomInfo() {
    *this = ::std::move(from);
  }

  inline RoomInfo& operator=(RoomInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RoomInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RoomInfo* internal_default_instance() {
    return reinterpret_cast<const RoomInfo*>(
               &_RoomInfo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(RoomInfo* other);
  friend void swap(RoomInfo& a, RoomInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RoomInfo* New() const PROTOBUF_FINAL { return New(NULL); }

  RoomInfo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const RoomInfo& from);
  void MergeFrom(const RoomInfo& from);
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
  void InternalSwap(RoomInfo* other);
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

  // int32 roomid = 1;
  void clear_roomid();
  static const int kRoomidFieldNumber = 1;
  ::google::protobuf::int32 roomid() const;
  void set_roomid(::google::protobuf::int32 value);

  // int32 maxsize = 2;
  void clear_maxsize();
  static const int kMaxsizeFieldNumber = 2;
  ::google::protobuf::int32 maxsize() const;
  void set_maxsize(::google::protobuf::int32 value);

  // int32 currentsize = 3;
  void clear_currentsize();
  static const int kCurrentsizeFieldNumber = 3;
  ::google::protobuf::int32 currentsize() const;
  void set_currentsize(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:RoomInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 roomid_;
  ::google::protobuf::int32 maxsize_;
  ::google::protobuf::int32 currentsize_;
  mutable int _cached_size_;
  friend struct ::protobuf_GetRoomListS2C_2eproto::TableStruct;
  friend void ::protobuf_GetRoomListS2C_2eproto::InitDefaultsRoomInfoImpl();
};
// -------------------------------------------------------------------

class GetRoomListS2C : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:GetRoomListS2C) */ {
 public:
  GetRoomListS2C();
  virtual ~GetRoomListS2C();

  GetRoomListS2C(const GetRoomListS2C& from);

  inline GetRoomListS2C& operator=(const GetRoomListS2C& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GetRoomListS2C(GetRoomListS2C&& from) noexcept
    : GetRoomListS2C() {
    *this = ::std::move(from);
  }

  inline GetRoomListS2C& operator=(GetRoomListS2C&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const GetRoomListS2C& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetRoomListS2C* internal_default_instance() {
    return reinterpret_cast<const GetRoomListS2C*>(
               &_GetRoomListS2C_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(GetRoomListS2C* other);
  friend void swap(GetRoomListS2C& a, GetRoomListS2C& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GetRoomListS2C* New() const PROTOBUF_FINAL { return New(NULL); }

  GetRoomListS2C* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GetRoomListS2C& from);
  void MergeFrom(const GetRoomListS2C& from);
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
  void InternalSwap(GetRoomListS2C* other);
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

  // repeated .RoomInfo roomsInfo = 2;
  int roomsinfo_size() const;
  void clear_roomsinfo();
  static const int kRoomsInfoFieldNumber = 2;
  const ::RoomInfo& roomsinfo(int index) const;
  ::RoomInfo* mutable_roomsinfo(int index);
  ::RoomInfo* add_roomsinfo();
  ::google::protobuf::RepeatedPtrField< ::RoomInfo >*
      mutable_roomsinfo();
  const ::google::protobuf::RepeatedPtrField< ::RoomInfo >&
      roomsinfo() const;

  // int32 error = 1;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  ::google::protobuf::int32 error() const;
  void set_error(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:GetRoomListS2C)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::RoomInfo > roomsinfo_;
  ::google::protobuf::int32 error_;
  mutable int _cached_size_;
  friend struct ::protobuf_GetRoomListS2C_2eproto::TableStruct;
  friend void ::protobuf_GetRoomListS2C_2eproto::InitDefaultsGetRoomListS2CImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RoomInfo

// int32 roomid = 1;
inline void RoomInfo::clear_roomid() {
  roomid_ = 0;
}
inline ::google::protobuf::int32 RoomInfo::roomid() const {
  // @@protoc_insertion_point(field_get:RoomInfo.roomid)
  return roomid_;
}
inline void RoomInfo::set_roomid(::google::protobuf::int32 value) {
  
  roomid_ = value;
  // @@protoc_insertion_point(field_set:RoomInfo.roomid)
}

// int32 maxsize = 2;
inline void RoomInfo::clear_maxsize() {
  maxsize_ = 0;
}
inline ::google::protobuf::int32 RoomInfo::maxsize() const {
  // @@protoc_insertion_point(field_get:RoomInfo.maxsize)
  return maxsize_;
}
inline void RoomInfo::set_maxsize(::google::protobuf::int32 value) {
  
  maxsize_ = value;
  // @@protoc_insertion_point(field_set:RoomInfo.maxsize)
}

// int32 currentsize = 3;
inline void RoomInfo::clear_currentsize() {
  currentsize_ = 0;
}
inline ::google::protobuf::int32 RoomInfo::currentsize() const {
  // @@protoc_insertion_point(field_get:RoomInfo.currentsize)
  return currentsize_;
}
inline void RoomInfo::set_currentsize(::google::protobuf::int32 value) {
  
  currentsize_ = value;
  // @@protoc_insertion_point(field_set:RoomInfo.currentsize)
}

// -------------------------------------------------------------------

// GetRoomListS2C

// int32 error = 1;
inline void GetRoomListS2C::clear_error() {
  error_ = 0;
}
inline ::google::protobuf::int32 GetRoomListS2C::error() const {
  // @@protoc_insertion_point(field_get:GetRoomListS2C.error)
  return error_;
}
inline void GetRoomListS2C::set_error(::google::protobuf::int32 value) {
  
  error_ = value;
  // @@protoc_insertion_point(field_set:GetRoomListS2C.error)
}

// repeated .RoomInfo roomsInfo = 2;
inline int GetRoomListS2C::roomsinfo_size() const {
  return roomsinfo_.size();
}
inline void GetRoomListS2C::clear_roomsinfo() {
  roomsinfo_.Clear();
}
inline const ::RoomInfo& GetRoomListS2C::roomsinfo(int index) const {
  // @@protoc_insertion_point(field_get:GetRoomListS2C.roomsInfo)
  return roomsinfo_.Get(index);
}
inline ::RoomInfo* GetRoomListS2C::mutable_roomsinfo(int index) {
  // @@protoc_insertion_point(field_mutable:GetRoomListS2C.roomsInfo)
  return roomsinfo_.Mutable(index);
}
inline ::RoomInfo* GetRoomListS2C::add_roomsinfo() {
  // @@protoc_insertion_point(field_add:GetRoomListS2C.roomsInfo)
  return roomsinfo_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::RoomInfo >*
GetRoomListS2C::mutable_roomsinfo() {
  // @@protoc_insertion_point(field_mutable_list:GetRoomListS2C.roomsInfo)
  return &roomsinfo_;
}
inline const ::google::protobuf::RepeatedPtrField< ::RoomInfo >&
GetRoomListS2C::roomsinfo() const {
  // @@protoc_insertion_point(field_list:GetRoomListS2C.roomsInfo)
  return roomsinfo_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_GetRoomListS2C_2eproto__INCLUDED

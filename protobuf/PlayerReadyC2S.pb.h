// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PlayerReadyC2S.proto

#ifndef PROTOBUF_PlayerReadyC2S_2eproto__INCLUDED
#define PROTOBUF_PlayerReadyC2S_2eproto__INCLUDED

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

namespace protobuf_PlayerReadyC2S_2eproto {
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
void InitDefaultsPlayerReadyC2SImpl();
void InitDefaultsPlayerReadyC2S();
inline void InitDefaults() {
  InitDefaultsPlayerReadyC2S();
}
}  // namespace protobuf_PlayerReadyC2S_2eproto
class PlayerReadyC2S;
class PlayerReadyC2SDefaultTypeInternal;
extern PlayerReadyC2SDefaultTypeInternal _PlayerReadyC2S_default_instance_;

// ===================================================================

class PlayerReadyC2S : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:PlayerReadyC2S) */ {
 public:
  PlayerReadyC2S();
  virtual ~PlayerReadyC2S();

  PlayerReadyC2S(const PlayerReadyC2S& from);

  inline PlayerReadyC2S& operator=(const PlayerReadyC2S& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  PlayerReadyC2S(PlayerReadyC2S&& from) noexcept
    : PlayerReadyC2S() {
    *this = ::std::move(from);
  }

  inline PlayerReadyC2S& operator=(PlayerReadyC2S&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const PlayerReadyC2S& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PlayerReadyC2S* internal_default_instance() {
    return reinterpret_cast<const PlayerReadyC2S*>(
               &_PlayerReadyC2S_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(PlayerReadyC2S* other);
  friend void swap(PlayerReadyC2S& a, PlayerReadyC2S& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline PlayerReadyC2S* New() const PROTOBUF_FINAL { return New(NULL); }

  PlayerReadyC2S* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PlayerReadyC2S& from);
  void MergeFrom(const PlayerReadyC2S& from);
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
  void InternalSwap(PlayerReadyC2S* other);
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

  // @@protoc_insertion_point(class_scope:PlayerReadyC2S)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct ::protobuf_PlayerReadyC2S_2eproto::TableStruct;
  friend void ::protobuf_PlayerReadyC2S_2eproto::InitDefaultsPlayerReadyC2SImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PlayerReadyC2S

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_PlayerReadyC2S_2eproto__INCLUDED

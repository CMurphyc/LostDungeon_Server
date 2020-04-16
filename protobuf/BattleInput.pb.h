// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BattleInput.proto

#ifndef PROTOBUF_BattleInput_2eproto__INCLUDED
#define PROTOBUF_BattleInput_2eproto__INCLUDED

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

namespace protobuf_BattleInput_2eproto {
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
void InitDefaultsBattleInputImpl();
void InitDefaultsBattleInput();
inline void InitDefaults() {
  InitDefaultsBattleInput();
}
}  // namespace protobuf_BattleInput_2eproto
class BattleInput;
class BattleInputDefaultTypeInternal;
extern BattleInputDefaultTypeInternal _BattleInput_default_instance_;

// ===================================================================

class BattleInput : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:BattleInput) */ {
 public:
  BattleInput();
  virtual ~BattleInput();

  BattleInput(const BattleInput& from);

  inline BattleInput& operator=(const BattleInput& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BattleInput(BattleInput&& from) noexcept
    : BattleInput() {
    *this = ::std::move(from);
  }

  inline BattleInput& operator=(BattleInput&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const BattleInput& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BattleInput* internal_default_instance() {
    return reinterpret_cast<const BattleInput*>(
               &_BattleInput_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(BattleInput* other);
  friend void swap(BattleInput& a, BattleInput& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BattleInput* New() const PROTOBUF_FINAL { return New(NULL); }

  BattleInput* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const BattleInput& from);
  void MergeFrom(const BattleInput& from);
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
  void InternalSwap(BattleInput* other);
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

  // int32 uid = 1;
  void clear_uid();
  static const int kUidFieldNumber = 1;
  ::google::protobuf::int32 uid() const;
  void set_uid(::google::protobuf::int32 value);

  // int32 moveDirectionX = 2;
  void clear_movedirectionx();
  static const int kMoveDirectionXFieldNumber = 2;
  ::google::protobuf::int32 movedirectionx() const;
  void set_movedirectionx(::google::protobuf::int32 value);

  // int32 moveDirectionY = 3;
  void clear_movedirectiony();
  static const int kMoveDirectionYFieldNumber = 3;
  ::google::protobuf::int32 movedirectiony() const;
  void set_movedirectiony(::google::protobuf::int32 value);

  // int32 attackType = 4;
  void clear_attacktype();
  static const int kAttackTypeFieldNumber = 4;
  ::google::protobuf::int32 attacktype() const;
  void set_attacktype(::google::protobuf::int32 value);

  // int32 attackDirectionX = 5;
  void clear_attackdirectionx();
  static const int kAttackDirectionXFieldNumber = 5;
  ::google::protobuf::int32 attackdirectionx() const;
  void set_attackdirectionx(::google::protobuf::int32 value);

  // int32 attackDirectionY = 6;
  void clear_attackdirectiony();
  static const int kAttackDirectionYFieldNumber = 6;
  ::google::protobuf::int32 attackdirectiony() const;
  void set_attackdirectiony(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:BattleInput)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 uid_;
  ::google::protobuf::int32 movedirectionx_;
  ::google::protobuf::int32 movedirectiony_;
  ::google::protobuf::int32 attacktype_;
  ::google::protobuf::int32 attackdirectionx_;
  ::google::protobuf::int32 attackdirectiony_;
  mutable int _cached_size_;
  friend struct ::protobuf_BattleInput_2eproto::TableStruct;
  friend void ::protobuf_BattleInput_2eproto::InitDefaultsBattleInputImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BattleInput

// int32 uid = 1;
inline void BattleInput::clear_uid() {
  uid_ = 0;
}
inline ::google::protobuf::int32 BattleInput::uid() const {
  // @@protoc_insertion_point(field_get:BattleInput.uid)
  return uid_;
}
inline void BattleInput::set_uid(::google::protobuf::int32 value) {
  
  uid_ = value;
  // @@protoc_insertion_point(field_set:BattleInput.uid)
}

// int32 moveDirectionX = 2;
inline void BattleInput::clear_movedirectionx() {
  movedirectionx_ = 0;
}
inline ::google::protobuf::int32 BattleInput::movedirectionx() const {
  // @@protoc_insertion_point(field_get:BattleInput.moveDirectionX)
  return movedirectionx_;
}
inline void BattleInput::set_movedirectionx(::google::protobuf::int32 value) {
  
  movedirectionx_ = value;
  // @@protoc_insertion_point(field_set:BattleInput.moveDirectionX)
}

// int32 moveDirectionY = 3;
inline void BattleInput::clear_movedirectiony() {
  movedirectiony_ = 0;
}
inline ::google::protobuf::int32 BattleInput::movedirectiony() const {
  // @@protoc_insertion_point(field_get:BattleInput.moveDirectionY)
  return movedirectiony_;
}
inline void BattleInput::set_movedirectiony(::google::protobuf::int32 value) {
  
  movedirectiony_ = value;
  // @@protoc_insertion_point(field_set:BattleInput.moveDirectionY)
}

// int32 attackType = 4;
inline void BattleInput::clear_attacktype() {
  attacktype_ = 0;
}
inline ::google::protobuf::int32 BattleInput::attacktype() const {
  // @@protoc_insertion_point(field_get:BattleInput.attackType)
  return attacktype_;
}
inline void BattleInput::set_attacktype(::google::protobuf::int32 value) {
  
  attacktype_ = value;
  // @@protoc_insertion_point(field_set:BattleInput.attackType)
}

// int32 attackDirectionX = 5;
inline void BattleInput::clear_attackdirectionx() {
  attackdirectionx_ = 0;
}
inline ::google::protobuf::int32 BattleInput::attackdirectionx() const {
  // @@protoc_insertion_point(field_get:BattleInput.attackDirectionX)
  return attackdirectionx_;
}
inline void BattleInput::set_attackdirectionx(::google::protobuf::int32 value) {
  
  attackdirectionx_ = value;
  // @@protoc_insertion_point(field_set:BattleInput.attackDirectionX)
}

// int32 attackDirectionY = 6;
inline void BattleInput::clear_attackdirectiony() {
  attackdirectiony_ = 0;
}
inline ::google::protobuf::int32 BattleInput::attackdirectiony() const {
  // @@protoc_insertion_point(field_get:BattleInput.attackDirectionY)
  return attackdirectiony_;
}
inline void BattleInput::set_attackdirectiony(::google::protobuf::int32 value) {
  
  attackdirectiony_ = value;
  // @@protoc_insertion_point(field_set:BattleInput.attackDirectionY)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_BattleInput_2eproto__INCLUDED

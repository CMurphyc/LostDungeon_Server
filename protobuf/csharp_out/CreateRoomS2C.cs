// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: CreateRoomS2C.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from CreateRoomS2C.proto</summary>
public static partial class CreateRoomS2CReflection {

  #region Descriptor
  /// <summary>File descriptor for CreateRoomS2C.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static CreateRoomS2CReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "ChNDcmVhdGVSb29tUzJDLnByb3RvGhBQbGF5ZXJJbmZvLnByb3RvImMKDUNy",
          "ZWF0ZVJvb21TMkMSDQoFZXJyb3IYASABKAUSDwoHc3VjY2VlZBgCIAEoCBIO",
          "CgZyb29tSWQYAyABKAUSIgoNcm9vbU93bmVySW5mbxgEIAEoCzILLlBsYXll",
          "ckluZm9iBnByb3RvMw=="));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { global::PlayerInfoReflection.Descriptor, },
        new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::CreateRoomS2C), global::CreateRoomS2C.Parser, new[]{ "Error", "Succeed", "RoomId", "RoomOwnerInfo" }, null, null, null)
        }));
  }
  #endregion

}
#region Messages
public sealed partial class CreateRoomS2C : pb::IMessage<CreateRoomS2C> {
  private static readonly pb::MessageParser<CreateRoomS2C> _parser = new pb::MessageParser<CreateRoomS2C>(() => new CreateRoomS2C());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<CreateRoomS2C> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::CreateRoomS2CReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public CreateRoomS2C() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public CreateRoomS2C(CreateRoomS2C other) : this() {
    error_ = other.error_;
    succeed_ = other.succeed_;
    roomId_ = other.roomId_;
    RoomOwnerInfo = other.roomOwnerInfo_ != null ? other.RoomOwnerInfo.Clone() : null;
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public CreateRoomS2C Clone() {
    return new CreateRoomS2C(this);
  }

  /// <summary>Field number for the "error" field.</summary>
  public const int ErrorFieldNumber = 1;
  private int error_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int Error {
    get { return error_; }
    set {
      error_ = value;
    }
  }

  /// <summary>Field number for the "succeed" field.</summary>
  public const int SucceedFieldNumber = 2;
  private bool succeed_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Succeed {
    get { return succeed_; }
    set {
      succeed_ = value;
    }
  }

  /// <summary>Field number for the "roomId" field.</summary>
  public const int RoomIdFieldNumber = 3;
  private int roomId_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int RoomId {
    get { return roomId_; }
    set {
      roomId_ = value;
    }
  }

  /// <summary>Field number for the "roomOwnerInfo" field.</summary>
  public const int RoomOwnerInfoFieldNumber = 4;
  private global::PlayerInfo roomOwnerInfo_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public global::PlayerInfo RoomOwnerInfo {
    get { return roomOwnerInfo_; }
    set {
      roomOwnerInfo_ = value;
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as CreateRoomS2C);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(CreateRoomS2C other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (Error != other.Error) return false;
    if (Succeed != other.Succeed) return false;
    if (RoomId != other.RoomId) return false;
    if (!object.Equals(RoomOwnerInfo, other.RoomOwnerInfo)) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (Error != 0) hash ^= Error.GetHashCode();
    if (Succeed != false) hash ^= Succeed.GetHashCode();
    if (RoomId != 0) hash ^= RoomId.GetHashCode();
    if (roomOwnerInfo_ != null) hash ^= RoomOwnerInfo.GetHashCode();
    if (_unknownFields != null) {
      hash ^= _unknownFields.GetHashCode();
    }
    return hash;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override string ToString() {
    return pb::JsonFormatter.ToDiagnosticString(this);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void WriteTo(pb::CodedOutputStream output) {
    if (Error != 0) {
      output.WriteRawTag(8);
      output.WriteInt32(Error);
    }
    if (Succeed != false) {
      output.WriteRawTag(16);
      output.WriteBool(Succeed);
    }
    if (RoomId != 0) {
      output.WriteRawTag(24);
      output.WriteInt32(RoomId);
    }
    if (roomOwnerInfo_ != null) {
      output.WriteRawTag(34);
      output.WriteMessage(RoomOwnerInfo);
    }
    if (_unknownFields != null) {
      _unknownFields.WriteTo(output);
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int CalculateSize() {
    int size = 0;
    if (Error != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(Error);
    }
    if (Succeed != false) {
      size += 1 + 1;
    }
    if (RoomId != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(RoomId);
    }
    if (roomOwnerInfo_ != null) {
      size += 1 + pb::CodedOutputStream.ComputeMessageSize(RoomOwnerInfo);
    }
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(CreateRoomS2C other) {
    if (other == null) {
      return;
    }
    if (other.Error != 0) {
      Error = other.Error;
    }
    if (other.Succeed != false) {
      Succeed = other.Succeed;
    }
    if (other.RoomId != 0) {
      RoomId = other.RoomId;
    }
    if (other.roomOwnerInfo_ != null) {
      if (roomOwnerInfo_ == null) {
        roomOwnerInfo_ = new global::PlayerInfo();
      }
      RoomOwnerInfo.MergeFrom(other.RoomOwnerInfo);
    }
    _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(pb::CodedInputStream input) {
    uint tag;
    while ((tag = input.ReadTag()) != 0) {
      switch(tag) {
        default:
          _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
          break;
        case 8: {
          Error = input.ReadInt32();
          break;
        }
        case 16: {
          Succeed = input.ReadBool();
          break;
        }
        case 24: {
          RoomId = input.ReadInt32();
          break;
        }
        case 34: {
          if (roomOwnerInfo_ == null) {
            roomOwnerInfo_ = new global::PlayerInfo();
          }
          input.ReadMessage(roomOwnerInfo_);
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code

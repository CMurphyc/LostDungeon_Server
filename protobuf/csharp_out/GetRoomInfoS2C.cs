// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: GetRoomInfoS2C.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from GetRoomInfoS2C.proto</summary>
public static partial class GetRoomInfoS2CReflection {

  #region Descriptor
  /// <summary>File descriptor for GetRoomInfoS2C.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static GetRoomInfoS2CReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "ChRHZXRSb29tSW5mb1MyQy5wcm90bxoQUGxheWVySW5mby5wcm90byJnCg5H",
          "ZXRSb29tSW5mb1MyQxINCgVlcnJvchgBIAEoBRIPCgdzdWNjZWVkGAIgASgI",
          "EhMKC3Jvb21Pd25lcklkGAMgASgFEiAKC3BsYXllcnNJbmZvGAQgAygLMgsu",
          "UGxheWVySW5mb2IGcHJvdG8z"));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { global::PlayerInfoReflection.Descriptor, },
        new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::GetRoomInfoS2C), global::GetRoomInfoS2C.Parser, new[]{ "Error", "Succeed", "RoomOwnerId", "PlayersInfo" }, null, null, null)
        }));
  }
  #endregion

}
#region Messages
public sealed partial class GetRoomInfoS2C : pb::IMessage<GetRoomInfoS2C> {
  private static readonly pb::MessageParser<GetRoomInfoS2C> _parser = new pb::MessageParser<GetRoomInfoS2C>(() => new GetRoomInfoS2C());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<GetRoomInfoS2C> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::GetRoomInfoS2CReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GetRoomInfoS2C() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GetRoomInfoS2C(GetRoomInfoS2C other) : this() {
    error_ = other.error_;
    succeed_ = other.succeed_;
    roomOwnerId_ = other.roomOwnerId_;
    playersInfo_ = other.playersInfo_.Clone();
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GetRoomInfoS2C Clone() {
    return new GetRoomInfoS2C(this);
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

  /// <summary>Field number for the "roomOwnerId" field.</summary>
  public const int RoomOwnerIdFieldNumber = 3;
  private int roomOwnerId_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int RoomOwnerId {
    get { return roomOwnerId_; }
    set {
      roomOwnerId_ = value;
    }
  }

  /// <summary>Field number for the "playersInfo" field.</summary>
  public const int PlayersInfoFieldNumber = 4;
  private static readonly pb::FieldCodec<global::PlayerInfo> _repeated_playersInfo_codec
      = pb::FieldCodec.ForMessage(34, global::PlayerInfo.Parser);
  private readonly pbc::RepeatedField<global::PlayerInfo> playersInfo_ = new pbc::RepeatedField<global::PlayerInfo>();
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public pbc::RepeatedField<global::PlayerInfo> PlayersInfo {
    get { return playersInfo_; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as GetRoomInfoS2C);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(GetRoomInfoS2C other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (Error != other.Error) return false;
    if (Succeed != other.Succeed) return false;
    if (RoomOwnerId != other.RoomOwnerId) return false;
    if(!playersInfo_.Equals(other.playersInfo_)) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (Error != 0) hash ^= Error.GetHashCode();
    if (Succeed != false) hash ^= Succeed.GetHashCode();
    if (RoomOwnerId != 0) hash ^= RoomOwnerId.GetHashCode();
    hash ^= playersInfo_.GetHashCode();
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
    if (RoomOwnerId != 0) {
      output.WriteRawTag(24);
      output.WriteInt32(RoomOwnerId);
    }
    playersInfo_.WriteTo(output, _repeated_playersInfo_codec);
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
    if (RoomOwnerId != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(RoomOwnerId);
    }
    size += playersInfo_.CalculateSize(_repeated_playersInfo_codec);
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(GetRoomInfoS2C other) {
    if (other == null) {
      return;
    }
    if (other.Error != 0) {
      Error = other.Error;
    }
    if (other.Succeed != false) {
      Succeed = other.Succeed;
    }
    if (other.RoomOwnerId != 0) {
      RoomOwnerId = other.RoomOwnerId;
    }
    playersInfo_.Add(other.playersInfo_);
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
          RoomOwnerId = input.ReadInt32();
          break;
        }
        case 34: {
          playersInfo_.AddEntriesFrom(input, _repeated_playersInfo_codec);
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code

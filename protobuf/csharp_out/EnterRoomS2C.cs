// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: EnterRoomS2C.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from EnterRoomS2C.proto</summary>
public static partial class EnterRoomS2CReflection {

  #region Descriptor
  /// <summary>File descriptor for EnterRoomS2C.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static EnterRoomS2CReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "ChJFbnRlclJvb21TMkMucHJvdG8aEFBsYXllckluZm8ucHJvdG8iPgoMRW50",
          "ZXJSb29tUzJDEg0KBWVycm9yGAEgASgFEh8KCnBsYXllckluZm8YAiABKAsy",
          "Cy5QbGF5ZXJJbmZvYgZwcm90bzM="));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { global::PlayerInfoReflection.Descriptor, },
        new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::EnterRoomS2C), global::EnterRoomS2C.Parser, new[]{ "Error", "PlayerInfo" }, null, null, null)
        }));
  }
  #endregion

}
#region Messages
public sealed partial class EnterRoomS2C : pb::IMessage<EnterRoomS2C> {
  private static readonly pb::MessageParser<EnterRoomS2C> _parser = new pb::MessageParser<EnterRoomS2C>(() => new EnterRoomS2C());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<EnterRoomS2C> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::EnterRoomS2CReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public EnterRoomS2C() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public EnterRoomS2C(EnterRoomS2C other) : this() {
    error_ = other.error_;
    PlayerInfo = other.playerInfo_ != null ? other.PlayerInfo.Clone() : null;
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public EnterRoomS2C Clone() {
    return new EnterRoomS2C(this);
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

  /// <summary>Field number for the "playerInfo" field.</summary>
  public const int PlayerInfoFieldNumber = 2;
  private global::PlayerInfo playerInfo_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public global::PlayerInfo PlayerInfo {
    get { return playerInfo_; }
    set {
      playerInfo_ = value;
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as EnterRoomS2C);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(EnterRoomS2C other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (Error != other.Error) return false;
    if (!object.Equals(PlayerInfo, other.PlayerInfo)) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (Error != 0) hash ^= Error.GetHashCode();
    if (playerInfo_ != null) hash ^= PlayerInfo.GetHashCode();
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
    if (playerInfo_ != null) {
      output.WriteRawTag(18);
      output.WriteMessage(PlayerInfo);
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
    if (playerInfo_ != null) {
      size += 1 + pb::CodedOutputStream.ComputeMessageSize(PlayerInfo);
    }
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(EnterRoomS2C other) {
    if (other == null) {
      return;
    }
    if (other.Error != 0) {
      Error = other.Error;
    }
    if (other.playerInfo_ != null) {
      if (playerInfo_ == null) {
        playerInfo_ = new global::PlayerInfo();
      }
      PlayerInfo.MergeFrom(other.PlayerInfo);
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
        case 18: {
          if (playerInfo_ == null) {
            playerInfo_ = new global::PlayerInfo();
          }
          input.ReadMessage(playerInfo_);
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code

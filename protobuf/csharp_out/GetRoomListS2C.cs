// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: GetRoomListS2C.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from GetRoomListS2C.proto</summary>
public static partial class GetRoomListS2CReflection {

  #region Descriptor
  /// <summary>File descriptor for GetRoomListS2C.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static GetRoomListS2CReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "ChRHZXRSb29tTGlzdFMyQy5wcm90byJACghSb29tSW5mbxIOCgZyb29taWQY",
          "ASABKAUSDwoHbWF4c2l6ZRgCIAEoBRITCgtjdXJyZW50c2l6ZRgDIAEoBSI9",
          "Cg5HZXRSb29tTGlzdFMyQxINCgVlcnJvchgBIAEoBRIcCglyb29tc0luZm8Y",
          "AiADKAsyCS5Sb29tSW5mb2IGcHJvdG8z"));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { },
        new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::RoomInfo), global::RoomInfo.Parser, new[]{ "Roomid", "Maxsize", "Currentsize" }, null, null, null),
          new pbr::GeneratedClrTypeInfo(typeof(global::GetRoomListS2C), global::GetRoomListS2C.Parser, new[]{ "Error", "RoomsInfo" }, null, null, null)
        }));
  }
  #endregion

}
#region Messages
public sealed partial class RoomInfo : pb::IMessage<RoomInfo> {
  private static readonly pb::MessageParser<RoomInfo> _parser = new pb::MessageParser<RoomInfo>(() => new RoomInfo());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<RoomInfo> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::GetRoomListS2CReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RoomInfo() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RoomInfo(RoomInfo other) : this() {
    roomid_ = other.roomid_;
    maxsize_ = other.maxsize_;
    currentsize_ = other.currentsize_;
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public RoomInfo Clone() {
    return new RoomInfo(this);
  }

  /// <summary>Field number for the "roomid" field.</summary>
  public const int RoomidFieldNumber = 1;
  private int roomid_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int Roomid {
    get { return roomid_; }
    set {
      roomid_ = value;
    }
  }

  /// <summary>Field number for the "maxsize" field.</summary>
  public const int MaxsizeFieldNumber = 2;
  private int maxsize_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int Maxsize {
    get { return maxsize_; }
    set {
      maxsize_ = value;
    }
  }

  /// <summary>Field number for the "currentsize" field.</summary>
  public const int CurrentsizeFieldNumber = 3;
  private int currentsize_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int Currentsize {
    get { return currentsize_; }
    set {
      currentsize_ = value;
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as RoomInfo);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(RoomInfo other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (Roomid != other.Roomid) return false;
    if (Maxsize != other.Maxsize) return false;
    if (Currentsize != other.Currentsize) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (Roomid != 0) hash ^= Roomid.GetHashCode();
    if (Maxsize != 0) hash ^= Maxsize.GetHashCode();
    if (Currentsize != 0) hash ^= Currentsize.GetHashCode();
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
    if (Roomid != 0) {
      output.WriteRawTag(8);
      output.WriteInt32(Roomid);
    }
    if (Maxsize != 0) {
      output.WriteRawTag(16);
      output.WriteInt32(Maxsize);
    }
    if (Currentsize != 0) {
      output.WriteRawTag(24);
      output.WriteInt32(Currentsize);
    }
    if (_unknownFields != null) {
      _unknownFields.WriteTo(output);
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int CalculateSize() {
    int size = 0;
    if (Roomid != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(Roomid);
    }
    if (Maxsize != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(Maxsize);
    }
    if (Currentsize != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(Currentsize);
    }
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(RoomInfo other) {
    if (other == null) {
      return;
    }
    if (other.Roomid != 0) {
      Roomid = other.Roomid;
    }
    if (other.Maxsize != 0) {
      Maxsize = other.Maxsize;
    }
    if (other.Currentsize != 0) {
      Currentsize = other.Currentsize;
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
          Roomid = input.ReadInt32();
          break;
        }
        case 16: {
          Maxsize = input.ReadInt32();
          break;
        }
        case 24: {
          Currentsize = input.ReadInt32();
          break;
        }
      }
    }
  }

}

public sealed partial class GetRoomListS2C : pb::IMessage<GetRoomListS2C> {
  private static readonly pb::MessageParser<GetRoomListS2C> _parser = new pb::MessageParser<GetRoomListS2C>(() => new GetRoomListS2C());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<GetRoomListS2C> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::GetRoomListS2CReflection.Descriptor.MessageTypes[1]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GetRoomListS2C() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GetRoomListS2C(GetRoomListS2C other) : this() {
    error_ = other.error_;
    roomsInfo_ = other.roomsInfo_.Clone();
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GetRoomListS2C Clone() {
    return new GetRoomListS2C(this);
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

  /// <summary>Field number for the "roomsInfo" field.</summary>
  public const int RoomsInfoFieldNumber = 2;
  private static readonly pb::FieldCodec<global::RoomInfo> _repeated_roomsInfo_codec
      = pb::FieldCodec.ForMessage(18, global::RoomInfo.Parser);
  private readonly pbc::RepeatedField<global::RoomInfo> roomsInfo_ = new pbc::RepeatedField<global::RoomInfo>();
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public pbc::RepeatedField<global::RoomInfo> RoomsInfo {
    get { return roomsInfo_; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as GetRoomListS2C);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(GetRoomListS2C other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (Error != other.Error) return false;
    if(!roomsInfo_.Equals(other.roomsInfo_)) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (Error != 0) hash ^= Error.GetHashCode();
    hash ^= roomsInfo_.GetHashCode();
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
    roomsInfo_.WriteTo(output, _repeated_roomsInfo_codec);
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
    size += roomsInfo_.CalculateSize(_repeated_roomsInfo_codec);
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(GetRoomListS2C other) {
    if (other == null) {
      return;
    }
    if (other.Error != 0) {
      Error = other.Error;
    }
    roomsInfo_.Add(other.roomsInfo_);
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
          roomsInfo_.AddEntriesFrom(input, _repeated_roomsInfo_codec);
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code

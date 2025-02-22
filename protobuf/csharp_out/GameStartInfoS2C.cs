// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: GameStartInfoS2C.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from GameStartInfoS2C.proto</summary>
public static partial class GameStartInfoS2CReflection {

  #region Descriptor
  /// <summary>File descriptor for GameStartInfoS2C.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static GameStartInfoS2CReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "ChZHYW1lU3RhcnRJbmZvUzJDLnByb3RvGhBQbGF5ZXJJbmZvLnByb3RvIncK",
          "EEdhbWVTdGFydEluZm9TMkMSDQoFZXJyb3IYASABKAUSDwoHc3VjY2VlZBgC",
          "IAEoCBIMCgRzZWVkGAMgASgFEhMKC2Zsb29yTnVtYmVyGAQgASgFEiAKC3Bs",
          "YXllcnNJbmZvGAUgAygLMgsuUGxheWVySW5mb2IGcHJvdG8z"));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { global::PlayerInfoReflection.Descriptor, },
        new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::GameStartInfoS2C), global::GameStartInfoS2C.Parser, new[]{ "Error", "Succeed", "Seed", "FloorNumber", "PlayersInfo" }, null, null, null)
        }));
  }
  #endregion

}
#region Messages
public sealed partial class GameStartInfoS2C : pb::IMessage<GameStartInfoS2C> {
  private static readonly pb::MessageParser<GameStartInfoS2C> _parser = new pb::MessageParser<GameStartInfoS2C>(() => new GameStartInfoS2C());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<GameStartInfoS2C> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::GameStartInfoS2CReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GameStartInfoS2C() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GameStartInfoS2C(GameStartInfoS2C other) : this() {
    error_ = other.error_;
    succeed_ = other.succeed_;
    seed_ = other.seed_;
    floorNumber_ = other.floorNumber_;
    playersInfo_ = other.playersInfo_.Clone();
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public GameStartInfoS2C Clone() {
    return new GameStartInfoS2C(this);
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

  /// <summary>Field number for the "seed" field.</summary>
  public const int SeedFieldNumber = 3;
  private int seed_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int Seed {
    get { return seed_; }
    set {
      seed_ = value;
    }
  }

  /// <summary>Field number for the "floorNumber" field.</summary>
  public const int FloorNumberFieldNumber = 4;
  private int floorNumber_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int FloorNumber {
    get { return floorNumber_; }
    set {
      floorNumber_ = value;
    }
  }

  /// <summary>Field number for the "playersInfo" field.</summary>
  public const int PlayersInfoFieldNumber = 5;
  private static readonly pb::FieldCodec<global::PlayerInfo> _repeated_playersInfo_codec
      = pb::FieldCodec.ForMessage(42, global::PlayerInfo.Parser);
  private readonly pbc::RepeatedField<global::PlayerInfo> playersInfo_ = new pbc::RepeatedField<global::PlayerInfo>();
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public pbc::RepeatedField<global::PlayerInfo> PlayersInfo {
    get { return playersInfo_; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as GameStartInfoS2C);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(GameStartInfoS2C other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (Error != other.Error) return false;
    if (Succeed != other.Succeed) return false;
    if (Seed != other.Seed) return false;
    if (FloorNumber != other.FloorNumber) return false;
    if(!playersInfo_.Equals(other.playersInfo_)) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (Error != 0) hash ^= Error.GetHashCode();
    if (Succeed != false) hash ^= Succeed.GetHashCode();
    if (Seed != 0) hash ^= Seed.GetHashCode();
    if (FloorNumber != 0) hash ^= FloorNumber.GetHashCode();
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
    if (Seed != 0) {
      output.WriteRawTag(24);
      output.WriteInt32(Seed);
    }
    if (FloorNumber != 0) {
      output.WriteRawTag(32);
      output.WriteInt32(FloorNumber);
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
    if (Seed != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(Seed);
    }
    if (FloorNumber != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(FloorNumber);
    }
    size += playersInfo_.CalculateSize(_repeated_playersInfo_codec);
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(GameStartInfoS2C other) {
    if (other == null) {
      return;
    }
    if (other.Error != 0) {
      Error = other.Error;
    }
    if (other.Succeed != false) {
      Succeed = other.Succeed;
    }
    if (other.Seed != 0) {
      Seed = other.Seed;
    }
    if (other.FloorNumber != 0) {
      FloorNumber = other.FloorNumber;
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
          Seed = input.ReadInt32();
          break;
        }
        case 32: {
          FloorNumber = input.ReadInt32();
          break;
        }
        case 42: {
          playersInfo_.AddEntriesFrom(input, _repeated_playersInfo_codec);
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code

// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: BattleFrame.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from BattleFrame.proto</summary>
public static partial class BattleFrameReflection {

  #region Descriptor
  /// <summary>File descriptor for BattleFrame.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static BattleFrameReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "ChFCYXR0bGVGcmFtZS5wcm90bxoRQmF0dGxlSW5wdXQucHJvdG8iaQoLQmF0",
          "dGxlRnJhbWUSDQoFZXJyb3IYASABKAUSEwoLZnJhbWVOdW1iZXIYAiABKAUS",
          "EgoKcmFuZG9tQ29kZRgDIAEoBRIiCgxiYXR0bGVJbnB1dHMYBCADKAsyDC5C",
          "YXR0bGVJbnB1dGIGcHJvdG8z"));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { global::BattleInputReflection.Descriptor, },
        new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::BattleFrame), global::BattleFrame.Parser, new[]{ "Error", "FrameNumber", "RandomCode", "BattleInputs" }, null, null, null)
        }));
  }
  #endregion

}
#region Messages
public sealed partial class BattleFrame : pb::IMessage<BattleFrame> {
  private static readonly pb::MessageParser<BattleFrame> _parser = new pb::MessageParser<BattleFrame>(() => new BattleFrame());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<BattleFrame> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::BattleFrameReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public BattleFrame() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public BattleFrame(BattleFrame other) : this() {
    error_ = other.error_;
    frameNumber_ = other.frameNumber_;
    randomCode_ = other.randomCode_;
    battleInputs_ = other.battleInputs_.Clone();
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public BattleFrame Clone() {
    return new BattleFrame(this);
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

  /// <summary>Field number for the "frameNumber" field.</summary>
  public const int FrameNumberFieldNumber = 2;
  private int frameNumber_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int FrameNumber {
    get { return frameNumber_; }
    set {
      frameNumber_ = value;
    }
  }

  /// <summary>Field number for the "randomCode" field.</summary>
  public const int RandomCodeFieldNumber = 3;
  private int randomCode_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int RandomCode {
    get { return randomCode_; }
    set {
      randomCode_ = value;
    }
  }

  /// <summary>Field number for the "battleInputs" field.</summary>
  public const int BattleInputsFieldNumber = 4;
  private static readonly pb::FieldCodec<global::BattleInput> _repeated_battleInputs_codec
      = pb::FieldCodec.ForMessage(34, global::BattleInput.Parser);
  private readonly pbc::RepeatedField<global::BattleInput> battleInputs_ = new pbc::RepeatedField<global::BattleInput>();
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public pbc::RepeatedField<global::BattleInput> BattleInputs {
    get { return battleInputs_; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as BattleFrame);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(BattleFrame other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (Error != other.Error) return false;
    if (FrameNumber != other.FrameNumber) return false;
    if (RandomCode != other.RandomCode) return false;
    if(!battleInputs_.Equals(other.battleInputs_)) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (Error != 0) hash ^= Error.GetHashCode();
    if (FrameNumber != 0) hash ^= FrameNumber.GetHashCode();
    if (RandomCode != 0) hash ^= RandomCode.GetHashCode();
    hash ^= battleInputs_.GetHashCode();
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
    if (FrameNumber != 0) {
      output.WriteRawTag(16);
      output.WriteInt32(FrameNumber);
    }
    if (RandomCode != 0) {
      output.WriteRawTag(24);
      output.WriteInt32(RandomCode);
    }
    battleInputs_.WriteTo(output, _repeated_battleInputs_codec);
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
    if (FrameNumber != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(FrameNumber);
    }
    if (RandomCode != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(RandomCode);
    }
    size += battleInputs_.CalculateSize(_repeated_battleInputs_codec);
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(BattleFrame other) {
    if (other == null) {
      return;
    }
    if (other.Error != 0) {
      Error = other.Error;
    }
    if (other.FrameNumber != 0) {
      FrameNumber = other.FrameNumber;
    }
    if (other.RandomCode != 0) {
      RandomCode = other.RandomCode;
    }
    battleInputs_.Add(other.battleInputs_);
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
          FrameNumber = input.ReadInt32();
          break;
        }
        case 24: {
          RandomCode = input.ReadInt32();
          break;
        }
        case 34: {
          battleInputs_.AddEntriesFrom(input, _repeated_battleInputs_codec);
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code

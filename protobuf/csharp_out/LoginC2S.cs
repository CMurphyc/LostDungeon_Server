// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: LoginC2S.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from LoginC2S.proto</summary>
public static partial class LoginC2SReflection {

  #region Descriptor
  /// <summary>File descriptor for LoginC2S.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static LoginC2SReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "Cg5Mb2dpbkMyUy5wcm90byIuCghMb2dpbkMyUxIQCgh1c2VyTmFtZRgBIAEo",
          "CRIQCghwYXNzd29yZBgCIAEoCWIGcHJvdG8z"));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { },
        new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::LoginC2S), global::LoginC2S.Parser, new[]{ "UserName", "Password" }, null, null, null)
        }));
  }
  #endregion

}
#region Messages
public sealed partial class LoginC2S : pb::IMessage<LoginC2S> {
  private static readonly pb::MessageParser<LoginC2S> _parser = new pb::MessageParser<LoginC2S>(() => new LoginC2S());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<LoginC2S> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::LoginC2SReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public LoginC2S() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public LoginC2S(LoginC2S other) : this() {
    userName_ = other.userName_;
    password_ = other.password_;
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public LoginC2S Clone() {
    return new LoginC2S(this);
  }

  /// <summary>Field number for the "userName" field.</summary>
  public const int UserNameFieldNumber = 1;
  private string userName_ = "";
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public string UserName {
    get { return userName_; }
    set {
      userName_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
    }
  }

  /// <summary>Field number for the "password" field.</summary>
  public const int PasswordFieldNumber = 2;
  private string password_ = "";
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public string Password {
    get { return password_; }
    set {
      password_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as LoginC2S);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(LoginC2S other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (UserName != other.UserName) return false;
    if (Password != other.Password) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (UserName.Length != 0) hash ^= UserName.GetHashCode();
    if (Password.Length != 0) hash ^= Password.GetHashCode();
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
    if (UserName.Length != 0) {
      output.WriteRawTag(10);
      output.WriteString(UserName);
    }
    if (Password.Length != 0) {
      output.WriteRawTag(18);
      output.WriteString(Password);
    }
    if (_unknownFields != null) {
      _unknownFields.WriteTo(output);
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int CalculateSize() {
    int size = 0;
    if (UserName.Length != 0) {
      size += 1 + pb::CodedOutputStream.ComputeStringSize(UserName);
    }
    if (Password.Length != 0) {
      size += 1 + pb::CodedOutputStream.ComputeStringSize(Password);
    }
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(LoginC2S other) {
    if (other == null) {
      return;
    }
    if (other.UserName.Length != 0) {
      UserName = other.UserName;
    }
    if (other.Password.Length != 0) {
      Password = other.Password;
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
        case 10: {
          UserName = input.ReadString();
          break;
        }
        case 18: {
          Password = input.ReadString();
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code

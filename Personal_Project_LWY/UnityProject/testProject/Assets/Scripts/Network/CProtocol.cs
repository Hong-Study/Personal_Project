// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: C#Protocol.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Google.Protobuf.Protocol {

  /// <summary>Holder for reflection information generated from C#Protocol.proto</summary>
  public static partial class CProtocolReflection {

    #region Descriptor
    /// <summary>File descriptor for C#Protocol.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static CProtocolReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "ChBDI1Byb3RvY29sLnByb3RvEghQcm90b2NvbBofZ29vZ2xlL3Byb3RvYnVm",
            "L3RpbWVzdGFtcC5wcm90byIwCgZTX1RFU1QSCgoCaWQYASABKAQSCgoCaHAY",
            "AiABKA0SDgoGYXR0YWNrGAMgASgNKh8KCFBrdF9UeXBlEgkKBUxPR0lOEAAS",
            "CAoEVEVTVBABQhuqAhhHb29nbGUuUHJvdG9idWYuUHJvdG9jb2xiBnByb3Rv",
            "Mw=="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Google.Protobuf.WellKnownTypes.TimestampReflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(new[] {typeof(global::Google.Protobuf.Protocol.Pkt_Type), }, null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Google.Protobuf.Protocol.S_TEST), global::Google.Protobuf.Protocol.S_TEST.Parser, new[]{ "Id", "Hp", "Attack" }, null, null, null, null)
          }));
    }
    #endregion

  }
  #region Enums
  public enum Pkt_Type {
    [pbr::OriginalName("LOGIN")] Login = 0,
    [pbr::OriginalName("TEST")] Test = 1,
  }

  #endregion

  #region Messages
  public sealed partial class S_TEST : pb::IMessage<S_TEST>
  #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      , pb::IBufferMessage
  #endif
  {
    private static readonly pb::MessageParser<S_TEST> _parser = new pb::MessageParser<S_TEST>(() => new S_TEST());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pb::MessageParser<S_TEST> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Google.Protobuf.Protocol.CProtocolReflection.Descriptor.MessageTypes[0]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public S_TEST() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public S_TEST(S_TEST other) : this() {
      id_ = other.id_;
      hp_ = other.hp_;
      attack_ = other.attack_;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public S_TEST Clone() {
      return new S_TEST(this);
    }

    /// <summary>Field number for the "id" field.</summary>
    public const int IdFieldNumber = 1;
    private ulong id_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public ulong Id {
      get { return id_; }
      set {
        id_ = value;
      }
    }

    /// <summary>Field number for the "hp" field.</summary>
    public const int HpFieldNumber = 2;
    private uint hp_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public uint Hp {
      get { return hp_; }
      set {
        hp_ = value;
      }
    }

    /// <summary>Field number for the "attack" field.</summary>
    public const int AttackFieldNumber = 3;
    private uint attack_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public uint Attack {
      get { return attack_; }
      set {
        attack_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override bool Equals(object other) {
      return Equals(other as S_TEST);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public bool Equals(S_TEST other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (Id != other.Id) return false;
      if (Hp != other.Hp) return false;
      if (Attack != other.Attack) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public override int GetHashCode() {
      int hash = 1;
      if (Id != 0UL) hash ^= Id.GetHashCode();
      if (Hp != 0) hash ^= Hp.GetHashCode();
      if (Attack != 0) hash ^= Attack.GetHashCode();
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
    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      output.WriteRawMessage(this);
    #else
      if (Id != 0UL) {
        output.WriteRawTag(8);
        output.WriteUInt64(Id);
      }
      if (Hp != 0) {
        output.WriteRawTag(16);
        output.WriteUInt32(Hp);
      }
      if (Attack != 0) {
        output.WriteRawTag(24);
        output.WriteUInt32(Attack);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    #endif
    }

    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    void pb::IBufferMessage.InternalWriteTo(ref pb::WriteContext output) {
      if (Id != 0UL) {
        output.WriteRawTag(8);
        output.WriteUInt64(Id);
      }
      if (Hp != 0) {
        output.WriteRawTag(16);
        output.WriteUInt32(Hp);
      }
      if (Attack != 0) {
        output.WriteRawTag(24);
        output.WriteUInt32(Attack);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(ref output);
      }
    }
    #endif

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public int CalculateSize() {
      int size = 0;
      if (Id != 0UL) {
        size += 1 + pb::CodedOutputStream.ComputeUInt64Size(Id);
      }
      if (Hp != 0) {
        size += 1 + pb::CodedOutputStream.ComputeUInt32Size(Hp);
      }
      if (Attack != 0) {
        size += 1 + pb::CodedOutputStream.ComputeUInt32Size(Attack);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(S_TEST other) {
      if (other == null) {
        return;
      }
      if (other.Id != 0UL) {
        Id = other.Id;
      }
      if (other.Hp != 0) {
        Hp = other.Hp;
      }
      if (other.Attack != 0) {
        Attack = other.Attack;
      }
      _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    public void MergeFrom(pb::CodedInputStream input) {
    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      input.ReadRawMessage(this);
    #else
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
            break;
          case 8: {
            Id = input.ReadUInt64();
            break;
          }
          case 16: {
            Hp = input.ReadUInt32();
            break;
          }
          case 24: {
            Attack = input.ReadUInt32();
            break;
          }
        }
      }
    #endif
    }

    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    void pb::IBufferMessage.InternalMergeFrom(ref pb::ParseContext input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, ref input);
            break;
          case 8: {
            Id = input.ReadUInt64();
            break;
          }
          case 16: {
            Hp = input.ReadUInt32();
            break;
          }
          case 24: {
            Attack = input.ReadUInt32();
            break;
          }
        }
      }
    }
    #endif

  }

  #endregion

}

#endregion Designer generated code

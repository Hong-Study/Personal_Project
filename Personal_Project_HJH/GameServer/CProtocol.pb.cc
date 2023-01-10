// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CProtocol.proto

#include "CProtocol.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Protocol {
constexpr S_DATA::S_DATA(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : plyaer_()
  , enemy_()
  , id_(0u)
  , map_level_(0u)
  , match_room_(0u){}
struct S_DATADefaultTypeInternal {
  constexpr S_DATADefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~S_DATADefaultTypeInternal() {}
  union {
    S_DATA _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT S_DATADefaultTypeInternal _S_DATA_default_instance_;
constexpr S_ENEMY::S_ENEMY(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : id_(0u)
  , x_(0)
  , y_(0)
  , z_(0){}
struct S_ENEMYDefaultTypeInternal {
  constexpr S_ENEMYDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~S_ENEMYDefaultTypeInternal() {}
  union {
    S_ENEMY _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT S_ENEMYDefaultTypeInternal _S_ENEMY_default_instance_;
constexpr S_PLYAER::S_PLYAER(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : x_(0)
  , y_(0)
  , z_(0){}
struct S_PLYAERDefaultTypeInternal {
  constexpr S_PLYAERDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~S_PLYAERDefaultTypeInternal() {}
  union {
    S_PLYAER _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT S_PLYAERDefaultTypeInternal _S_PLYAER_default_instance_;
}  // namespace Protocol
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_CProtocol_2eproto[3];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_CProtocol_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_CProtocol_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_CProtocol_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::S_DATA, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Protocol::S_DATA, id_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_DATA, map_level_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_DATA, match_room_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_DATA, plyaer_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_DATA, enemy_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::S_ENEMY, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Protocol::S_ENEMY, id_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_ENEMY, x_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_ENEMY, y_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_ENEMY, z_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::S_PLYAER, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Protocol::S_PLYAER, x_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_PLYAER, y_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_PLYAER, z_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Protocol::S_DATA)},
  { 10, -1, sizeof(::Protocol::S_ENEMY)},
  { 19, -1, sizeof(::Protocol::S_PLYAER)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_S_DATA_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_S_ENEMY_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_S_PLYAER_default_instance_),
};

const char descriptor_table_protodef_CProtocol_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017CProtocol.proto\022\010Protocol\"\201\001\n\006S_DATA\022\n"
  "\n\002id\030\001 \001(\r\022\021\n\tmap_level\030\002 \001(\r\022\022\n\nmatch_r"
  "oom\030\003 \001(\r\022\"\n\006plyaer\030\004 \003(\0132\022.Protocol.S_P"
  "LYAER\022 \n\005enemy\030\005 \003(\0132\021.Protocol.S_ENEMY\""
  "6\n\007S_ENEMY\022\n\n\002id\030\001 \001(\r\022\t\n\001x\030\002 \001(\002\022\t\n\001y\030\003"
  " \001(\002\022\t\n\001z\030\004 \001(\002\"+\n\010S_PLYAER\022\t\n\001x\030\002 \001(\002\022\t"
  "\n\001y\030\003 \001(\002\022\t\n\001z\030\004 \001(\002*\215\001\n\006INGAME\022\010\n\004MOVE\020"
  "\000\022\023\n\017CHARATERS_CRASH\020\001\022\022\n\016OBSTACLE_CRASH"
  "\020\002\022\013\n\007NO_MOVE\020\003\022\010\n\004DROP\020\004\022\013\n\007COMPLTE\020\005\022\010"
  "\n\004FAIL\020\006\022\017\n\013PACKET_FAIL\020\007\022\021\n\rOBSTACLE_MO"
  "VE\020\010b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_CProtocol_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_CProtocol_2eproto = {
  false, false, 412, descriptor_table_protodef_CProtocol_2eproto, "CProtocol.proto", 
  &descriptor_table_CProtocol_2eproto_once, nullptr, 0, 3,
  schemas, file_default_instances, TableStruct_CProtocol_2eproto::offsets,
  file_level_metadata_CProtocol_2eproto, file_level_enum_descriptors_CProtocol_2eproto, file_level_service_descriptors_CProtocol_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_CProtocol_2eproto_getter() {
  return &descriptor_table_CProtocol_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_CProtocol_2eproto(&descriptor_table_CProtocol_2eproto);
namespace Protocol {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* INGAME_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_CProtocol_2eproto);
  return file_level_enum_descriptors_CProtocol_2eproto[0];
}
bool INGAME_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class S_DATA::_Internal {
 public:
};

S_DATA::S_DATA(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  plyaer_(arena),
  enemy_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Protocol.S_DATA)
}
S_DATA::S_DATA(const S_DATA& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      plyaer_(from.plyaer_),
      enemy_(from.enemy_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&match_room_) -
    reinterpret_cast<char*>(&id_)) + sizeof(match_room_));
  // @@protoc_insertion_point(copy_constructor:Protocol.S_DATA)
}

void S_DATA::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&id_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&match_room_) -
    reinterpret_cast<char*>(&id_)) + sizeof(match_room_));
}

S_DATA::~S_DATA() {
  // @@protoc_insertion_point(destructor:Protocol.S_DATA)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void S_DATA::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void S_DATA::ArenaDtor(void* object) {
  S_DATA* _this = reinterpret_cast< S_DATA* >(object);
  (void)_this;
}
void S_DATA::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void S_DATA::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void S_DATA::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.S_DATA)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  plyaer_.Clear();
  enemy_.Clear();
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&match_room_) -
      reinterpret_cast<char*>(&id_)) + sizeof(match_room_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* S_DATA::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 map_level = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          map_level_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 match_room = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          match_room_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .Protocol.S_PLYAER plyaer = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_plyaer(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .Protocol.S_ENEMY enemy = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_enemy(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* S_DATA::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.S_DATA)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_id(), target);
  }

  // uint32 map_level = 2;
  if (this->map_level() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_map_level(), target);
  }

  // uint32 match_room = 3;
  if (this->match_room() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_match_room(), target);
  }

  // repeated .Protocol.S_PLYAER plyaer = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_plyaer_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_plyaer(i), target, stream);
  }

  // repeated .Protocol.S_ENEMY enemy = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_enemy_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, this->_internal_enemy(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.S_DATA)
  return target;
}

size_t S_DATA::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.S_DATA)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Protocol.S_PLYAER plyaer = 4;
  total_size += 1UL * this->_internal_plyaer_size();
  for (const auto& msg : this->plyaer_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .Protocol.S_ENEMY enemy = 5;
  total_size += 1UL * this->_internal_enemy_size();
  for (const auto& msg : this->enemy_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // uint32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());
  }

  // uint32 map_level = 2;
  if (this->map_level() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_map_level());
  }

  // uint32 match_room = 3;
  if (this->match_room() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_match_room());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void S_DATA::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Protocol.S_DATA)
  GOOGLE_DCHECK_NE(&from, this);
  const S_DATA* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<S_DATA>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Protocol.S_DATA)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Protocol.S_DATA)
    MergeFrom(*source);
  }
}

void S_DATA::MergeFrom(const S_DATA& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.S_DATA)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  plyaer_.MergeFrom(from.plyaer_);
  enemy_.MergeFrom(from.enemy_);
  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.map_level() != 0) {
    _internal_set_map_level(from._internal_map_level());
  }
  if (from.match_room() != 0) {
    _internal_set_match_room(from._internal_match_room());
  }
}

void S_DATA::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Protocol.S_DATA)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S_DATA::CopyFrom(const S_DATA& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.S_DATA)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S_DATA::IsInitialized() const {
  return true;
}

void S_DATA::InternalSwap(S_DATA* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  plyaer_.InternalSwap(&other->plyaer_);
  enemy_.InternalSwap(&other->enemy_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(S_DATA, match_room_)
      + sizeof(S_DATA::match_room_)
      - PROTOBUF_FIELD_OFFSET(S_DATA, id_)>(
          reinterpret_cast<char*>(&id_),
          reinterpret_cast<char*>(&other->id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata S_DATA::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_CProtocol_2eproto_getter, &descriptor_table_CProtocol_2eproto_once,
      file_level_metadata_CProtocol_2eproto[0]);
}

// ===================================================================

class S_ENEMY::_Internal {
 public:
};

S_ENEMY::S_ENEMY(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Protocol.S_ENEMY)
}
S_ENEMY::S_ENEMY(const S_ENEMY& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&id_)) + sizeof(z_));
  // @@protoc_insertion_point(copy_constructor:Protocol.S_ENEMY)
}

void S_ENEMY::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&id_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&id_)) + sizeof(z_));
}

S_ENEMY::~S_ENEMY() {
  // @@protoc_insertion_point(destructor:Protocol.S_ENEMY)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void S_ENEMY::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void S_ENEMY::ArenaDtor(void* object) {
  S_ENEMY* _this = reinterpret_cast< S_ENEMY* >(object);
  (void)_this;
}
void S_ENEMY::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void S_ENEMY::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void S_ENEMY::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.S_ENEMY)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&z_) -
      reinterpret_cast<char*>(&id_)) + sizeof(z_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* S_ENEMY::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float x = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float y = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float z = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 37)) {
          z_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* S_ENEMY::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.S_ENEMY)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_id(), target);
  }

  // float x = 2;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_x(), target);
  }

  // float y = 3;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_y(), target);
  }

  // float z = 4;
  if (!(this->z() <= 0 && this->z() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(4, this->_internal_z(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.S_ENEMY)
  return target;
}

size_t S_ENEMY::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.S_ENEMY)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());
  }

  // float x = 2;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    total_size += 1 + 4;
  }

  // float y = 3;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    total_size += 1 + 4;
  }

  // float z = 4;
  if (!(this->z() <= 0 && this->z() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void S_ENEMY::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Protocol.S_ENEMY)
  GOOGLE_DCHECK_NE(&from, this);
  const S_ENEMY* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<S_ENEMY>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Protocol.S_ENEMY)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Protocol.S_ENEMY)
    MergeFrom(*source);
  }
}

void S_ENEMY::MergeFrom(const S_ENEMY& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.S_ENEMY)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (!(from.x() <= 0 && from.x() >= 0)) {
    _internal_set_x(from._internal_x());
  }
  if (!(from.y() <= 0 && from.y() >= 0)) {
    _internal_set_y(from._internal_y());
  }
  if (!(from.z() <= 0 && from.z() >= 0)) {
    _internal_set_z(from._internal_z());
  }
}

void S_ENEMY::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Protocol.S_ENEMY)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S_ENEMY::CopyFrom(const S_ENEMY& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.S_ENEMY)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S_ENEMY::IsInitialized() const {
  return true;
}

void S_ENEMY::InternalSwap(S_ENEMY* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(S_ENEMY, z_)
      + sizeof(S_ENEMY::z_)
      - PROTOBUF_FIELD_OFFSET(S_ENEMY, id_)>(
          reinterpret_cast<char*>(&id_),
          reinterpret_cast<char*>(&other->id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata S_ENEMY::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_CProtocol_2eproto_getter, &descriptor_table_CProtocol_2eproto_once,
      file_level_metadata_CProtocol_2eproto[1]);
}

// ===================================================================

class S_PLYAER::_Internal {
 public:
};

S_PLYAER::S_PLYAER(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Protocol.S_PLYAER)
}
S_PLYAER::S_PLYAER(const S_PLYAER& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&x_, &from.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&x_)) + sizeof(z_));
  // @@protoc_insertion_point(copy_constructor:Protocol.S_PLYAER)
}

void S_PLYAER::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&x_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&x_)) + sizeof(z_));
}

S_PLYAER::~S_PLYAER() {
  // @@protoc_insertion_point(destructor:Protocol.S_PLYAER)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void S_PLYAER::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void S_PLYAER::ArenaDtor(void* object) {
  S_PLYAER* _this = reinterpret_cast< S_PLYAER* >(object);
  (void)_this;
}
void S_PLYAER::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void S_PLYAER::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void S_PLYAER::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.S_PLYAER)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&z_) -
      reinterpret_cast<char*>(&x_)) + sizeof(z_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* S_PLYAER::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // float x = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float y = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float z = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 37)) {
          z_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* S_PLYAER::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.S_PLYAER)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // float x = 2;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_x(), target);
  }

  // float y = 3;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_y(), target);
  }

  // float z = 4;
  if (!(this->z() <= 0 && this->z() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(4, this->_internal_z(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.S_PLYAER)
  return target;
}

size_t S_PLYAER::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.S_PLYAER)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float x = 2;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    total_size += 1 + 4;
  }

  // float y = 3;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    total_size += 1 + 4;
  }

  // float z = 4;
  if (!(this->z() <= 0 && this->z() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void S_PLYAER::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Protocol.S_PLYAER)
  GOOGLE_DCHECK_NE(&from, this);
  const S_PLYAER* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<S_PLYAER>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Protocol.S_PLYAER)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Protocol.S_PLYAER)
    MergeFrom(*source);
  }
}

void S_PLYAER::MergeFrom(const S_PLYAER& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.S_PLYAER)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.x() <= 0 && from.x() >= 0)) {
    _internal_set_x(from._internal_x());
  }
  if (!(from.y() <= 0 && from.y() >= 0)) {
    _internal_set_y(from._internal_y());
  }
  if (!(from.z() <= 0 && from.z() >= 0)) {
    _internal_set_z(from._internal_z());
  }
}

void S_PLYAER::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Protocol.S_PLYAER)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void S_PLYAER::CopyFrom(const S_PLYAER& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.S_PLYAER)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S_PLYAER::IsInitialized() const {
  return true;
}

void S_PLYAER::InternalSwap(S_PLYAER* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(S_PLYAER, z_)
      + sizeof(S_PLYAER::z_)
      - PROTOBUF_FIELD_OFFSET(S_PLYAER, x_)>(
          reinterpret_cast<char*>(&x_),
          reinterpret_cast<char*>(&other->x_));
}

::PROTOBUF_NAMESPACE_ID::Metadata S_PLYAER::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_CProtocol_2eproto_getter, &descriptor_table_CProtocol_2eproto_once,
      file_level_metadata_CProtocol_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::S_DATA* Arena::CreateMaybeMessage< ::Protocol::S_DATA >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::S_DATA >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::S_ENEMY* Arena::CreateMaybeMessage< ::Protocol::S_ENEMY >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::S_ENEMY >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::S_PLYAER* Arena::CreateMaybeMessage< ::Protocol::S_PLYAER >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::S_PLYAER >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

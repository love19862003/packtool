// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: monsterConfig.proto

#ifndef PROTOBUF_monsterConfig_2eproto__INCLUDED
#define PROTOBUF_monsterConfig_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "roleConfig.pb.h"
#include "ConfigTypeGroup.pb.h"
// @@protoc_insertion_point(includes)

namespace Pro {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_monsterConfig_2eproto();
void protobuf_InitDefaults_monsterConfig_2eproto();
void protobuf_AssignDesc_monsterConfig_2eproto();
void protobuf_ShutdownFile_monsterConfig_2eproto();

class monsterConfig;
class monsterConfig_ConfigTypeGroupmonstertype;

enum monsterConfig_monstertype {
  monsterConfig_monstertype_mini_monster = 1,
  monsterConfig_monstertype_middile_monster = 2,
  monsterConfig_monstertype_big_monter = 3
};
bool monsterConfig_monstertype_IsValid(int value);
const monsterConfig_monstertype monsterConfig_monstertype_monstertype_MIN = monsterConfig_monstertype_mini_monster;
const monsterConfig_monstertype monsterConfig_monstertype_monstertype_MAX = monsterConfig_monstertype_big_monter;
const int monsterConfig_monstertype_monstertype_ARRAYSIZE = monsterConfig_monstertype_monstertype_MAX + 1;

const ::google::protobuf::EnumDescriptor* monsterConfig_monstertype_descriptor();
inline const ::std::string& monsterConfig_monstertype_Name(monsterConfig_monstertype value) {
  return ::google::protobuf::internal::NameOfEnum(
    monsterConfig_monstertype_descriptor(), value);
}
inline bool monsterConfig_monstertype_Parse(
    const ::std::string& name, monsterConfig_monstertype* value) {
  return ::google::protobuf::internal::ParseNamedEnum<monsterConfig_monstertype>(
    monsterConfig_monstertype_descriptor(), name, value);
}
// ===================================================================

class monsterConfig_ConfigTypeGroupmonstertype : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.monsterConfig.ConfigTypeGroupmonstertype) */ {
 public:
  monsterConfig_ConfigTypeGroupmonstertype();
  virtual ~monsterConfig_ConfigTypeGroupmonstertype();

  monsterConfig_ConfigTypeGroupmonstertype(const monsterConfig_ConfigTypeGroupmonstertype& from);

  inline monsterConfig_ConfigTypeGroupmonstertype& operator=(const monsterConfig_ConfigTypeGroupmonstertype& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const monsterConfig_ConfigTypeGroupmonstertype& default_instance();

  static const monsterConfig_ConfigTypeGroupmonstertype* internal_default_instance();

  void Swap(monsterConfig_ConfigTypeGroupmonstertype* other);

  // implements Message ----------------------------------------------

  inline monsterConfig_ConfigTypeGroupmonstertype* New() const { return New(NULL); }

  monsterConfig_ConfigTypeGroupmonstertype* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const monsterConfig_ConfigTypeGroupmonstertype& from);
  void MergeFrom(const monsterConfig_ConfigTypeGroupmonstertype& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(monsterConfig_ConfigTypeGroupmonstertype* other);
  void UnsafeMergeFrom(const monsterConfig_ConfigTypeGroupmonstertype& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .Pro.monsterConfig.monstertype array = 1;
  int array_size() const;
  void clear_array();
  static const int kArrayFieldNumber = 1;
  ::Pro::monsterConfig_monstertype array(int index) const;
  void set_array(int index, ::Pro::monsterConfig_monstertype value);
  void add_array(::Pro::monsterConfig_monstertype value);
  const ::google::protobuf::RepeatedField<int>& array() const;
  ::google::protobuf::RepeatedField<int>* mutable_array();

  // @@protoc_insertion_point(class_scope:Pro.monsterConfig.ConfigTypeGroupmonstertype)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField<int> array_;
  friend void  protobuf_InitDefaults_monsterConfig_2eproto_impl();
  friend void  protobuf_AddDesc_monsterConfig_2eproto_impl();
  friend void protobuf_AssignDesc_monsterConfig_2eproto();
  friend void protobuf_ShutdownFile_monsterConfig_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<monsterConfig_ConfigTypeGroupmonstertype> monsterConfig_ConfigTypeGroupmonstertype_default_instance_;

// -------------------------------------------------------------------

class monsterConfig : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.monsterConfig) */ {
 public:
  monsterConfig();
  virtual ~monsterConfig();

  monsterConfig(const monsterConfig& from);

  inline monsterConfig& operator=(const monsterConfig& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const monsterConfig& default_instance();

  static const monsterConfig* internal_default_instance();

  void Swap(monsterConfig* other);

  // implements Message ----------------------------------------------

  inline monsterConfig* New() const { return New(NULL); }

  monsterConfig* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const monsterConfig& from);
  void MergeFrom(const monsterConfig& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(monsterConfig* other);
  void UnsafeMergeFrom(const monsterConfig& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef monsterConfig_ConfigTypeGroupmonstertype ConfigTypeGroupmonstertype;

  typedef monsterConfig_monstertype monstertype;
  static const monstertype mini_monster =
    monsterConfig_monstertype_mini_monster;
  static const monstertype middile_monster =
    monsterConfig_monstertype_middile_monster;
  static const monstertype big_monter =
    monsterConfig_monstertype_big_monter;
  static inline bool monstertype_IsValid(int value) {
    return monsterConfig_monstertype_IsValid(value);
  }
  static const monstertype monstertype_MIN =
    monsterConfig_monstertype_monstertype_MIN;
  static const monstertype monstertype_MAX =
    monsterConfig_monstertype_monstertype_MAX;
  static const int monstertype_ARRAYSIZE =
    monsterConfig_monstertype_monstertype_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  monstertype_descriptor() {
    return monsterConfig_monstertype_descriptor();
  }
  static inline const ::std::string& monstertype_Name(monstertype value) {
    return monsterConfig_monstertype_Name(value);
  }
  static inline bool monstertype_Parse(const ::std::string& name,
      monstertype* value) {
    return monsterConfig_monstertype_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional string id = 1;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  const ::std::string& id() const;
  void set_id(const ::std::string& value);
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  ::std::string* mutable_id();
  ::std::string* release_id();
  void set_allocated_id(::std::string* id);

  // repeated .Pro.ConfigTypeGroupfloat group_float = 2;
  int group_float_size() const;
  void clear_group_float();
  static const int kGroupFloatFieldNumber = 2;
  const ::Pro::ConfigTypeGroupfloat& group_float(int index) const;
  ::Pro::ConfigTypeGroupfloat* mutable_group_float(int index);
  ::Pro::ConfigTypeGroupfloat* add_group_float();
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupfloat >*
      mutable_group_float();
  const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupfloat >&
      group_float() const;

  // repeated .Pro.ConfigTypeGroupstring group_string = 3;
  int group_string_size() const;
  void clear_group_string();
  static const int kGroupStringFieldNumber = 3;
  const ::Pro::ConfigTypeGroupstring& group_string(int index) const;
  ::Pro::ConfigTypeGroupstring* mutable_group_string(int index);
  ::Pro::ConfigTypeGroupstring* add_group_string();
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupstring >*
      mutable_group_string();
  const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupstring >&
      group_string() const;

  // optional .Pro.roleConfig.jobtype job = 4;
  bool has_job() const;
  void clear_job();
  static const int kJobFieldNumber = 4;
  ::Pro::roleConfig_jobtype job() const;
  void set_job(::Pro::roleConfig_jobtype value);

  // optional int32 level = 5;
  bool has_level() const;
  void clear_level();
  static const int kLevelFieldNumber = 5;
  ::google::protobuf::int32 level() const;
  void set_level(::google::protobuf::int32 value);

  // optional int32 sub = 6;
  bool has_sub() const;
  void clear_sub();
  static const int kSubFieldNumber = 6;
  ::google::protobuf::int32 sub() const;
  void set_sub(::google::protobuf::int32 value);

  // optional .Pro.ProCoordinate c1 = 7;
  bool has_c1() const;
  void clear_c1();
  static const int kC1FieldNumber = 7;
  const ::Pro::ProCoordinate& c1() const;
  ::Pro::ProCoordinate* mutable_c1();
  ::Pro::ProCoordinate* release_c1();
  void set_allocated_c1(::Pro::ProCoordinate* c1);

  // repeated .Pro.ProCoordinate c2 = 8;
  int c2_size() const;
  void clear_c2();
  static const int kC2FieldNumber = 8;
  const ::Pro::ProCoordinate& c2(int index) const;
  ::Pro::ProCoordinate* mutable_c2(int index);
  ::Pro::ProCoordinate* add_c2();
  ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate >*
      mutable_c2();
  const ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate >&
      c2() const;

  // repeated .Pro.ConfigTypeGroupProCoordinate c3 = 9;
  int c3_size() const;
  void clear_c3();
  static const int kC3FieldNumber = 9;
  const ::Pro::ConfigTypeGroupProCoordinate& c3(int index) const;
  ::Pro::ConfigTypeGroupProCoordinate* mutable_c3(int index);
  ::Pro::ConfigTypeGroupProCoordinate* add_c3();
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupProCoordinate >*
      mutable_c3();
  const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupProCoordinate >&
      c3() const;

  // @@protoc_insertion_point(class_scope:Pro.monsterConfig)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_job();
  inline void clear_has_job();
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_sub();
  inline void clear_has_sub();
  inline void set_has_c1();
  inline void clear_has_c1();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupfloat > group_float_;
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupstring > group_string_;
  ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate > c2_;
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupProCoordinate > c3_;
  ::google::protobuf::internal::ArenaStringPtr id_;
  ::Pro::ProCoordinate* c1_;
  int job_;
  ::google::protobuf::int32 level_;
  ::google::protobuf::int32 sub_;
  friend void  protobuf_InitDefaults_monsterConfig_2eproto_impl();
  friend void  protobuf_AddDesc_monsterConfig_2eproto_impl();
  friend void protobuf_AssignDesc_monsterConfig_2eproto();
  friend void protobuf_ShutdownFile_monsterConfig_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<monsterConfig> monsterConfig_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// monsterConfig_ConfigTypeGroupmonstertype

// repeated .Pro.monsterConfig.monstertype array = 1;
inline int monsterConfig_ConfigTypeGroupmonstertype::array_size() const {
  return array_.size();
}
inline void monsterConfig_ConfigTypeGroupmonstertype::clear_array() {
  array_.Clear();
}
inline ::Pro::monsterConfig_monstertype monsterConfig_ConfigTypeGroupmonstertype::array(int index) const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.ConfigTypeGroupmonstertype.array)
  return static_cast< ::Pro::monsterConfig_monstertype >(array_.Get(index));
}
inline void monsterConfig_ConfigTypeGroupmonstertype::set_array(int index, ::Pro::monsterConfig_monstertype value) {
  assert(::Pro::monsterConfig_monstertype_IsValid(value));
  array_.Set(index, value);
  // @@protoc_insertion_point(field_set:Pro.monsterConfig.ConfigTypeGroupmonstertype.array)
}
inline void monsterConfig_ConfigTypeGroupmonstertype::add_array(::Pro::monsterConfig_monstertype value) {
  assert(::Pro::monsterConfig_monstertype_IsValid(value));
  array_.Add(value);
  // @@protoc_insertion_point(field_add:Pro.monsterConfig.ConfigTypeGroupmonstertype.array)
}
inline const ::google::protobuf::RepeatedField<int>&
monsterConfig_ConfigTypeGroupmonstertype::array() const {
  // @@protoc_insertion_point(field_list:Pro.monsterConfig.ConfigTypeGroupmonstertype.array)
  return array_;
}
inline ::google::protobuf::RepeatedField<int>*
monsterConfig_ConfigTypeGroupmonstertype::mutable_array() {
  // @@protoc_insertion_point(field_mutable_list:Pro.monsterConfig.ConfigTypeGroupmonstertype.array)
  return &array_;
}

inline const monsterConfig_ConfigTypeGroupmonstertype* monsterConfig_ConfigTypeGroupmonstertype::internal_default_instance() {
  return &monsterConfig_ConfigTypeGroupmonstertype_default_instance_.get();
}
// -------------------------------------------------------------------

// monsterConfig

// optional string id = 1;
inline bool monsterConfig::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void monsterConfig::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void monsterConfig::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void monsterConfig::clear_id() {
  id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_id();
}
inline const ::std::string& monsterConfig::id() const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.id)
  return id_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void monsterConfig::set_id(const ::std::string& value) {
  set_has_id();
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Pro.monsterConfig.id)
}
inline void monsterConfig::set_id(const char* value) {
  set_has_id();
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Pro.monsterConfig.id)
}
inline void monsterConfig::set_id(const char* value, size_t size) {
  set_has_id();
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Pro.monsterConfig.id)
}
inline ::std::string* monsterConfig::mutable_id() {
  set_has_id();
  // @@protoc_insertion_point(field_mutable:Pro.monsterConfig.id)
  return id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* monsterConfig::release_id() {
  // @@protoc_insertion_point(field_release:Pro.monsterConfig.id)
  clear_has_id();
  return id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void monsterConfig::set_allocated_id(::std::string* id) {
  if (id != NULL) {
    set_has_id();
  } else {
    clear_has_id();
  }
  id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), id);
  // @@protoc_insertion_point(field_set_allocated:Pro.monsterConfig.id)
}

// repeated .Pro.ConfigTypeGroupfloat group_float = 2;
inline int monsterConfig::group_float_size() const {
  return group_float_.size();
}
inline void monsterConfig::clear_group_float() {
  group_float_.Clear();
}
inline const ::Pro::ConfigTypeGroupfloat& monsterConfig::group_float(int index) const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.group_float)
  return group_float_.Get(index);
}
inline ::Pro::ConfigTypeGroupfloat* monsterConfig::mutable_group_float(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.monsterConfig.group_float)
  return group_float_.Mutable(index);
}
inline ::Pro::ConfigTypeGroupfloat* monsterConfig::add_group_float() {
  // @@protoc_insertion_point(field_add:Pro.monsterConfig.group_float)
  return group_float_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupfloat >*
monsterConfig::mutable_group_float() {
  // @@protoc_insertion_point(field_mutable_list:Pro.monsterConfig.group_float)
  return &group_float_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupfloat >&
monsterConfig::group_float() const {
  // @@protoc_insertion_point(field_list:Pro.monsterConfig.group_float)
  return group_float_;
}

// repeated .Pro.ConfigTypeGroupstring group_string = 3;
inline int monsterConfig::group_string_size() const {
  return group_string_.size();
}
inline void monsterConfig::clear_group_string() {
  group_string_.Clear();
}
inline const ::Pro::ConfigTypeGroupstring& monsterConfig::group_string(int index) const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.group_string)
  return group_string_.Get(index);
}
inline ::Pro::ConfigTypeGroupstring* monsterConfig::mutable_group_string(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.monsterConfig.group_string)
  return group_string_.Mutable(index);
}
inline ::Pro::ConfigTypeGroupstring* monsterConfig::add_group_string() {
  // @@protoc_insertion_point(field_add:Pro.monsterConfig.group_string)
  return group_string_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupstring >*
monsterConfig::mutable_group_string() {
  // @@protoc_insertion_point(field_mutable_list:Pro.monsterConfig.group_string)
  return &group_string_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupstring >&
monsterConfig::group_string() const {
  // @@protoc_insertion_point(field_list:Pro.monsterConfig.group_string)
  return group_string_;
}

// optional .Pro.roleConfig.jobtype job = 4;
inline bool monsterConfig::has_job() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void monsterConfig::set_has_job() {
  _has_bits_[0] |= 0x00000008u;
}
inline void monsterConfig::clear_has_job() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void monsterConfig::clear_job() {
  job_ = 0;
  clear_has_job();
}
inline ::Pro::roleConfig_jobtype monsterConfig::job() const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.job)
  return static_cast< ::Pro::roleConfig_jobtype >(job_);
}
inline void monsterConfig::set_job(::Pro::roleConfig_jobtype value) {
  assert(::Pro::roleConfig_jobtype_IsValid(value));
  set_has_job();
  job_ = value;
  // @@protoc_insertion_point(field_set:Pro.monsterConfig.job)
}

// optional int32 level = 5;
inline bool monsterConfig::has_level() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void monsterConfig::set_has_level() {
  _has_bits_[0] |= 0x00000010u;
}
inline void monsterConfig::clear_has_level() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void monsterConfig::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 monsterConfig::level() const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.level)
  return level_;
}
inline void monsterConfig::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
  // @@protoc_insertion_point(field_set:Pro.monsterConfig.level)
}

// optional int32 sub = 6;
inline bool monsterConfig::has_sub() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void monsterConfig::set_has_sub() {
  _has_bits_[0] |= 0x00000020u;
}
inline void monsterConfig::clear_has_sub() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void monsterConfig::clear_sub() {
  sub_ = 0;
  clear_has_sub();
}
inline ::google::protobuf::int32 monsterConfig::sub() const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.sub)
  return sub_;
}
inline void monsterConfig::set_sub(::google::protobuf::int32 value) {
  set_has_sub();
  sub_ = value;
  // @@protoc_insertion_point(field_set:Pro.monsterConfig.sub)
}

// optional .Pro.ProCoordinate c1 = 7;
inline bool monsterConfig::has_c1() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void monsterConfig::set_has_c1() {
  _has_bits_[0] |= 0x00000040u;
}
inline void monsterConfig::clear_has_c1() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void monsterConfig::clear_c1() {
  if (c1_ != NULL) c1_->::Pro::ProCoordinate::Clear();
  clear_has_c1();
}
inline const ::Pro::ProCoordinate& monsterConfig::c1() const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.c1)
  return c1_ != NULL ? *c1_
                         : *::Pro::ProCoordinate::internal_default_instance();
}
inline ::Pro::ProCoordinate* monsterConfig::mutable_c1() {
  set_has_c1();
  if (c1_ == NULL) {
    c1_ = new ::Pro::ProCoordinate;
  }
  // @@protoc_insertion_point(field_mutable:Pro.monsterConfig.c1)
  return c1_;
}
inline ::Pro::ProCoordinate* monsterConfig::release_c1() {
  // @@protoc_insertion_point(field_release:Pro.monsterConfig.c1)
  clear_has_c1();
  ::Pro::ProCoordinate* temp = c1_;
  c1_ = NULL;
  return temp;
}
inline void monsterConfig::set_allocated_c1(::Pro::ProCoordinate* c1) {
  delete c1_;
  c1_ = c1;
  if (c1) {
    set_has_c1();
  } else {
    clear_has_c1();
  }
  // @@protoc_insertion_point(field_set_allocated:Pro.monsterConfig.c1)
}

// repeated .Pro.ProCoordinate c2 = 8;
inline int monsterConfig::c2_size() const {
  return c2_.size();
}
inline void monsterConfig::clear_c2() {
  c2_.Clear();
}
inline const ::Pro::ProCoordinate& monsterConfig::c2(int index) const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.c2)
  return c2_.Get(index);
}
inline ::Pro::ProCoordinate* monsterConfig::mutable_c2(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.monsterConfig.c2)
  return c2_.Mutable(index);
}
inline ::Pro::ProCoordinate* monsterConfig::add_c2() {
  // @@protoc_insertion_point(field_add:Pro.monsterConfig.c2)
  return c2_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate >*
monsterConfig::mutable_c2() {
  // @@protoc_insertion_point(field_mutable_list:Pro.monsterConfig.c2)
  return &c2_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate >&
monsterConfig::c2() const {
  // @@protoc_insertion_point(field_list:Pro.monsterConfig.c2)
  return c2_;
}

// repeated .Pro.ConfigTypeGroupProCoordinate c3 = 9;
inline int monsterConfig::c3_size() const {
  return c3_.size();
}
inline void monsterConfig::clear_c3() {
  c3_.Clear();
}
inline const ::Pro::ConfigTypeGroupProCoordinate& monsterConfig::c3(int index) const {
  // @@protoc_insertion_point(field_get:Pro.monsterConfig.c3)
  return c3_.Get(index);
}
inline ::Pro::ConfigTypeGroupProCoordinate* monsterConfig::mutable_c3(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.monsterConfig.c3)
  return c3_.Mutable(index);
}
inline ::Pro::ConfigTypeGroupProCoordinate* monsterConfig::add_c3() {
  // @@protoc_insertion_point(field_add:Pro.monsterConfig.c3)
  return c3_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupProCoordinate >*
monsterConfig::mutable_c3() {
  // @@protoc_insertion_point(field_mutable_list:Pro.monsterConfig.c3)
  return &c3_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupProCoordinate >&
monsterConfig::c3() const {
  // @@protoc_insertion_point(field_list:Pro.monsterConfig.c3)
  return c3_;
}

inline const monsterConfig* monsterConfig::internal_default_instance() {
  return &monsterConfig_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Pro

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Pro::monsterConfig_monstertype> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Pro::monsterConfig_monstertype>() {
  return ::Pro::monsterConfig_monstertype_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_monsterConfig_2eproto__INCLUDED

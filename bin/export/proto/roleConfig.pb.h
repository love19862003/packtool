// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: roleConfig.proto

#ifndef PROTOBUF_roleConfig_2eproto__INCLUDED
#define PROTOBUF_roleConfig_2eproto__INCLUDED

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
#include "EnumDefineConfig.pb.h"
#include "ConfigTypeGroup.pb.h"
// @@protoc_insertion_point(includes)

namespace Pro {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_roleConfig_2eproto();
void protobuf_InitDefaults_roleConfig_2eproto();
void protobuf_AssignDesc_roleConfig_2eproto();
void protobuf_ShutdownFile_roleConfig_2eproto();

class roleConfig;
class roleConfig_ConfigTypeGroupjobtype;

enum roleConfig_jobtype {
  roleConfig_jobtype_common_0 = 0,
  roleConfig_jobtype_novice_1 = 1,
  roleConfig_jobtype_swordman_2 = 2,
  roleConfig_jobtype_businessman_3 = 3,
  roleConfig_jobtype_archer_4 = 4,
  roleConfig_jobtype_master_5 = 5,
  roleConfig_jobtype_serve_6 = 6,
  roleConfig_jobtype_robbers_7 = 7
};
bool roleConfig_jobtype_IsValid(int value);
const roleConfig_jobtype roleConfig_jobtype_jobtype_MIN = roleConfig_jobtype_common_0;
const roleConfig_jobtype roleConfig_jobtype_jobtype_MAX = roleConfig_jobtype_robbers_7;
const int roleConfig_jobtype_jobtype_ARRAYSIZE = roleConfig_jobtype_jobtype_MAX + 1;

const ::google::protobuf::EnumDescriptor* roleConfig_jobtype_descriptor();
inline const ::std::string& roleConfig_jobtype_Name(roleConfig_jobtype value) {
  return ::google::protobuf::internal::NameOfEnum(
    roleConfig_jobtype_descriptor(), value);
}
inline bool roleConfig_jobtype_Parse(
    const ::std::string& name, roleConfig_jobtype* value) {
  return ::google::protobuf::internal::ParseNamedEnum<roleConfig_jobtype>(
    roleConfig_jobtype_descriptor(), name, value);
}
// ===================================================================

class roleConfig_ConfigTypeGroupjobtype : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.roleConfig.ConfigTypeGroupjobtype) */ {
 public:
  roleConfig_ConfigTypeGroupjobtype();
  virtual ~roleConfig_ConfigTypeGroupjobtype();

  roleConfig_ConfigTypeGroupjobtype(const roleConfig_ConfigTypeGroupjobtype& from);

  inline roleConfig_ConfigTypeGroupjobtype& operator=(const roleConfig_ConfigTypeGroupjobtype& from) {
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
  static const roleConfig_ConfigTypeGroupjobtype& default_instance();

  static const roleConfig_ConfigTypeGroupjobtype* internal_default_instance();

  void Swap(roleConfig_ConfigTypeGroupjobtype* other);

  // implements Message ----------------------------------------------

  inline roleConfig_ConfigTypeGroupjobtype* New() const { return New(NULL); }

  roleConfig_ConfigTypeGroupjobtype* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const roleConfig_ConfigTypeGroupjobtype& from);
  void MergeFrom(const roleConfig_ConfigTypeGroupjobtype& from);
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
  void InternalSwap(roleConfig_ConfigTypeGroupjobtype* other);
  void UnsafeMergeFrom(const roleConfig_ConfigTypeGroupjobtype& from);
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

  // repeated .Pro.roleConfig.jobtype array = 1;
  int array_size() const;
  void clear_array();
  static const int kArrayFieldNumber = 1;
  ::Pro::roleConfig_jobtype array(int index) const;
  void set_array(int index, ::Pro::roleConfig_jobtype value);
  void add_array(::Pro::roleConfig_jobtype value);
  const ::google::protobuf::RepeatedField<int>& array() const;
  ::google::protobuf::RepeatedField<int>* mutable_array();

  // @@protoc_insertion_point(class_scope:Pro.roleConfig.ConfigTypeGroupjobtype)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField<int> array_;
  friend void  protobuf_InitDefaults_roleConfig_2eproto_impl();
  friend void  protobuf_AddDesc_roleConfig_2eproto_impl();
  friend void protobuf_AssignDesc_roleConfig_2eproto();
  friend void protobuf_ShutdownFile_roleConfig_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<roleConfig_ConfigTypeGroupjobtype> roleConfig_ConfigTypeGroupjobtype_default_instance_;

// -------------------------------------------------------------------

class roleConfig : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.roleConfig) */ {
 public:
  roleConfig();
  virtual ~roleConfig();

  roleConfig(const roleConfig& from);

  inline roleConfig& operator=(const roleConfig& from) {
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
  static const roleConfig& default_instance();

  static const roleConfig* internal_default_instance();

  void Swap(roleConfig* other);

  // implements Message ----------------------------------------------

  inline roleConfig* New() const { return New(NULL); }

  roleConfig* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const roleConfig& from);
  void MergeFrom(const roleConfig& from);
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
  void InternalSwap(roleConfig* other);
  void UnsafeMergeFrom(const roleConfig& from);
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

  typedef roleConfig_ConfigTypeGroupjobtype ConfigTypeGroupjobtype;

  typedef roleConfig_jobtype jobtype;
  static const jobtype common_0 =
    roleConfig_jobtype_common_0;
  static const jobtype novice_1 =
    roleConfig_jobtype_novice_1;
  static const jobtype swordman_2 =
    roleConfig_jobtype_swordman_2;
  static const jobtype businessman_3 =
    roleConfig_jobtype_businessman_3;
  static const jobtype archer_4 =
    roleConfig_jobtype_archer_4;
  static const jobtype master_5 =
    roleConfig_jobtype_master_5;
  static const jobtype serve_6 =
    roleConfig_jobtype_serve_6;
  static const jobtype robbers_7 =
    roleConfig_jobtype_robbers_7;
  static inline bool jobtype_IsValid(int value) {
    return roleConfig_jobtype_IsValid(value);
  }
  static const jobtype jobtype_MIN =
    roleConfig_jobtype_jobtype_MIN;
  static const jobtype jobtype_MAX =
    roleConfig_jobtype_jobtype_MAX;
  static const int jobtype_ARRAYSIZE =
    roleConfig_jobtype_jobtype_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  jobtype_descriptor() {
    return roleConfig_jobtype_descriptor();
  }
  static inline const ::std::string& jobtype_Name(jobtype value) {
    return roleConfig_jobtype_Name(value);
  }
  static inline bool jobtype_Parse(const ::std::string& name,
      jobtype* value) {
    return roleConfig_jobtype_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional int32 id = 1;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

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

  // optional .Pro.camptype camp = 4;
  bool has_camp() const;
  void clear_camp();
  static const int kCampFieldNumber = 4;
  ::Pro::camptype camp() const;
  void set_camp(::Pro::camptype value);

  // repeated .Pro.camptype camp_array = 5;
  int camp_array_size() const;
  void clear_camp_array();
  static const int kCampArrayFieldNumber = 5;
  ::Pro::camptype camp_array(int index) const;
  void set_camp_array(int index, ::Pro::camptype value);
  void add_camp_array(::Pro::camptype value);
  const ::google::protobuf::RepeatedField<int>& camp_array() const;
  ::google::protobuf::RepeatedField<int>* mutable_camp_array();

  // repeated .Pro.ConfigTypeGroupcamptype camp_group = 6;
  int camp_group_size() const;
  void clear_camp_group();
  static const int kCampGroupFieldNumber = 6;
  const ::Pro::ConfigTypeGroupcamptype& camp_group(int index) const;
  ::Pro::ConfigTypeGroupcamptype* mutable_camp_group(int index);
  ::Pro::ConfigTypeGroupcamptype* add_camp_group();
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupcamptype >*
      mutable_camp_group();
  const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupcamptype >&
      camp_group() const;

  // repeated .Pro.roleConfig.jobtype job = 7;
  int job_size() const;
  void clear_job();
  static const int kJobFieldNumber = 7;
  ::Pro::roleConfig_jobtype job(int index) const;
  void set_job(int index, ::Pro::roleConfig_jobtype value);
  void add_job(::Pro::roleConfig_jobtype value);
  const ::google::protobuf::RepeatedField<int>& job() const;
  ::google::protobuf::RepeatedField<int>* mutable_job();

  // repeated .Pro.roleConfig.ConfigTypeGroupjobtype job2 = 8;
  int job2_size() const;
  void clear_job2();
  static const int kJob2FieldNumber = 8;
  const ::Pro::roleConfig_ConfigTypeGroupjobtype& job2(int index) const;
  ::Pro::roleConfig_ConfigTypeGroupjobtype* mutable_job2(int index);
  ::Pro::roleConfig_ConfigTypeGroupjobtype* add_job2();
  ::google::protobuf::RepeatedPtrField< ::Pro::roleConfig_ConfigTypeGroupjobtype >*
      mutable_job2();
  const ::google::protobuf::RepeatedPtrField< ::Pro::roleConfig_ConfigTypeGroupjobtype >&
      job2() const;

  // @@protoc_insertion_point(class_scope:Pro.roleConfig)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_camp();
  inline void clear_has_camp();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupfloat > group_float_;
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupstring > group_string_;
  ::google::protobuf::RepeatedField<int> camp_array_;
  ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupcamptype > camp_group_;
  ::google::protobuf::RepeatedField<int> job_;
  ::google::protobuf::RepeatedPtrField< ::Pro::roleConfig_ConfigTypeGroupjobtype > job2_;
  ::google::protobuf::int32 id_;
  int camp_;
  friend void  protobuf_InitDefaults_roleConfig_2eproto_impl();
  friend void  protobuf_AddDesc_roleConfig_2eproto_impl();
  friend void protobuf_AssignDesc_roleConfig_2eproto();
  friend void protobuf_ShutdownFile_roleConfig_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<roleConfig> roleConfig_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// roleConfig_ConfigTypeGroupjobtype

// repeated .Pro.roleConfig.jobtype array = 1;
inline int roleConfig_ConfigTypeGroupjobtype::array_size() const {
  return array_.size();
}
inline void roleConfig_ConfigTypeGroupjobtype::clear_array() {
  array_.Clear();
}
inline ::Pro::roleConfig_jobtype roleConfig_ConfigTypeGroupjobtype::array(int index) const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.ConfigTypeGroupjobtype.array)
  return static_cast< ::Pro::roleConfig_jobtype >(array_.Get(index));
}
inline void roleConfig_ConfigTypeGroupjobtype::set_array(int index, ::Pro::roleConfig_jobtype value) {
  assert(::Pro::roleConfig_jobtype_IsValid(value));
  array_.Set(index, value);
  // @@protoc_insertion_point(field_set:Pro.roleConfig.ConfigTypeGroupjobtype.array)
}
inline void roleConfig_ConfigTypeGroupjobtype::add_array(::Pro::roleConfig_jobtype value) {
  assert(::Pro::roleConfig_jobtype_IsValid(value));
  array_.Add(value);
  // @@protoc_insertion_point(field_add:Pro.roleConfig.ConfigTypeGroupjobtype.array)
}
inline const ::google::protobuf::RepeatedField<int>&
roleConfig_ConfigTypeGroupjobtype::array() const {
  // @@protoc_insertion_point(field_list:Pro.roleConfig.ConfigTypeGroupjobtype.array)
  return array_;
}
inline ::google::protobuf::RepeatedField<int>*
roleConfig_ConfigTypeGroupjobtype::mutable_array() {
  // @@protoc_insertion_point(field_mutable_list:Pro.roleConfig.ConfigTypeGroupjobtype.array)
  return &array_;
}

inline const roleConfig_ConfigTypeGroupjobtype* roleConfig_ConfigTypeGroupjobtype::internal_default_instance() {
  return &roleConfig_ConfigTypeGroupjobtype_default_instance_.get();
}
// -------------------------------------------------------------------

// roleConfig

// optional int32 id = 1;
inline bool roleConfig::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void roleConfig::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void roleConfig::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void roleConfig::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 roleConfig::id() const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.id)
  return id_;
}
inline void roleConfig::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:Pro.roleConfig.id)
}

// repeated .Pro.ConfigTypeGroupfloat group_float = 2;
inline int roleConfig::group_float_size() const {
  return group_float_.size();
}
inline void roleConfig::clear_group_float() {
  group_float_.Clear();
}
inline const ::Pro::ConfigTypeGroupfloat& roleConfig::group_float(int index) const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.group_float)
  return group_float_.Get(index);
}
inline ::Pro::ConfigTypeGroupfloat* roleConfig::mutable_group_float(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.roleConfig.group_float)
  return group_float_.Mutable(index);
}
inline ::Pro::ConfigTypeGroupfloat* roleConfig::add_group_float() {
  // @@protoc_insertion_point(field_add:Pro.roleConfig.group_float)
  return group_float_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupfloat >*
roleConfig::mutable_group_float() {
  // @@protoc_insertion_point(field_mutable_list:Pro.roleConfig.group_float)
  return &group_float_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupfloat >&
roleConfig::group_float() const {
  // @@protoc_insertion_point(field_list:Pro.roleConfig.group_float)
  return group_float_;
}

// repeated .Pro.ConfigTypeGroupstring group_string = 3;
inline int roleConfig::group_string_size() const {
  return group_string_.size();
}
inline void roleConfig::clear_group_string() {
  group_string_.Clear();
}
inline const ::Pro::ConfigTypeGroupstring& roleConfig::group_string(int index) const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.group_string)
  return group_string_.Get(index);
}
inline ::Pro::ConfigTypeGroupstring* roleConfig::mutable_group_string(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.roleConfig.group_string)
  return group_string_.Mutable(index);
}
inline ::Pro::ConfigTypeGroupstring* roleConfig::add_group_string() {
  // @@protoc_insertion_point(field_add:Pro.roleConfig.group_string)
  return group_string_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupstring >*
roleConfig::mutable_group_string() {
  // @@protoc_insertion_point(field_mutable_list:Pro.roleConfig.group_string)
  return &group_string_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupstring >&
roleConfig::group_string() const {
  // @@protoc_insertion_point(field_list:Pro.roleConfig.group_string)
  return group_string_;
}

// optional .Pro.camptype camp = 4;
inline bool roleConfig::has_camp() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void roleConfig::set_has_camp() {
  _has_bits_[0] |= 0x00000008u;
}
inline void roleConfig::clear_has_camp() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void roleConfig::clear_camp() {
  camp_ = 1;
  clear_has_camp();
}
inline ::Pro::camptype roleConfig::camp() const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.camp)
  return static_cast< ::Pro::camptype >(camp_);
}
inline void roleConfig::set_camp(::Pro::camptype value) {
  assert(::Pro::camptype_IsValid(value));
  set_has_camp();
  camp_ = value;
  // @@protoc_insertion_point(field_set:Pro.roleConfig.camp)
}

// repeated .Pro.camptype camp_array = 5;
inline int roleConfig::camp_array_size() const {
  return camp_array_.size();
}
inline void roleConfig::clear_camp_array() {
  camp_array_.Clear();
}
inline ::Pro::camptype roleConfig::camp_array(int index) const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.camp_array)
  return static_cast< ::Pro::camptype >(camp_array_.Get(index));
}
inline void roleConfig::set_camp_array(int index, ::Pro::camptype value) {
  assert(::Pro::camptype_IsValid(value));
  camp_array_.Set(index, value);
  // @@protoc_insertion_point(field_set:Pro.roleConfig.camp_array)
}
inline void roleConfig::add_camp_array(::Pro::camptype value) {
  assert(::Pro::camptype_IsValid(value));
  camp_array_.Add(value);
  // @@protoc_insertion_point(field_add:Pro.roleConfig.camp_array)
}
inline const ::google::protobuf::RepeatedField<int>&
roleConfig::camp_array() const {
  // @@protoc_insertion_point(field_list:Pro.roleConfig.camp_array)
  return camp_array_;
}
inline ::google::protobuf::RepeatedField<int>*
roleConfig::mutable_camp_array() {
  // @@protoc_insertion_point(field_mutable_list:Pro.roleConfig.camp_array)
  return &camp_array_;
}

// repeated .Pro.ConfigTypeGroupcamptype camp_group = 6;
inline int roleConfig::camp_group_size() const {
  return camp_group_.size();
}
inline void roleConfig::clear_camp_group() {
  camp_group_.Clear();
}
inline const ::Pro::ConfigTypeGroupcamptype& roleConfig::camp_group(int index) const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.camp_group)
  return camp_group_.Get(index);
}
inline ::Pro::ConfigTypeGroupcamptype* roleConfig::mutable_camp_group(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.roleConfig.camp_group)
  return camp_group_.Mutable(index);
}
inline ::Pro::ConfigTypeGroupcamptype* roleConfig::add_camp_group() {
  // @@protoc_insertion_point(field_add:Pro.roleConfig.camp_group)
  return camp_group_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupcamptype >*
roleConfig::mutable_camp_group() {
  // @@protoc_insertion_point(field_mutable_list:Pro.roleConfig.camp_group)
  return &camp_group_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::ConfigTypeGroupcamptype >&
roleConfig::camp_group() const {
  // @@protoc_insertion_point(field_list:Pro.roleConfig.camp_group)
  return camp_group_;
}

// repeated .Pro.roleConfig.jobtype job = 7;
inline int roleConfig::job_size() const {
  return job_.size();
}
inline void roleConfig::clear_job() {
  job_.Clear();
}
inline ::Pro::roleConfig_jobtype roleConfig::job(int index) const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.job)
  return static_cast< ::Pro::roleConfig_jobtype >(job_.Get(index));
}
inline void roleConfig::set_job(int index, ::Pro::roleConfig_jobtype value) {
  assert(::Pro::roleConfig_jobtype_IsValid(value));
  job_.Set(index, value);
  // @@protoc_insertion_point(field_set:Pro.roleConfig.job)
}
inline void roleConfig::add_job(::Pro::roleConfig_jobtype value) {
  assert(::Pro::roleConfig_jobtype_IsValid(value));
  job_.Add(value);
  // @@protoc_insertion_point(field_add:Pro.roleConfig.job)
}
inline const ::google::protobuf::RepeatedField<int>&
roleConfig::job() const {
  // @@protoc_insertion_point(field_list:Pro.roleConfig.job)
  return job_;
}
inline ::google::protobuf::RepeatedField<int>*
roleConfig::mutable_job() {
  // @@protoc_insertion_point(field_mutable_list:Pro.roleConfig.job)
  return &job_;
}

// repeated .Pro.roleConfig.ConfigTypeGroupjobtype job2 = 8;
inline int roleConfig::job2_size() const {
  return job2_.size();
}
inline void roleConfig::clear_job2() {
  job2_.Clear();
}
inline const ::Pro::roleConfig_ConfigTypeGroupjobtype& roleConfig::job2(int index) const {
  // @@protoc_insertion_point(field_get:Pro.roleConfig.job2)
  return job2_.Get(index);
}
inline ::Pro::roleConfig_ConfigTypeGroupjobtype* roleConfig::mutable_job2(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.roleConfig.job2)
  return job2_.Mutable(index);
}
inline ::Pro::roleConfig_ConfigTypeGroupjobtype* roleConfig::add_job2() {
  // @@protoc_insertion_point(field_add:Pro.roleConfig.job2)
  return job2_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::roleConfig_ConfigTypeGroupjobtype >*
roleConfig::mutable_job2() {
  // @@protoc_insertion_point(field_mutable_list:Pro.roleConfig.job2)
  return &job2_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::roleConfig_ConfigTypeGroupjobtype >&
roleConfig::job2() const {
  // @@protoc_insertion_point(field_list:Pro.roleConfig.job2)
  return job2_;
}

inline const roleConfig* roleConfig::internal_default_instance() {
  return &roleConfig_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Pro

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Pro::roleConfig_jobtype> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Pro::roleConfig_jobtype>() {
  return ::Pro::roleConfig_jobtype_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_roleConfig_2eproto__INCLUDED

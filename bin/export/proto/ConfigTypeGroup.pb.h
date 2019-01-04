// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ConfigTypeGroup.proto

#ifndef PROTOBUF_ConfigTypeGroup_2eproto__INCLUDED
#define PROTOBUF_ConfigTypeGroup_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Pro {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_ConfigTypeGroup_2eproto();
void protobuf_InitDefaults_ConfigTypeGroup_2eproto();
void protobuf_AssignDesc_ConfigTypeGroup_2eproto();
void protobuf_ShutdownFile_ConfigTypeGroup_2eproto();

class ConfigTypeGroupProCoordinate;
class ConfigTypeGroupbool;
class ConfigTypeGroupfloat;
class ConfigTypeGroupint32;
class ConfigTypeGroupstring;
class ProCoordinate;

// ===================================================================

class ProCoordinate : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.ProCoordinate) */ {
 public:
  ProCoordinate();
  virtual ~ProCoordinate();

  ProCoordinate(const ProCoordinate& from);

  inline ProCoordinate& operator=(const ProCoordinate& from) {
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
  static const ProCoordinate& default_instance();

  static const ProCoordinate* internal_default_instance();

  void Swap(ProCoordinate* other);

  // implements Message ----------------------------------------------

  inline ProCoordinate* New() const { return New(NULL); }

  ProCoordinate* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ProCoordinate& from);
  void MergeFrom(const ProCoordinate& from);
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
  void InternalSwap(ProCoordinate* other);
  void UnsafeMergeFrom(const ProCoordinate& from);
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

  // optional float x = 1;
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 1;
  float x() const;
  void set_x(float value);

  // optional float y = 2;
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 2;
  float y() const;
  void set_y(float value);

  // optional float z = 3;
  bool has_z() const;
  void clear_z();
  static const int kZFieldNumber = 3;
  float z() const;
  void set_z(float value);

  // optional float o = 4;
  bool has_o() const;
  void clear_o();
  static const int kOFieldNumber = 4;
  float o() const;
  void set_o(float value);

  // @@protoc_insertion_point(class_scope:Pro.ProCoordinate)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_z();
  inline void clear_has_z();
  inline void set_has_o();
  inline void clear_has_o();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  float x_;
  float y_;
  float z_;
  float o_;
  friend void  protobuf_InitDefaults_ConfigTypeGroup_2eproto_impl();
  friend void  protobuf_AddDesc_ConfigTypeGroup_2eproto_impl();
  friend void protobuf_AssignDesc_ConfigTypeGroup_2eproto();
  friend void protobuf_ShutdownFile_ConfigTypeGroup_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ProCoordinate> ProCoordinate_default_instance_;

// -------------------------------------------------------------------

class ConfigTypeGroupProCoordinate : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.ConfigTypeGroupProCoordinate) */ {
 public:
  ConfigTypeGroupProCoordinate();
  virtual ~ConfigTypeGroupProCoordinate();

  ConfigTypeGroupProCoordinate(const ConfigTypeGroupProCoordinate& from);

  inline ConfigTypeGroupProCoordinate& operator=(const ConfigTypeGroupProCoordinate& from) {
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
  static const ConfigTypeGroupProCoordinate& default_instance();

  static const ConfigTypeGroupProCoordinate* internal_default_instance();

  void Swap(ConfigTypeGroupProCoordinate* other);

  // implements Message ----------------------------------------------

  inline ConfigTypeGroupProCoordinate* New() const { return New(NULL); }

  ConfigTypeGroupProCoordinate* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConfigTypeGroupProCoordinate& from);
  void MergeFrom(const ConfigTypeGroupProCoordinate& from);
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
  void InternalSwap(ConfigTypeGroupProCoordinate* other);
  void UnsafeMergeFrom(const ConfigTypeGroupProCoordinate& from);
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

  // repeated .Pro.ProCoordinate array = 1;
  int array_size() const;
  void clear_array();
  static const int kArrayFieldNumber = 1;
  const ::Pro::ProCoordinate& array(int index) const;
  ::Pro::ProCoordinate* mutable_array(int index);
  ::Pro::ProCoordinate* add_array();
  ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate >*
      mutable_array();
  const ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate >&
      array() const;

  // @@protoc_insertion_point(class_scope:Pro.ConfigTypeGroupProCoordinate)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate > array_;
  friend void  protobuf_InitDefaults_ConfigTypeGroup_2eproto_impl();
  friend void  protobuf_AddDesc_ConfigTypeGroup_2eproto_impl();
  friend void protobuf_AssignDesc_ConfigTypeGroup_2eproto();
  friend void protobuf_ShutdownFile_ConfigTypeGroup_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ConfigTypeGroupProCoordinate> ConfigTypeGroupProCoordinate_default_instance_;

// -------------------------------------------------------------------

class ConfigTypeGroupbool : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.ConfigTypeGroupbool) */ {
 public:
  ConfigTypeGroupbool();
  virtual ~ConfigTypeGroupbool();

  ConfigTypeGroupbool(const ConfigTypeGroupbool& from);

  inline ConfigTypeGroupbool& operator=(const ConfigTypeGroupbool& from) {
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
  static const ConfigTypeGroupbool& default_instance();

  static const ConfigTypeGroupbool* internal_default_instance();

  void Swap(ConfigTypeGroupbool* other);

  // implements Message ----------------------------------------------

  inline ConfigTypeGroupbool* New() const { return New(NULL); }

  ConfigTypeGroupbool* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConfigTypeGroupbool& from);
  void MergeFrom(const ConfigTypeGroupbool& from);
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
  void InternalSwap(ConfigTypeGroupbool* other);
  void UnsafeMergeFrom(const ConfigTypeGroupbool& from);
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

  // repeated bool array = 1;
  int array_size() const;
  void clear_array();
  static const int kArrayFieldNumber = 1;
  bool array(int index) const;
  void set_array(int index, bool value);
  void add_array(bool value);
  const ::google::protobuf::RepeatedField< bool >&
      array() const;
  ::google::protobuf::RepeatedField< bool >*
      mutable_array();

  // @@protoc_insertion_point(class_scope:Pro.ConfigTypeGroupbool)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< bool > array_;
  friend void  protobuf_InitDefaults_ConfigTypeGroup_2eproto_impl();
  friend void  protobuf_AddDesc_ConfigTypeGroup_2eproto_impl();
  friend void protobuf_AssignDesc_ConfigTypeGroup_2eproto();
  friend void protobuf_ShutdownFile_ConfigTypeGroup_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ConfigTypeGroupbool> ConfigTypeGroupbool_default_instance_;

// -------------------------------------------------------------------

class ConfigTypeGroupint32 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.ConfigTypeGroupint32) */ {
 public:
  ConfigTypeGroupint32();
  virtual ~ConfigTypeGroupint32();

  ConfigTypeGroupint32(const ConfigTypeGroupint32& from);

  inline ConfigTypeGroupint32& operator=(const ConfigTypeGroupint32& from) {
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
  static const ConfigTypeGroupint32& default_instance();

  static const ConfigTypeGroupint32* internal_default_instance();

  void Swap(ConfigTypeGroupint32* other);

  // implements Message ----------------------------------------------

  inline ConfigTypeGroupint32* New() const { return New(NULL); }

  ConfigTypeGroupint32* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConfigTypeGroupint32& from);
  void MergeFrom(const ConfigTypeGroupint32& from);
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
  void InternalSwap(ConfigTypeGroupint32* other);
  void UnsafeMergeFrom(const ConfigTypeGroupint32& from);
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

  // repeated int32 array = 1;
  int array_size() const;
  void clear_array();
  static const int kArrayFieldNumber = 1;
  ::google::protobuf::int32 array(int index) const;
  void set_array(int index, ::google::protobuf::int32 value);
  void add_array(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      array() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_array();

  // @@protoc_insertion_point(class_scope:Pro.ConfigTypeGroupint32)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > array_;
  friend void  protobuf_InitDefaults_ConfigTypeGroup_2eproto_impl();
  friend void  protobuf_AddDesc_ConfigTypeGroup_2eproto_impl();
  friend void protobuf_AssignDesc_ConfigTypeGroup_2eproto();
  friend void protobuf_ShutdownFile_ConfigTypeGroup_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ConfigTypeGroupint32> ConfigTypeGroupint32_default_instance_;

// -------------------------------------------------------------------

class ConfigTypeGroupstring : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.ConfigTypeGroupstring) */ {
 public:
  ConfigTypeGroupstring();
  virtual ~ConfigTypeGroupstring();

  ConfigTypeGroupstring(const ConfigTypeGroupstring& from);

  inline ConfigTypeGroupstring& operator=(const ConfigTypeGroupstring& from) {
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
  static const ConfigTypeGroupstring& default_instance();

  static const ConfigTypeGroupstring* internal_default_instance();

  void Swap(ConfigTypeGroupstring* other);

  // implements Message ----------------------------------------------

  inline ConfigTypeGroupstring* New() const { return New(NULL); }

  ConfigTypeGroupstring* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConfigTypeGroupstring& from);
  void MergeFrom(const ConfigTypeGroupstring& from);
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
  void InternalSwap(ConfigTypeGroupstring* other);
  void UnsafeMergeFrom(const ConfigTypeGroupstring& from);
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

  // repeated string array = 1;
  int array_size() const;
  void clear_array();
  static const int kArrayFieldNumber = 1;
  const ::std::string& array(int index) const;
  ::std::string* mutable_array(int index);
  void set_array(int index, const ::std::string& value);
  void set_array(int index, const char* value);
  void set_array(int index, const char* value, size_t size);
  ::std::string* add_array();
  void add_array(const ::std::string& value);
  void add_array(const char* value);
  void add_array(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& array() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_array();

  // @@protoc_insertion_point(class_scope:Pro.ConfigTypeGroupstring)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> array_;
  friend void  protobuf_InitDefaults_ConfigTypeGroup_2eproto_impl();
  friend void  protobuf_AddDesc_ConfigTypeGroup_2eproto_impl();
  friend void protobuf_AssignDesc_ConfigTypeGroup_2eproto();
  friend void protobuf_ShutdownFile_ConfigTypeGroup_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ConfigTypeGroupstring> ConfigTypeGroupstring_default_instance_;

// -------------------------------------------------------------------

class ConfigTypeGroupfloat : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pro.ConfigTypeGroupfloat) */ {
 public:
  ConfigTypeGroupfloat();
  virtual ~ConfigTypeGroupfloat();

  ConfigTypeGroupfloat(const ConfigTypeGroupfloat& from);

  inline ConfigTypeGroupfloat& operator=(const ConfigTypeGroupfloat& from) {
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
  static const ConfigTypeGroupfloat& default_instance();

  static const ConfigTypeGroupfloat* internal_default_instance();

  void Swap(ConfigTypeGroupfloat* other);

  // implements Message ----------------------------------------------

  inline ConfigTypeGroupfloat* New() const { return New(NULL); }

  ConfigTypeGroupfloat* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConfigTypeGroupfloat& from);
  void MergeFrom(const ConfigTypeGroupfloat& from);
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
  void InternalSwap(ConfigTypeGroupfloat* other);
  void UnsafeMergeFrom(const ConfigTypeGroupfloat& from);
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

  // repeated float array = 1;
  int array_size() const;
  void clear_array();
  static const int kArrayFieldNumber = 1;
  float array(int index) const;
  void set_array(int index, float value);
  void add_array(float value);
  const ::google::protobuf::RepeatedField< float >&
      array() const;
  ::google::protobuf::RepeatedField< float >*
      mutable_array();

  // @@protoc_insertion_point(class_scope:Pro.ConfigTypeGroupfloat)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< float > array_;
  friend void  protobuf_InitDefaults_ConfigTypeGroup_2eproto_impl();
  friend void  protobuf_AddDesc_ConfigTypeGroup_2eproto_impl();
  friend void protobuf_AssignDesc_ConfigTypeGroup_2eproto();
  friend void protobuf_ShutdownFile_ConfigTypeGroup_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ConfigTypeGroupfloat> ConfigTypeGroupfloat_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ProCoordinate

// optional float x = 1;
inline bool ProCoordinate::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ProCoordinate::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ProCoordinate::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ProCoordinate::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float ProCoordinate::x() const {
  // @@protoc_insertion_point(field_get:Pro.ProCoordinate.x)
  return x_;
}
inline void ProCoordinate::set_x(float value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:Pro.ProCoordinate.x)
}

// optional float y = 2;
inline bool ProCoordinate::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ProCoordinate::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ProCoordinate::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ProCoordinate::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float ProCoordinate::y() const {
  // @@protoc_insertion_point(field_get:Pro.ProCoordinate.y)
  return y_;
}
inline void ProCoordinate::set_y(float value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:Pro.ProCoordinate.y)
}

// optional float z = 3;
inline bool ProCoordinate::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ProCoordinate::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ProCoordinate::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ProCoordinate::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline float ProCoordinate::z() const {
  // @@protoc_insertion_point(field_get:Pro.ProCoordinate.z)
  return z_;
}
inline void ProCoordinate::set_z(float value) {
  set_has_z();
  z_ = value;
  // @@protoc_insertion_point(field_set:Pro.ProCoordinate.z)
}

// optional float o = 4;
inline bool ProCoordinate::has_o() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ProCoordinate::set_has_o() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ProCoordinate::clear_has_o() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ProCoordinate::clear_o() {
  o_ = 0;
  clear_has_o();
}
inline float ProCoordinate::o() const {
  // @@protoc_insertion_point(field_get:Pro.ProCoordinate.o)
  return o_;
}
inline void ProCoordinate::set_o(float value) {
  set_has_o();
  o_ = value;
  // @@protoc_insertion_point(field_set:Pro.ProCoordinate.o)
}

inline const ProCoordinate* ProCoordinate::internal_default_instance() {
  return &ProCoordinate_default_instance_.get();
}
// -------------------------------------------------------------------

// ConfigTypeGroupProCoordinate

// repeated .Pro.ProCoordinate array = 1;
inline int ConfigTypeGroupProCoordinate::array_size() const {
  return array_.size();
}
inline void ConfigTypeGroupProCoordinate::clear_array() {
  array_.Clear();
}
inline const ::Pro::ProCoordinate& ConfigTypeGroupProCoordinate::array(int index) const {
  // @@protoc_insertion_point(field_get:Pro.ConfigTypeGroupProCoordinate.array)
  return array_.Get(index);
}
inline ::Pro::ProCoordinate* ConfigTypeGroupProCoordinate::mutable_array(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.ConfigTypeGroupProCoordinate.array)
  return array_.Mutable(index);
}
inline ::Pro::ProCoordinate* ConfigTypeGroupProCoordinate::add_array() {
  // @@protoc_insertion_point(field_add:Pro.ConfigTypeGroupProCoordinate.array)
  return array_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate >*
ConfigTypeGroupProCoordinate::mutable_array() {
  // @@protoc_insertion_point(field_mutable_list:Pro.ConfigTypeGroupProCoordinate.array)
  return &array_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Pro::ProCoordinate >&
ConfigTypeGroupProCoordinate::array() const {
  // @@protoc_insertion_point(field_list:Pro.ConfigTypeGroupProCoordinate.array)
  return array_;
}

inline const ConfigTypeGroupProCoordinate* ConfigTypeGroupProCoordinate::internal_default_instance() {
  return &ConfigTypeGroupProCoordinate_default_instance_.get();
}
// -------------------------------------------------------------------

// ConfigTypeGroupbool

// repeated bool array = 1;
inline int ConfigTypeGroupbool::array_size() const {
  return array_.size();
}
inline void ConfigTypeGroupbool::clear_array() {
  array_.Clear();
}
inline bool ConfigTypeGroupbool::array(int index) const {
  // @@protoc_insertion_point(field_get:Pro.ConfigTypeGroupbool.array)
  return array_.Get(index);
}
inline void ConfigTypeGroupbool::set_array(int index, bool value) {
  array_.Set(index, value);
  // @@protoc_insertion_point(field_set:Pro.ConfigTypeGroupbool.array)
}
inline void ConfigTypeGroupbool::add_array(bool value) {
  array_.Add(value);
  // @@protoc_insertion_point(field_add:Pro.ConfigTypeGroupbool.array)
}
inline const ::google::protobuf::RepeatedField< bool >&
ConfigTypeGroupbool::array() const {
  // @@protoc_insertion_point(field_list:Pro.ConfigTypeGroupbool.array)
  return array_;
}
inline ::google::protobuf::RepeatedField< bool >*
ConfigTypeGroupbool::mutable_array() {
  // @@protoc_insertion_point(field_mutable_list:Pro.ConfigTypeGroupbool.array)
  return &array_;
}

inline const ConfigTypeGroupbool* ConfigTypeGroupbool::internal_default_instance() {
  return &ConfigTypeGroupbool_default_instance_.get();
}
// -------------------------------------------------------------------

// ConfigTypeGroupint32

// repeated int32 array = 1;
inline int ConfigTypeGroupint32::array_size() const {
  return array_.size();
}
inline void ConfigTypeGroupint32::clear_array() {
  array_.Clear();
}
inline ::google::protobuf::int32 ConfigTypeGroupint32::array(int index) const {
  // @@protoc_insertion_point(field_get:Pro.ConfigTypeGroupint32.array)
  return array_.Get(index);
}
inline void ConfigTypeGroupint32::set_array(int index, ::google::protobuf::int32 value) {
  array_.Set(index, value);
  // @@protoc_insertion_point(field_set:Pro.ConfigTypeGroupint32.array)
}
inline void ConfigTypeGroupint32::add_array(::google::protobuf::int32 value) {
  array_.Add(value);
  // @@protoc_insertion_point(field_add:Pro.ConfigTypeGroupint32.array)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
ConfigTypeGroupint32::array() const {
  // @@protoc_insertion_point(field_list:Pro.ConfigTypeGroupint32.array)
  return array_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
ConfigTypeGroupint32::mutable_array() {
  // @@protoc_insertion_point(field_mutable_list:Pro.ConfigTypeGroupint32.array)
  return &array_;
}

inline const ConfigTypeGroupint32* ConfigTypeGroupint32::internal_default_instance() {
  return &ConfigTypeGroupint32_default_instance_.get();
}
// -------------------------------------------------------------------

// ConfigTypeGroupstring

// repeated string array = 1;
inline int ConfigTypeGroupstring::array_size() const {
  return array_.size();
}
inline void ConfigTypeGroupstring::clear_array() {
  array_.Clear();
}
inline const ::std::string& ConfigTypeGroupstring::array(int index) const {
  // @@protoc_insertion_point(field_get:Pro.ConfigTypeGroupstring.array)
  return array_.Get(index);
}
inline ::std::string* ConfigTypeGroupstring::mutable_array(int index) {
  // @@protoc_insertion_point(field_mutable:Pro.ConfigTypeGroupstring.array)
  return array_.Mutable(index);
}
inline void ConfigTypeGroupstring::set_array(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:Pro.ConfigTypeGroupstring.array)
  array_.Mutable(index)->assign(value);
}
inline void ConfigTypeGroupstring::set_array(int index, const char* value) {
  array_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:Pro.ConfigTypeGroupstring.array)
}
inline void ConfigTypeGroupstring::set_array(int index, const char* value, size_t size) {
  array_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Pro.ConfigTypeGroupstring.array)
}
inline ::std::string* ConfigTypeGroupstring::add_array() {
  // @@protoc_insertion_point(field_add_mutable:Pro.ConfigTypeGroupstring.array)
  return array_.Add();
}
inline void ConfigTypeGroupstring::add_array(const ::std::string& value) {
  array_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:Pro.ConfigTypeGroupstring.array)
}
inline void ConfigTypeGroupstring::add_array(const char* value) {
  array_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:Pro.ConfigTypeGroupstring.array)
}
inline void ConfigTypeGroupstring::add_array(const char* value, size_t size) {
  array_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:Pro.ConfigTypeGroupstring.array)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
ConfigTypeGroupstring::array() const {
  // @@protoc_insertion_point(field_list:Pro.ConfigTypeGroupstring.array)
  return array_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
ConfigTypeGroupstring::mutable_array() {
  // @@protoc_insertion_point(field_mutable_list:Pro.ConfigTypeGroupstring.array)
  return &array_;
}

inline const ConfigTypeGroupstring* ConfigTypeGroupstring::internal_default_instance() {
  return &ConfigTypeGroupstring_default_instance_.get();
}
// -------------------------------------------------------------------

// ConfigTypeGroupfloat

// repeated float array = 1;
inline int ConfigTypeGroupfloat::array_size() const {
  return array_.size();
}
inline void ConfigTypeGroupfloat::clear_array() {
  array_.Clear();
}
inline float ConfigTypeGroupfloat::array(int index) const {
  // @@protoc_insertion_point(field_get:Pro.ConfigTypeGroupfloat.array)
  return array_.Get(index);
}
inline void ConfigTypeGroupfloat::set_array(int index, float value) {
  array_.Set(index, value);
  // @@protoc_insertion_point(field_set:Pro.ConfigTypeGroupfloat.array)
}
inline void ConfigTypeGroupfloat::add_array(float value) {
  array_.Add(value);
  // @@protoc_insertion_point(field_add:Pro.ConfigTypeGroupfloat.array)
}
inline const ::google::protobuf::RepeatedField< float >&
ConfigTypeGroupfloat::array() const {
  // @@protoc_insertion_point(field_list:Pro.ConfigTypeGroupfloat.array)
  return array_;
}
inline ::google::protobuf::RepeatedField< float >*
ConfigTypeGroupfloat::mutable_array() {
  // @@protoc_insertion_point(field_mutable_list:Pro.ConfigTypeGroupfloat.array)
  return &array_;
}

inline const ConfigTypeGroupfloat* ConfigTypeGroupfloat::internal_default_instance() {
  return &ConfigTypeGroupfloat_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Pro

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ConfigTypeGroup_2eproto__INCLUDED

/************************************************
 * \file table.h
 * \date 2018/12/26 10:58
 *
 * \author wufan
 * Contact: love19862003@163.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*************************************************/
#pragma once
#include <set>
#include <string>
#include <variant>
#include "MapTemplate.h"
namespace ToolSpace{

  struct THead{
    int basic_type;
    int muti_type;
    int index;
    int column;
    std::string comment;
    std::string table;
    std::string name;
    std::string type_name;       //int, array<int>, group<int>
    std::string type_basic_name; //int int int
  };

  struct TEnumValue{
    std::string name;
    int value;
    std::string comment;
  };

  struct TEnum{
    std::string full_name;
    std::string table;
    std::string name;
    ObjectMap<std::string, TEnumValue> values;
  };

  struct TLink{
    std::string link;
    std::vector<std::string> heads;
  };

  typedef std::string  BasicValueType;
  typedef std::vector<BasicValueType> ArrayValueType;
  typedef std::vector<ArrayValueType> GroupValueType;
  typedef std::variant<BasicValueType, ArrayValueType, GroupValueType> TValueType;
  typedef std::string RecordIndexType;

  struct TField{
    RecordIndexType record_index;
    std::string field_value_str;
    TValueType  field_value;
  };

  struct TRecord{
    RecordIndexType record_index;
    ObjectMap<int, TField> fields;
  };

  struct THeadLayout {
    std::string head_name;
    int head_index;
    std::string type_name;
  };

  struct TTableLayout{
    std::string table;
    int key_index;
    int next_index;
    ObjectMap<std::string, THeadLayout> layouts;
  };

  typedef std::shared_ptr<TTableLayout> LayoutPtr;
  typedef ObjPtrMap<std::string, TRecord> RecordMap;
  typedef RecordMap::value_type RecordPtr;
  typedef ObjPtrMap<std::string, TLink> LinkMap;
  typedef LinkMap::value_type LinkPtr;
  typedef ObjPtrMap<int, THead> HeadMap;
  typedef HeadMap::value_type HeadPtr;

  class Table
  {
  public:
    explicit Table(const LayoutPtr& layout);
    virtual ~Table();

    inline const std::string& tableName() const{ return m_tableName; }
    inline const std::set<std::string>& dependTable() const{ return m_dependTable; }
    inline void depentTable(const std::string&tableName){ m_dependTable.insert(tableName); }

    bool addHead(const HeadPtr& ptr);
    bool addRecord(const RecordPtr& ptr);
    bool hadRecord(const RecordIndexType& index) const;
    bool addLink(const LinkPtr& ptr);

    HeadPtr getHead(int index) const;
    HeadPtr getColumnHead(int column) const;
    HeadPtr getHead(const std::string& headName)const;

    const LayoutPtr& getLayout() const{ return m_layout; }

  protected:
    Table(const Table&) = delete;
    Table& operator =(const Table&) = delete;
  private:
    const std::string m_tableName;
    RecordMap m_records;
    HeadMap m_heads;
    LinkMap m_links;
    const LayoutPtr m_layout;
    std::set<std::string> m_dependTable;
  };



}

/************************************************
 * \file Table.cpp
 * \date 2018/12/26 13:50
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
#include "Table.h"
#include "Utility.h"
namespace ToolSpace{


  Table::Table(const TTableLayout& layout) : m_layout(layout), m_tableName(tolower(m_layout.table)){
  
  }
  Table::Table(const std::string& table) : m_tableName(tolower_copy(table)){
    m_layout.table = m_tableName;
  }

  Table::~Table(){
  
  }

  bool Table::addHead(const HeadPtr& ptr){
    return m_heads.addData(ptr->index, ptr);
  }

  bool Table::addRecord(const RecordPtr& ptr){
    return m_records.addData(ptr->record_index, ptr);
  }

  bool Table::hadRecord(const RecordIndexType& index) const{
    return m_records.hasData(index);
  }
  bool Table::addLink(const LinkPtr& ptr){
    return m_links.addData(ptr->link, ptr);
  }


  Table::HeadPtr Table::getHead(int index) const{
    return m_heads.getData(index);
  }

  Table::HeadPtr Table::getColumnHead(int column) const{
    return m_heads.getData([column](const HeadMap::pair_type& pair){
      auto ptr = pair.second;
      if (ptr && ptr->column == column){
        return true;
      }
      return false;
    
    });
  }

  Table::HeadPtr Table::getHead(const std::string& headName) const{
    return m_heads.getData([&headName](const HeadMap::pair_type& pair){
      auto ptr = pair.second;
      if (ptr && ptr->name == headName){
        return true;
      }
      return false;
    });
  }


}
/************************************************
 * \file TableTool.h
 * \date 2018/12/26 14:17
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
#include "MapTemplate.h"
#include <set>
#include <fstream>

namespace ToolSpace{
  enum ProtoType{
     PROTO_VER2 = 0,
     PROTO_VER3 = 1,
  };
  class Table;
  struct TEnum;
  class TableTool
  {
  public:
    struct ExcelFile{
      explicit ExcelFile(const std::string& t):file_name(t){}
      explicit ExcelFile(){}
      const std::string file_name;
      std::set<std::string> sheet_set;
    };
    struct TableLinkArgs{
      explicit TableLinkArgs(const std::string& t) : table_name(t){}
      explicit TableLinkArgs(){}
      const std::string table_name;
      std::vector<std::string> link_args;
    };
    struct ToolArgs{
      std::string setting_file;
      std::string layout_file = "TableLayout.layout";
      std::string name_space = "TableSpace";
      std::string all_config_name = "Game";
      std::string tail_config_name = "Config";
      std::string out_dir = "../export/";
      std::string excel_dir = "../";
      std::string out_file_name = "AllConfig";
      std::string common_define_name = "ConfigType";
      std::string common_group_name = "ConfigTypeGroup";
      std::string version = "v1.0.0.0";
      int next_table_id = 2;
      int version_table_id = 1;
      ProtoType proto_type = PROTO_VER3;
    };

    typedef ObjPtrMap<std::string, Table> TableMap;
    typedef TableMap::value_type TablePtr;
    typedef ObjPtrMap<std::string, TEnum> EnumMap;
    typedef EnumMap::value_type EnumPtr;
    typedef ObjectMap<std::string, ExcelFile> ExcelSheetMap;
    typedef ObjectMap<std::string, TableLinkArgs> TableLinkMap;

    explicit TableTool(const std::string& file, const std::string& version, ProtoType type, const std::string& log);
    virtual ~TableTool();

    enum{
      SETTING_ENUM_INDEX = 0,
      SETTING_TABLE_INDEX = 1,
      SETTING_OUT_INDEX = 2,
      SETTING_CHECK_INDEX = 3,
    };

    enum {
      COLUMN_FILE = 0,
      COLUMN_SHEET = 1,
    };

    enum {
      ROW_NAME_SPACE = 0,
      ROW_ALL_CONFIG_NAME ,
      ROW_TAIL_CONFIG_NAME ,
      ROW_OUT_DIR ,
      ROW_EXCEL_DIR ,
      ROW_OUT_FILE_NAME,
      ROW_COMMON_DEFINE_NAME,
      ROW_COMMON_GROUP_NAME,
      ROW_LAYOUT_FILE_NAME,
    };

    enum {
      ENUM_ROW_NAME = 0,
      ENUM_ROW_TYPE,
      ENUM_ROW_COMMENT,
     
    };

  private:
    bool run();
    bool loadSetting(const std::string& file);
    bool loadEnum(const std::string& file);
    bool loadTable(const std::string& file);
    bool loadCheck(const std::string& file);
    bool loadLayout(const std::string& file);
    bool check();

    void save();
    void saveToLua();
    void saveToJson();
    void saveToSql();
    void saveToLuaFile();
    void saveLayout();

    template<typename T, typename ...ARGS>
    void debug(T t, ARGS ... args){
      auto str = makeString(t, args...);
      m_log << "[d]:" << str << "\n";
    }

    template<typename T, typename ...ARGS>
    void error(T t, ARGS ... args){
      auto str = makeString(t, args...);
      m_log << "[e]:" << str << "\n";
      m_error = true;
    }

  protected:
    TableTool(const TableTool&) = delete;
    TableTool& operator=(const TableTool&) = delete;
  private:
    TableMap m_tables;
    EnumMap m_enums;
    ExcelSheetMap m_excels;
    ExcelSheetMap m_enumExcels;
    ExcelSheetMap m_checkExcels;
    TableLinkMap m_links;
    ToolArgs m_args;
    mutable bool m_error;
    mutable std::ofstream m_log;
  };

}
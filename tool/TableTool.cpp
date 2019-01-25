/************************************************
 * \file TableTool.cpp
 * \date 2018/12/26 15:16
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
#include "TableTool.h"
#include "ExcelReader.h"
#include "Utility.h"
#include "litlua.h"
#include "pbc-lua.h"
#include "lfs.h"

namespace ToolSpace{

  std::string TableTool::U2G(const std::string& str){
#ifdef WIN32
    return utf8_to_gbk(str);
#else
    return str;
#endif
  }

  TableTool::TableTool(const std::string& file, const std::string& version, ProtoType type, const std::string& log):m_log(log, std::ios::out | std::ios::binary){
    m_args.proto_type = type;
    m_args.setting_file = file;
    m_args.version = version;
    m_error = false;
    m_state = nullptr;
    
  }

  TableTool::~TableTool(){
    m_log.close();
  }

  bool TableTool::init(){
    static std::function<void(std::string)> erfun = [this](std::string er){
      error(er);
    };

    static std::function<void(std::string)>  lgfun = [this](std::string info){ debug(info); };
    m_state = luaL_newstate();
    LitSpace::openLuaLibs(m_state);
    LitSpace::openLuaLib(m_state, "protobuf.c", luaopen_protobuf_c);
    luaopen_lfs(m_state);
    LitSpace::add_fun2(m_state, "error_info", erfun);
    LitSpace::add_fun2(m_state, "debug_info", lgfun);
    LitSpace::class_reg<ToolArgs>(m_state, "ToolArgs");
    LitSpace::class_mem<ToolArgs>(m_state, "layout_file", &ToolArgs::layout_file);
    LitSpace::class_mem<ToolArgs>(m_state, "name_space", &ToolArgs::name_space);
    LitSpace::class_mem<ToolArgs>(m_state, "all_config_name", &ToolArgs::all_config_name);
    LitSpace::class_mem<ToolArgs>(m_state, "tail_config_name", &ToolArgs::tail_config_name);
    LitSpace::class_mem<ToolArgs>(m_state, "out_dir", &ToolArgs::out_dir);
    LitSpace::class_mem<ToolArgs>(m_state, "excel_dir", &ToolArgs::excel_dir);
    LitSpace::class_mem<ToolArgs>(m_state, "out_file_name", &ToolArgs::out_file_name);
    LitSpace::class_mem<ToolArgs>(m_state, "common_define_name", &ToolArgs::common_define_name);
    LitSpace::class_mem<ToolArgs>(m_state, "common_group_name", &ToolArgs::common_group_name);
    LitSpace::class_mem<ToolArgs>(m_state, "common_enum_name", &ToolArgs::common_enum_name);
    LitSpace::class_mem<ToolArgs>(m_state, "version", &ToolArgs::version);
    LitSpace::class_mem<ToolArgs>(m_state, "proto_type", &ToolArgs::proto_type);
    
    LitSpace::dofile(m_state, "./lua/tool.lua");
    return true;
  }

  void TableTool::shutDown(){
    if (m_state){
      lua_close(m_state);
      m_state = nullptr;
    }
  }

  bool TableTool::run(){
    if (!loadSetting(m_args.setting_file)){
      error("load setting file :", m_args.setting_file, " failed!");
      return false;
    }

    m_enumExcels.forEachValue([this](const ExcelFile& file){
      if (!loadEnum(file.file_name)){
        error("load enum file :", file.file_name, " failed!");
      }
    });

    m_excels.forEachValue([this](const ExcelFile& file){
      if (!loadTable(file.file_name)){
        error("load table file :", file.file_name, " failed!");
      }
    });

    m_checkExcels.forEachValue([this](const ExcelFile& file){
      if (!loadCheck(file.file_name)){
        error("load check file :", file.file_name, " failed!");
      }
    });

    if(!check()){
     // m_error = true;
      //return false;
    }

    if (!m_error){
      save();
    }
    return !m_error;
  }

  bool TableTool::loadSetting(const std::string& file){
    
    auto loadSheet = [](ExcelSheetMap& map, ExcelSpace::SheetPtr sheet){
      if (!sheet){ return;  }

      for (int r = 0; r < sheet->rowCount(); ++r){
        std::string columnFile = ToolSpace::strlimit(sheet->read(r, COLUMN_FILE));
        std::string columnName = ToolSpace::strlimit(sheet->read(r, COLUMN_SHEET));
        if (columnFile.empty() || columnName.empty()){break; }

        if (!map.hasData(columnFile)){
          ExcelFile obj (columnFile);
          obj.sheet_set.insert(columnName);
          map.addData(obj.file_name, obj);
        }else{
          map.getData(columnFile).sheet_set.insert(columnName);
        }
       
      }
    };
    
    auto book = ExcelSpace::ExcelBook::openBook(file);
    if (!book){   return false; }

    auto sheet = book->getSheet(SETTING_ENUM_INDEX);
    if (!sheet){
      error("load enum setting failed");
      return false;
    }

    loadSheet(m_enumExcels, sheet);

    sheet = book->getSheet(SETTING_TABLE_INDEX);
    if (!sheet){
      error("load table setting failed");
      return false;
    }

    loadSheet(m_excels, sheet);

    for (int r = 0; r < sheet->rowCount(); ++r){
      std::string columnName = ToolSpace::strlimit(sheet->read(r, COLUMN_SHEET));
      if ( columnName.empty()){ break; }
      for (int column = COLUMN_SHEET + 1; column < sheet->colCount(); ++column){
        std::string link = ToolSpace::strlimit(sheet->read(r, column));
        if (link.empty()){ break; }
        LitSpace::call<void>(m_state, "add_table_link", columnName, link);
      }
    }

    sheet = book->getSheet(SETTING_OUT_INDEX);
    if (!sheet){
      error("load out setting failed");
      return false;
    }

    m_args.name_space = strlimit(sheet->read(ROW_NAME_SPACE, COLUMN_FILE), false);
    m_args.all_config_name = strlimit(sheet->read(ROW_ALL_CONFIG_NAME, COLUMN_FILE), false);
    m_args.tail_config_name = strlimit(sheet->read(ROW_TAIL_CONFIG_NAME, COLUMN_FILE), false);
    m_args.out_dir = strlimit(sheet->read(ROW_OUT_DIR, COLUMN_FILE), false);
    m_args.excel_dir = strlimit(sheet->read(ROW_EXCEL_DIR, COLUMN_FILE), false);
    m_args.out_file_name = strlimit(sheet->read(ROW_OUT_FILE_NAME, COLUMN_FILE), false);
    m_args.common_define_name = strlimit(sheet->read(ROW_COMMON_DEFINE_NAME, COLUMN_FILE), false);
    m_args.common_group_name = strlimit(sheet->read(ROW_COMMON_GROUP_NAME, COLUMN_FILE), false);
    m_args.layout_file = strlimit(sheet->read(ROW_LAYOUT_FILE_NAME, COLUMN_FILE), false);

    LitSpace::call<void>(m_state, "set_tool_args", m_args);

    sheet = book->getSheet(SETTING_CHECK_INDEX);
    if (!sheet){
      error("load check setting failed");
      return false;
    }
    loadSheet(m_checkExcels, sheet);
    return true;
  }

  bool TableTool::loadEnum(const std::string& file){
    std::string path = m_args.excel_dir + file;
    ExcelSpace::BookPtr book = ExcelSpace::ExcelBook::openBook(path);
    if (!book){
      error("load enum file:", file, " failed");
      return false;
    }

    if (!m_enumExcels.hasData(file)){
      return false;
    }

    const auto& excelFile = m_enumExcels.getData(file);

    for (int i = 0; i < book->sheetCount(); ++i){
      auto sheet = book->getSheet(i);
      if (!sheet){ break; }

      auto sheetName = tolower(sheet->name());
      if (excelFile.sheet_set.find(sheetName) == excelFile.sheet_set.end()){ continue; }


      for (int col = 0; col < sheet->colCount(); ++col){
        std::string enName = strlimit(sheet->read(ENUM_ROW_NAME, col));
        std::string enType = strlimit(sheet->read(ENUM_ROW_TYPE, col));
        std::string enComment = strlimit(sheet->read(ENUM_ROW_COMMENT, col));
        
        if (enName.empty()){ break; }

        auto rv = LitSpace::rcall<LitSpace::lua_returns<int, int>>(m_state, "read_input_type", enType);
        if (!LitSpace::call<bool>(m_state, "isSingleType", std::get<0>(rv)) || !LitSpace::call<bool>(m_state, "isEnumType", std::get<1>(rv))){
          break;
        }

        LitSpace::call<void>(m_state, "read_enum_name", enName);
        for (int row = ENUM_ROW_COMMENT + 1; row < sheet->rowCount(); ++row){
          std::string enValue = strlimit(sheet->read(row, col));
          std::string enValueComment  = strlimit(sheet->readComment(row, col));
          if (enValue.empty()){ break; }
          LitSpace::call<void>(m_state, "read_enum_value", enName, enValue, enValueComment);
        }

        if (m_args.proto_type == PROTO_VER3){
          bool hasZero = LitSpace::call<bool>(m_state, "check_enum_value", enName, 0);
          if (!hasZero){ LitSpace::call<void>(m_state, "read_enum_value", enName, "unknow_zero=0", "unknow value"); }
        }
      }
    }
    return true;
  }




  bool TableTool::loadTable(const std::string& file){
    std::string path = m_args.excel_dir + file;
    ExcelSpace::BookPtr book = ExcelSpace::ExcelBook::openBook(path);
    if (!book){
      error("load table file:", file, " failed");
      return false;
    }

    if (!m_excels.hasData(file)){
      return false;
    }

    const auto& excelFile = m_excels.getData(file);

    for (int i = 0; i < book->sheetCount(); ++i){
      auto sheet = book->getSheet(i);
      if (!sheet){ break; }

      auto sheetName = tolower(sheet->name());
      if (excelFile.sheet_set.find(sheetName) == excelFile.sheet_set.end()){ continue;}

      if (sheetName.empty()){ continue; }

      // read head type
      LitSpace::call<void>(m_state, "new_table", sheetName);
      for (int column = 0; column < sheet->colCount(); ++column){
        std::string headName = strlimit(sheet->read(HEAD_ROW_NAME, column));
        std::string typeName = strlimit(sheet->read(HEAD_ROW_TYPE, column));
        std::string comment = strlimit(sheet->read(HEAD_ROW_COMMENT, column));

        if (headName.empty() || typeName.empty()){ break; }
        bool res = LitSpace::call<bool>(m_state, "table_head", sheetName, column, headName, typeName, comment);
        if (!res){ 
          return false;
        }
      }


      if(!LitSpace::call<bool>(m_state, "check_table_link", sheetName)){
        return false;
      }

      // read table record
      for (int row = HEAD_ROW_COMMENT + 1; row < sheet->rowCount(); ++row){
        LitSpace::call<void>(m_state, "reset_read_table_record");
        for (int column = 0; column < sheet->colCount(); ++column){
          std::string str = strlimit(sheet->read(row, column));
          bool res = LitSpace::call<bool>(m_state, "add_read_fields", sheetName, column, str);
          if (!res){ break;}
        }
        if (LitSpace::call<bool>(m_state, "read_record_end")){break; }
        LitSpace::call<void>(m_state, "add_record", sheetName);
      }

    }

    LitSpace::call<void>(m_state, "dump_tables");
    return true;
  }

  bool TableTool::loadCheck(const std::string& file){
    std::string path = m_args.excel_dir + file;
    ExcelSpace::BookPtr book = ExcelSpace::ExcelBook::openBook(path);
    if (!book){
      error("load table file:", file, " failed");
      return false;
    }

    if (!m_checkExcels.hasData(file)){
      return false;
    }

    const auto& excelFile = m_checkExcels.getData(file);
    for (int i = 0; i < book->sheetCount(); ++i){
      auto sheet = book->getSheet(i);
      if (!sheet){ break; }

      auto sheetName = tolower(sheet->name());
      if (excelFile.sheet_set.find(sheetName) == excelFile.sheet_set.end()){ continue; }

      if (sheetName.empty()){ continue; }

      for (int row = 0; row < sheet->rowCount(); ++row){
        auto h = sheet->read(row, CHECK_COLUMN_HEAD);
        auto c = sheet->read(row, CHECK_COLUMN_CONTENT);
        if (h.empty() || c.empty()){
          break;
        }

        LitSpace::call<void>(m_state, "add_check_field", h, c);
      }
    
    
    }


    return true;
  }

  bool TableTool::check(){
    return  LitSpace::call<bool>(m_state, "check_data");
  }

  void TableTool::save(){
    LitSpace::call<void>(m_state, "save_configs");
  }

}
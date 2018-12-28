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
#include "Table.h"
#include "litlua.h"
namespace ToolSpace{

  TableTool::TableTool(const std::string& file, const std::string& version, ProtoType type, const std::string& log):m_log(log, std::ios::out | std::ios::binary){
    m_args.proto_type = type;
    m_args.setting_file = file;
    m_args.version = version;
    m_args.next_table_id = 2;
    m_error = false;
    m_state = nullptr;
    
  }

  TableTool::~TableTool(){
    m_log.close();
  }

  bool TableTool::init(){
    m_state = luaL_newstate();
    LitSpace::openLuaLibs(m_state);
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

    if (!loadLayout(m_args.layout_file)){
      error("load layout file :", m_args.layout_file, " failed!");
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
      m_error = true;
      return false;
    }

    if (!m_error){
      save();
    }
    return !m_error;
  }

  bool TableTool::loadSetting(const std::string& file){
    
    auto loadSheet = [](ExcelSheetMap& map, ExcelSpace::SheetPtr sheet){
      if (!sheet){
        return;
      }

      for (int r = 0; r < sheet->rowCount(); ++r){
        std::string columnFile = ToolSpace::strlimit(sheet->read(r, COLUMN_FILE));
        std::string columnName = ToolSpace::strlimit(sheet->read(r, COLUMN_SHEET));
        if (columnFile.empty() || columnName.empty()){
          break;
        }

     
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
    if (!book){
      return false;
    }

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
        if (link.empty()){
          break;
        }
        if (m_links.hasData(columnName)){
          m_links.getData(columnName).link_args.push_back(link);
        }else{
          TableLinkArgs args(columnName);
          args.link_args.push_back(link);
          m_links.addData(columnName, args);
        }
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

    sheet = book->getSheet(SETTING_CHECK_INDEX);
    if (!sheet){
      error("load check setting failed");
      return false;
    }
    loadSheet(m_checkExcels, sheet);
    return true;
  }



  bool TableTool::loadLayout(const std::string& file){
    std::string path = m_args.out_dir + m_args.layout_file;
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
      if (excelFile.sheet_set.find(sheetName) == excelFile.sheet_set.end()){
        continue;
      }


      for (int col = 0; col < sheet->colCount(); ++col){
        std::string enName = strlimit(sheet->read(ENUM_ROW_NAME, col));
        std::string enType = strlimit(sheet->read(ENUM_ROW_TYPE, col));
        std::string enComment = strlimit(sheet->read(ENUM_ROW_COMMENT, col));
        
        if (enName.empty()){ break; }

        auto rv = LitSpace::rcall<LitSpace::lua_returns<int, int>>(m_state, "read_type", enType);
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

        LitSpace::resetStack(m_state);
        LitSpace::table t = LitSpace::call<LitSpace::table>(m_state, "get_enum", enName);
        if (!t.isNil()){
          EnumPtr en = std::make_shared<TEnum>();
          en->full_name = t.get<std::string>("full_name");
          en->name = t.get<std::string>("name");
          en->table = t.get<std::string>("table");
          LitSpace::table values = t.get<LitSpace::table>("values");
          if (!values.isNil()){
            int len = values.len();
            for (size_t i = 1; i <= len; ++i){
              LitSpace::table value_table = values.get<LitSpace::table>(i);
              if (!value_table.isNil()){
                TEnumValue tev;
                tev.name = value_table.get<std::string>(1);
                tev.value = value_table.get<int>(2);
                tev.comment = value_table.get<std::string>(3);
                en->values.addData(tev.name, tev);
              }
            }
          }
          m_enums.addData(en->full_name, en);
        }

        LitSpace::resetStack(m_state);
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

      auto layout = m_layouts.getData(sheetName);
      if (!layout){
        layout = std::make_shared<TTableLayout>();
        layout->table = sheetName;
        layout->next_index = 1;
        layout->key_index = 1;
        m_layouts.addData(layout->table, layout);
      }
      TablePtr table = std::make_shared<Table>(layout);
      m_tables.addData(table->tableName(), table);
      layout = table->getLayout();
      if (!layout){ error(sheetName, " layout get error "); return false; }

      // read head type
      for (int column = 0; column < sheet->colCount(); ++column){
        std::string headName = strlimit(sheet->read(HEAD_ROW_NAME, column));
        std::string typeName = strlimit(sheet->read(HEAD_ROW_TYPE, column));
        std::string comment = strlimit(sheet->read(HEAD_ROW_COMMENT, column));

        if (headName.empty() || typeName.empty()){ break; }
        auto rv = LitSpace::rcall<LitSpace::lua_returns<int, int, std::string>>(m_state, "read_type", typeName);
        auto basicType = std::get<1>(rv);
        if (LitSpace::call<bool>(m_state, "isNoneType", basicType)){
          continue;
        }

        auto mutiType = std::get<0>(rv);
        HeadPtr head = std::make_shared<THead>();
        head->basic_type = basicType;
        head->muti_type = mutiType;
        head->column = column;
        head->comment = comment;
        head->table = table->tableName();
        head->name = headName;
        head->type_name = typeName;
        head->type_basic_name = std::get<2>(rv);

        if (layout->layouts.hasData(head->name)){
          head->index = layout->layouts.getData(head->name).head_index;
        }else{
          head->index = layout->next_index;
          layout->next_index++;
        }

        if (head->index == TABLE_KEY_INDEX){
            if (!LitSpace::call<bool>(m_state, "checkKeyType", mutiType, basicType)){
              error(head->table, " key must single type");
              return false;
            }
        }

        if(!table->addHead(head)){
          error(head->table, " add head ", head->name, " error");
          return false;
        }

        if (LitSpace::call<bool>( m_state, "isSelfEnumType", head->basic_type)){
          if(!m_enums.hasData(head->type_basic_name)){
            error(head->table, " add head ", head->name, " with enum:", head->type_basic_name, " not found");
            return false;
          }

          auto en = m_enums.getData(head->type_basic_name);
          table->depentTable(en->table);
        }
      }

      //check table link type
      if (m_links.hasData(table->tableName())){
        auto& links = m_links.getData(table->tableName());
        for (auto& str : links.link_args){
          LinkPtr ptr = std::make_shared<TLink>();
          ptr->heads = split(str, ",");
          ptr->link = join(ptr->heads, "_");

          for (auto&name : ptr->heads){
            auto head = table->getHead(name);
            if (!head){
              error(table->tableName(), " not found link head :", name);
              return false;
            }

            if (!LitSpace::call<bool>(m_state, "checkKeyType", head->muti_type, head->basic_type)){
              error(head->table, " not found allow link types:", head->name);
              return false;
            }
          }

          table->addLink(ptr);
        }
      }

      // read table record
      for (int row = HEAD_ROW_COMMENT + 1; row < sheet->rowCount(); ++row){
        RecordPtr record = std::make_shared<TRecord>();
        for (int column = 0; column < sheet->colCount(); ++column){
          auto head = table->getColumnHead(column);
          if (!head){
            continue;
          }
         
          std::string str = strlimit(sheet->read(row, column));
          if (head->index == TABLE_KEY_INDEX){
            record->record_index = str;
          }
          TField field;
          field.record_index = record->record_index;
          field.field_value_str = str;

          LitSpace::resetStack(m_state);
          LitSpace::table t = LitSpace::call<LitSpace::table>(m_state, "read_data", field.field_value_str, head->basic_type, head->muti_type, head->type_name);
          if (t.isNil()){
            error(table->tableName(), " read ", field.field_value_str, " error with head ", head->name);
            return false;
          }

          int len = t.len();
          if (LitSpace::call<bool>(m_state, "isSingleType", head->muti_type)){
            assert(len >= 1);
            field.field_value = t.get<BasicValueType>(1);
          }else if (LitSpace::call<bool>(m_state, "isArrayType", head->muti_type)){
            ArrayValueType array;
            for (int i = 1; i <= len; ++i){
              array.push_back(t.get<BasicValueType>(i));
            }
            field.field_value = array;
          }if (LitSpace::call<bool>(m_state, "isGroupType", head->muti_type)){
            GroupValueType group;
            for (int i = 1; i <= len; ++i){
              auto ti = t.get<LitSpace::table>(i);
              if (!ti.isNil()){
                ArrayValueType array;
                int tilen = ti.len();
                for (int j = 1; j <= tilen; ++j){
                  array.push_back(ti.get<BasicValueType>(j));
                }
                group.push_back(array);
              }
            }
            field.field_value = group;
          }
          LitSpace::resetStack(m_state);
          record->fields.addData(head->index, field);
        }

        if (record->record_index.empty()){
          break;
        }
        table->addRecord(record);
      }

    }
    return true;
  }

  bool TableTool::loadCheck(const std::string& file){
    return true;
  }

  bool TableTool::check(){
    return true;
  }

  void TableTool::save(){
    saveProto();
    saveToLua();
    saveToJson();
    saveToSql();
    saveToLuaFile();
    saveLayout();

  }

  void TableTool::saveProto(){
  
  }

  void TableTool::saveToLua(){

  }
  void TableTool::saveToJson(){
  }
  void TableTool::saveToSql(){
  }
  void TableTool::saveToLuaFile(){
  }
  void TableTool::saveLayout(){
  }

}
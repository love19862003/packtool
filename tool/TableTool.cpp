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

    
  }

  TableTool::~TableTool(){
    m_log.close();
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
        EnumPtr en = std::make_shared<TEnum>();
        en->full_name = strlimit(sheet->read(ENUM_ROW_NAME, col));
        if (en->full_name.empty()){ break;}
//         auto v = split(en->full_name, ".");
//         en->name = v.back();
//         if (v.size() >= 2){ en->table = v.front(); }

        

         
      }



    }


    return true;
  }




  bool TableTool::loadTable(const std::string& file){
    return true;
  }

  bool TableTool::loadCheck(const std::string& file){
    return true;
  }

  bool TableTool::check(){
    return true;
  }

  void TableTool::save(){
  
  }


}
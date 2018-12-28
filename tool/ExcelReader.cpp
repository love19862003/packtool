/************************************************
 * \file ExcelReader.cpp
 * \date 2018/12/25 16:06
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
#include <regex>
#include <locale>
#include "ExcelReader.h"
#include "MapTemplate.h"
#include "Utility.h"
#include "xlnt/xlnt.hpp"
namespace ExcelSpace{

    class XlntSheet : public Sheet
    {
    public:
      XlntSheet(const xlnt::worksheet& sheet) : m_sheet(sheet){}
      virtual ~XlntSheet(){}

      virtual int rowCount() final {return m_sheet.rows().length();}

      virtual int colCount() final {return m_sheet.columns().length();}

      virtual std::string read(int row, int col) final{
         auto ref = cellRef(row, col);
         std::string res;

         if (!m_sheet.has_cell(ref)){
           return res;
         }
         auto cell = m_sheet.cell(ref);
         res = cell.to_string();
         if (xlnt::cell_type::boolean ==  cell.data_type()){
           res = cell.value<double>() == 0.L ? "1" : "0";
         }
         return res;
      }


      virtual std::string readComment(int row, int col) final{
        auto ref = cellRef(row, col);
        std::string res("none");
        if (!m_sheet.has_cell(ref)){
          return res;
        }

        auto cell = m_sheet.cell(ref);
        if (cell.has_comment()){
          res = cell.comment().plain_text();
        }
        return res;
      }

      virtual std::string name() final {
        return ToolSpace::tolower( m_sheet.title());
      }


      xlnt::cell_reference cellRef(int row, int col) const{
        xlnt::column_t c(col + 1);
        xlnt::row_t r(row + 1);
        return xlnt::cell_reference(c, r);
      }
    protected:
    private:
      const xlnt::worksheet m_sheet;
    };


    class XlntBook  : public ExcelBook
    {
    public:
        XlntBook(const std::string& path){
          
         // try{

            m_book.load(path);
           
//           } catch (...){
// 
//           }

          for (int i = 0; i < m_book.sheet_count(); ++i){
            m_sheets.addData(i, std::make_shared<XlntSheet>(m_book.sheet_by_index(i)));
          }
          
        }
        virtual ~XlntBook(){
          m_sheets.clear();
        }

        virtual  SheetPtr  getSheet(int index) final{
          return m_sheets.getData(index);
        }

        virtual SheetPtr getSheet(const std::string& sheetName) final{
          SheetPtr res = nullptr;
          m_sheets.forEachValue([&res, &sheetName](const std::shared_ptr<Sheet>& ptr){
            if (ptr && ptr->name() == sheetName){
              res = ptr;
            }
          });
          return res;
        }

        virtual int sheetCount() final {
          return m_sheets.size();
        }

        virtual const std::string& error() final {
          return m_error;
        }

    protected:
    private:
      typedef ToolSpace::ObjPtrMap<int, Sheet> SheetMap;
      xlnt::workbook m_book;
      std::string m_error;
      SheetMap m_sheets;
    };


    //check file type is xlsx
    BookPtr ExcelBook::openBook(const std::string& file){
      const char* regex = ".+\\.xlsx$";
      std::regex reg(regex);
      std::cmatch match;
      if (std::regex_match(file.data(), match, reg)){
        return std::make_shared<XlntBook>(file);
      }
      return nullptr;
    }

}
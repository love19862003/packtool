/************************************************
 * \file ExcelReader.h
 * \date 2018/12/25 16:00
 *
 * \author wufan
 * Contact: love19862003@163.com
 *
 * \brief excel reader class
 *
 * TODO: long description
 *
 * \note
*************************************************/
#pragma once
#include <string>
#include <memory>
namespace ExcelSpace{

  class Sheet{
  public:
    virtual int rowCount() = 0;
    virtual int colCount() = 0;
    virtual std::string read(int row, int col) = 0;
    virtual std::string readComment(int row, int col) = 0;
    virtual std::string name() = 0;
  protected:
  private:
  };

  class ExcelBook;
  typedef std::shared_ptr<ExcelBook> BookPtr;
  typedef std::shared_ptr<Sheet> SheetPtr;

  class ExcelBook{
  public:
    static BookPtr openBook(const std::string& file);
    virtual SheetPtr getSheet(int index) = 0;
    virtual SheetPtr getSheet(const std::string& name) = 0;
    virtual int sheetCount() = 0;
    virtual const std::string& error() = 0;
  protected:
  private:
  };


}
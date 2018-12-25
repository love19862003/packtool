/************************************************
 * \file Utility.h
 * \date 2018/12/25 16:44
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
#include <string>
#include <locale>
#include <algorithm>
namespace ToolSpace{

  inline std::string& tolower( std::string& str){
    std::for_each(str.begin(), str.end(), [](char& c){ c = std::tolower(c, std::locale()); });
    return str;
  }

  inline std::string& toupper(std::string& str){
    std::for_each(str.begin(), str.end(), [](char& c){ c = std::toupper(c, std::locale()); });
    return str;
  }

}

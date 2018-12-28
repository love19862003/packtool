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
#include <vector>
#include <regex>
namespace ToolSpace{

  inline std::string& tolower( std::string& str){
    std::for_each(str.begin(), str.end(), [](char& c){ c = std::tolower(c, std::locale()); });
    return str;
  }

  inline std::string tolower_copy(const std::string& str){
    std::string res(str);
    tolower(res);
    return res;
  }

  inline std::string& toupper(std::string& str){
    std::for_each(str.begin(), str.end(), [](char& c){ c = std::toupper(c, std::locale()); });
    return str;
  }

  inline std::string toupper_copy(const std::string& str){
    std::string res(str);
    toupper(res);
    return res;
  }

  inline std::string& replace(std::string& str, const std::string& tag, const std::string& t){
    std::string::size_type pos = 0;
    std::string::size_type tag_len = tag.size();
    std::string::size_type t_len = t.size();
    while (pos = str.find(tag, pos) ){
      if (pos == std::string::npos){ break;}
      str.replace(pos, tag_len, t);
      pos += t_len;
    }
    return str;
  }

  inline std::string replace_copy(const std::string& str, const std::string& tag, const std::string& t){
    std::string res(str);
    replace(res, tag, t);
    return res;
  }


  inline std::vector<std::string> split(const std::string& str, const std::string& tag){
    std::regex re(tag);
    std::sregex_token_iterator it(str.begin(), str.end(), re, -1);
    std::sregex_token_iterator end;
    return {it, end};
  }

  inline std::string join(const std::vector<std::string>& v, const std::string& tag){
    std::string res;
    auto it = v.begin();
    auto itEnd = v.end();
    if (it != itEnd){
      res.append(*it);
      ++it;
    }

    for (; it != itEnd; ++it ){
      res.append(tag).append(*it);
    }
    return res;
  }


  inline std::string& strlimit(std::string& str, bool lower = true){
    replace(str, " ", "");
    replace(str, "\n", "");
    replace(str, "\t", "");
    if(lower)tolower(str);
    return str;
  } 

  inline std::string strlimit_copy(const std::string& str, bool lower = true){
    std::string res(str);
    strlimit(res, lower);
    return res;
  }

  

}

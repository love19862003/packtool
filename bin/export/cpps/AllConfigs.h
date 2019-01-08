/************************************************
* file AllConfigs.h
* date Tue Jan  8 16:01:32 2019
*
* author wufan
* Contact: love19862003@163.com
*
* brief
*
* TODO: long description
*
* note
*************************************************/
#pragma once
#include <memory>
#include <functional>
#include "roleConfig.pb.h"
namespace Pro {
  class roleConfig;
  class monsterConfig;
}
namespace Pro {

 class AllConfigs {
 public:
  AllConfigs();
  ~AllConfigs()
  bool init(const std::string& files);
  bool init(const char* bytes, size_t len);
  bool reload();
  const std::string& fileName() const;
  const std::string& version() const;
  // table role interfaces
  const roleConfig& role(const int& index) const;
  bool has_role(const int& index) const;
  bool role(const std::function<bool(const roleConfig&)>& call) const;
  
  // table monster interfaces
  const monsterConfig& monster(const std::string& index) const;
  bool has_monster(const std::string& index) const;
  bool monster(const std::function<bool(const monsterConfig&)>& call) const;
  // table monster links
  const monsterConfig& monster_by_job_level_sub(const role::jobtype& job, const int& level, const int& sub) const;
  
 private:
  AllConfigs (const AllConfigs&) = delete;
  AllConfigs& operator = (const AllConfigs&) = delete;
  class Impl;
  std::unique_ptr<Impl> m_impl;
 }; //AllConfigs
}//Pro


/************************************************
* file AllConfigs.cpp
* date Mon Jan  7 19:27:45 2019
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
#include <memory>
#include <map>
#include <fstream>
#include <tuple>
#include "AllConfigs.h"
#include "GameConfig.pb.h"
namespace Pro{
 class AllConfigs ::Impl{
 public:
  bool init(const std::string& file){
   m_fileName = file;
   clear();
   std::ifstream ifile(file.data(), std::ios::binary | std::ios::in);
   auto ptr = make_shared<GameConfig>();
   bool res = ptr->ParseFromIstream(ifile);
   ifile.close();
   if(!res){return res;}
   fill(ptr);
   return true;
  }
  bool init(const char* bytes, size_t len){
   m_fileName.clear();
   clear();
   auto ptr = make_shared<GameConfig>();
   bool res = ptr->ParseFromArray(bytes, len);
   if(!res){return res;}
   fill(ptr);
   return true;
  }
  bool reload(){return init(m_fileName);}
  void clear(){
   m_monster.clear();
   // table monster links
   m_monster_link_job_level_sub.clear();
   m_role.clear();
  }
  void fill(const std::shared_ptr< GameConfig >& ptr){
   m_version = ptr->version();
   for(auto& v : ptr->monster()){
    m_monster[v.id()] = v;
    // table monster links
    job_level_sub_type job_level_sub_value = std::make_tuple(v.job(), v.level(), v.sub());
    m_monster_link_job_level_sub[job_level_sub_value] = v.id();
   }
   for(auto& v : ptr->role()){
    m_role[v.id()] = v;
   }
  }
  const std::string& fileName() const{return m_fileName;}
  const std::string& version() const{return m_version;}
  // table monster interfaces
  const monsterConfig& monster(const std::string& index) const;
  bool has_monster(const std::string& index) const;
  bool monster(const std::function<bool(const monsterConfig&)>& call) const;
  // table monster links
  const monsterConfig& monster_by_job_level_sub(const role::jobtype& job, const int& level, const int& sub) const;
  
  // table role interfaces
  const roleConfig& role(const int& index) const;
  bool has_role(const int& index) const;
  bool role(const std::function<bool(const roleConfig&)>& call) const;
  
 private:
  std::string m_version;
  std::string m_fileName;
  std::map<std::string, monsterConfig> m_monster;
  // table monster links
  typedef std::tuple<role::jobtype, int, int> job_level_sub_type;
  std::map<job_level_sub_type, std::string> m_monster_link_job_level_sub;
  std::map<int, roleConfig> m_role;
 };//AllConfigs::Impl
 // table monster interfaces
 const monsterConfig& AllConfigs::Impl::monster(const std::string& index) const{
  try{
   return m_monster.at(index);
  }catch(...){ return monsterConfig::default_instance();}
 }
 bool AllConfigs::Impl::has_monster(const std::string& index) const{
  try{
   return m_monster.count(index) > 0;
  }catch(...){ return false;}
 }
 bool AllConfigs::Impl::monster(const std::function<bool(const monsterConfig&)>& call) const{
  for(auto& pair : m_monster){
   if(call(pair.second)){return true;}
  }
  return false;
 }
 // table monster links
 const monsterConfig& AllConfigs::Impl::monster_by_job_level_sub(const role::jobtype& job, const int& level, const int& sub) const{
  const job_level_sub_type job_level_sub_value = std::make_tuple(job, level, sub);
  const auto& it = m_monster_link_job_level_sub.find(job_level_sub_value);
  if(it != m_monster_link_job_level_sub.end()){return  monster(it->second);}
  else{ return monsterConfig::default_instance();}
 }
 
 // table role interfaces
 const roleConfig& AllConfigs::Impl::role(const int& index) const{
  try{
   return m_role.at(index);
  }catch(...){ return roleConfig::default_instance();}
 }
 bool AllConfigs::Impl::has_role(const int& index) const{
  try{
   return m_role.count(index) > 0;
  }catch(...){ return false;}
 }
 bool AllConfigs::Impl::role(const std::function<bool(const roleConfig&)>& call) const{
  for(auto& pair : m_role){
   if(call(pair.second)){return true;}
  }
  return false;
 }
 
 AllConfigs::AllConfigs():m_impl(new Impl()){}
 
 AllConfigs::~AllConfigs(){ m_impl.reset();}
 //init by file
 bool AllConfigs::init(const std::string& file){return m_impl->init(file);}
 //init by bytes
 bool AllConfigs::init(const char* bytes, size_t len){return m_impl->init(bytes, len);}
 //reload
 bool AllConfigs::reload(){return m_impl->reload();}
 //file
 const AllConfigs::std::string& fileName() const{return m_impl->fileName();}
 //version
 const AllConfigs::std::string& version() const{return m_impl->version();}
 // table monster interfaces
 const monsterConfig& AllConfigs::monster(const std::string& index) const{
  return m_impl->AllConfigs::(index);
 }
 bool AllConfigs::has_monster(const std::string& index) const{
  return m_impl->has_monster(index);
 }
 bool AllConfigs::monster(const std::function<bool(const monsterConfig&)>& call) const{
  return m_impl->monster(call);
 }
 // table monster links
 const monsterConfig& AllConfigs::monster_by_job_level_sub(const role::jobtype& job, const int& level, const int& sub) const{
  return m_impl->monster_by_job_level_sub(job, level, sub);
 }
 
 // table role interfaces
 const roleConfig& AllConfigs::role(const int& index) const{
  return m_impl->AllConfigs::(index);
 }
 bool AllConfigs::has_role(const int& index) const{
  return m_impl->has_role(index);
 }
 bool AllConfigs::role(const std::function<bool(const roleConfig&)>& call) const{
  return m_impl->role(call);
 }
 
}//Pro


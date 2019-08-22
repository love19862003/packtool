#include "litlua.h"
#include "pbc-lua.h"
#include "AllConfigs.h"
#include "roleConfig.pb.h"
#include "monsterConfig.pb.h"

void run_test(){
 
  Pro::AllConfigs configs;
  bool r = configs.init("./export/data/AllConfigs.bin");
  assert(r);
  assert(configs.has_role(1));
  assert(!configs.has_role(100));
  assert(configs.has_monster("1"));
  assert(configs.monster("1").level() == 1);
  std::cout << configs.monster("1").DebugString() << std::endl;
  assert(configs.monster("2").sub() == 1);
  configs.monster([](const Pro::monsterConfig& conf){
    std::cout << conf.DebugString() << std::endl;
    return false;
  });
  std::cout << configs.version() << std::endl;

}
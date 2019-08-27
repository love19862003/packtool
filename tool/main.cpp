/********************************************************************

  Filename:   main

  Description:main

  Version:  1.0
  Created:  15:4:2015   16:11
  Revison:  none
  Compiler: gcc vc

  Author:   wufan, love19862003@163.com

  Organization:
*********************************************************************/
#include <iostream>
#include "TableTool.h"
#include <string>
#include <assert.h>
#ifdef WIN32
#include <windows.h>
#endif
#include "Utility.h"
int main(int argc, char* argv[]) {
#ifdef WIN32
  system("chcp 936");
  system("cls");
  SetConsoleTitle("pack excel to protobuf");
#endif // WIN32

  std::string file = "./setting.xlsx";
  std::string version = "1.0.0.1";
  ToolSpace::ProtoType type = ToolSpace::PROTO_VER3;
  std::string log = "./out.log";
  if (argc > 1) {
    file = argv[1];
  }

  if (argc > 2){
    version = argv[2];
  }

  if (argc > 3){
    type = static_cast<ToolSpace::ProtoType>(std::stoi(argv[3]));
  }

  if (argc > 4){
    log = argv[4];
  }

  bool pause = false;
  if (argc > 5){
    pause = true;
  }

  ToolSpace::TableTool m(file, version, type, log);
  if (!m.init()){
    assert(false);
    return 1;
  }

  bool ret = m.run();

  m.shutDown();

  if (pause){
    getchar();
  }
  
  return ret ? 0 : 1 ;
}
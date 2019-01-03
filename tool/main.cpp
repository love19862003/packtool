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

int main(int argc, char* argv[]) {
  ToolSpace::TableTool m("./setting.xlsx", "1.0.0.1", ToolSpace::PROTO_VER2, "../out.log");
  if (!m.init()){
    return 1;
  }

  if (!m.run()){
    return 1;
  }

  m.shutDown();
#ifdef _DEBUG
   // getchar();
#endif // _DEBUG
    return 0;
}
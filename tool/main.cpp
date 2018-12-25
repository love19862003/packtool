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

int main(int argc, char* argv[]) {
  
//     std::string  tt = "test.xls";
//     std::string  vesion = "v1.0.0.0";
//     ToolSpace::ProtoType proto = ToolSpace::PROTO2_TYPE2;
//     if (argc > 1){
//       std::cout << argv[1] << std::endl;
//       tt = argv[1];
//       
//     }
//     if (argc > 2){
//       vesion = argv[2];
//       std::cout << vesion << std::endl;
//     }
// 
//     if(argc > 3){
//       int i = ToolSpace::PROTO2_TYPE2;
//       try {
//         i = std::stoi(argv[3]);
//         if(i <= 0) {
//           proto = ToolSpace::PROTO2_TYPE2;
//         } else if(i >= ToolSpace::PROTO3_TYPE3) {
//           proto = ToolSpace::PROTO3_TYPE3;
//         } else {
//           proto = ToolSpace::PROTO3_TYPE2;
//         }
//       }catch(...){
//         std::string type(argv[3]);
//         if (type == "proto3_type2"){
//           proto = ToolSpace::PROTO3_TYPE2;
//         }else if (type == "proto3_type3"){
//           proto = ToolSpace::PROTO3_TYPE3;
//         }else{
//           proto = ToolSpace::PROTO2_TYPE2;
//         }
//       }
//     } 
//     
//     ToolSpace::TableManager m(tt.c_str(), vesion, proto);
//     if(!m.run()) { 
//       assert(false);
//     }
#ifdef _DEBUG
    getchar();
#endif // _DEBUG
    return 0;
}
# packtool                                                                                                                                  <br>
read excel to protobuf and pack data                                                                                                        <br>
导出excel文件为proto，并且打包出对应的数据                                                                                                  <br>
支持自定义结构和类型                                                                                                                        <br>
支持自定义枚举                                                                                                                              <br>
支持自动生成c++管理类和相关接口                                                                                                             <br>
支持自动生成C#管理类和接口                                                                                                                  <br>
支持数据检查等                                                                                                                              <br>
支持新老版本兼容                                                                                                                            <br>
支持数据的对比，更新，删除并产生log文件                                                                                                     <br>
                                                                                                                                            <br>
具体使用方法在demo里 bin目录下有运行时候的setting.xlsx文件来配置整个数据包的产出                                                            <br>
第一个sheet页为所有自定义枚举的配置                                                                                                         <br>
  1.每一行的第一个是定义枚举的所在的excel文件 第二列是所在文件的sheet的名字                                                                 <br>
  枚举定义                                                                                                                                  <br>
    表所属枚举定义 表名.枚举名                                                                                                              <br>
    role.JobType   枚举名                                                                                                                   <br>
    enum           类型                                                                                                                     <br>
    职业           注释                                                                                                                     <br>
    COMMON_0=0                                                                                                                              <br>
    NOVICE_1=1                                                                                                                              <br>
    SWORDMAN_2=2                                                                                                                            <br>
    BUSINESSMAN_3=3                                                                                                                         <br>
    ARCHER_4=4                                                                                                                              <br>
    MASTER_5=5                                                                                                                              <br>
    SERVE_6=6                                                                                                                               <br>
    ROBBERS_7=7                                                                                                                             <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
    全局枚举定义 枚举名                                                                                                                     <br>
    CampType    枚举名                                                                                                                      <br>
    enum        类型                                                                                                                        <br>
    阵营        注释                                                                                                                        <br>
    Camp_Light=1                                                                                                                            <br>
    Camp_Dark=2                                                                                                                             <br>
                                                                                                                                            <br>
    枚举值定义  枚举值名=枚举数值                                                                                                           <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
第二个sheet页为所有的table的配置                                                                                                            <br>
  1.每一行的第一个是定义表的所在的excel文件 第二列是所在文件的sheet的名字 第三列是联合索引，支持多个列来查询一条记录。                      <br>
  表文件         sheet名兼表名字             多列联合索引                                                                                   <br>
  monster.xlsx	monster	                   job,level,sub	                                                                                  <br>
                                                                                                                                            <br>
  表的第一列必须是basic_type并且是唯一的来支持索引，                                                                                        <br>
  表结构定义                                                                                                                                <br>
  id	    group_float	  group_string	job                                                                                                   <br>
  string	group<float>	group<string>	role.jobtype                                                                                          <br>
  1	      [[1.2,2.0]]	[[1.2,2.0],[2]]	common_0                                                                                              <br>
                                                                                                                                            <br>
  目前基础类型支持  basic_type                                                                                                              <br>
  none     --注释                                                                                                                           <br>
  string   --字符串                                                                                                                         <br>
  float    --浮点数                                                                                                                         <br>
  int      --整数                                                                                                                           <br>
  bool     --bool                                                                                                                           <br>
  enum     --枚举定义类型                                                                                                                   <br>
  self_enum  --自定义的枚举                                                                                                                 <br>
  self_type  --自定义数据结构                                                                                                               <br>
  coordinate --坐标类型                                                                                                                     <br>
  int5       --int5 value                                                                                                                   <br>
                                                                                                                                            <br>
  self_enum是通过enum定义出来的                                                                                                             <br>
  self_type 是自定义数据结构， 可以参考里面目前coordinate,int5的方式自定义类型,需要实现自定义的解析和定义函数即可                           <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
  维数类型                                                                                                                                  <br>
  array<basic_type>  --数组                                                                                                                 <br>
  group<basic_type>  --二维数组                                                                                                             <br>
                                                                                                                                            <br>
  例如                                                                                                                                      <br>
  array<int> array<role.jobtype>  array<coordinate>                                                                                         <br>
  group<int> group<role.jobtype>  group<coordinate>                                                                                         <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
第三个sheet页为导出的proto和相关管理类的配置                                                                                                <br>
                                                                                                                                            <br>
  Pro	包名。Package                                                                                                                         <br>
  Game	            打包的数据结构名字（ 用于生产管理类的数据。）                                                                           <br>
  Config	          打包的类的后缀名                                                                                                        <br>
  AllConfigs	      输出的管理类和文件名字                                                                                                  <br>
  ./export/	        打包输出目录                                                                                                            <br>
  ./	              excel目录                                                                                                               <br>
  ConfigType	      自定义类型定义                                                                                                          <br>
  ConfigTypeGroup	  group类型定义                                                                                                           <br>
  layout.layout	    表结构布局文件                                                                                                          <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
  打包输出目录会产生几个子文件夹                                                                                                            <br>
  cpps    c++管理类                                                                                                                         <br>
  csharp  c#管理类，另外附带测试工程                                                                                                        <br>
  data    二进制数据包                                                                                                                      <br>
  info    版本迭代信息，数据更新删除等等产生的log                                                                                           <br>
  lua     输出的lua数据                                                                                                                     <br>
  lua_out pbc接口管理                                                                                                                       <br>
  pbs     proto文件的二进制                                                                                                                 <br>
  proto   proto文件                                                                                                                         <br>
  sql     mysql文件                                                                                                                         <br>
                                                                                                                                            <br>
第四个sheet页为数据检测的配置                                                                                                               <br>
  1.每一行的第一个是定义检测的所在的excel文件 第二列是所在文件的sheet的名字                                                                 <br>
  检测语法                                                                                                                                  <br>
  表.列名  = [[ 条件， 条件，...] ,[ 条件， 条件，...] , ...]                                                                               <br>
  条件可以为                                                                                                                                <br>
    表.列名             -- 在表里该列里查找数值                                                                                             <br>
    数值                -- 可以为这个数值                                                                                                   <br>
    ?                   -- 任意                                                                                                             <br>
    枚举                -- 在定义枚举值中                                                                                                   <br>
    枚举.枚举值         -- 必须为枚举值                                                                                                     <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
   具体检测方法可以查看check                                                                                                                <br>
   自定义类型的检测方法，需要自己编写。                                                                                                     <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
                                                                                                                                            <br>
                                                                                                                                            <br>


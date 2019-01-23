# packtool
read excel to protobuf and pack data 
导出excel文件为proto，并且打包出对应的数据
支持自定义结构和类型
支持自定义枚举
支持自动生成c++管理类和相关接口
支持自动生成C#管理类和接口
支持数据检查等
支持新老版本兼容
支持数据的对比，更新，删除并产生log文件

具体使用方法在demo里 bin目录下有运行时候的setting.xlsx文件来配置整个数据包的产出
第一个sheet页为所有自定义枚举的配置 
  1.每一行的第一个是定义枚举的所在的excel文件 第二列是所在文件的sheet的名字
  枚举定义
    表所属枚举定义 表名.枚举名 
    role.JobType   枚举名
    enum           类型
    职业           注释
    COMMON_0=0     
    NOVICE_1=1
    SWORDMAN_2=2
    BUSINESSMAN_3=3
    ARCHER_4=4
    MASTER_5=5
    SERVE_6=6
    ROBBERS_7=7
    
    
    
    全局枚举定义 枚举名
    CampType    枚举名
    enum        类型
    阵营        注释
    Camp_Light=1
    Camp_Dark=2
    
    枚举值定义  枚举值名=枚举数值

  
第二个sheet页为所有的table的配置
  1.每一行的第一个是定义表的所在的excel文件 第二列是所在文件的sheet的名字 第三列是联合索引，支持多个列来查询一条记录。
  表文件         sheet名兼表名字             多列联合索引          
  monster.xlsx	monster	                   job,level,sub	

  表的第一列必须是basic_type并且是唯一的来支持索引，
  表结构定义
  id	    group_float	  group_string	job
  string	group<float>	group<string>	role.jobtype
  1	      [[1.2,2.0]]	[[1.2,2.0],[2]]	common_0

  目前基础类型支持  basic_type
  none     --注释
  string   --字符串
  float    --浮点数
  int      --整数
  bool     --bool
  enum     --枚举定义类型
  self_enum  --自定义的枚举
  self_type  --自定义数据结构  
  coordinate --坐标类型 
  int5       --int5 value
  
  self_enum是通过enum定义出来的
  self_type 是自定义数据结构， 可以参考里面目前coordinate,int5的方式自定义类型,需要实现自定义的解析和定义函数即可
  
  
  维数类型
  array<basic_type>  --数组
  group<basic_type>  --二维数组
  
  例如
  array<int> array<role.jobtype>  array<coordinate>
  group<int> group<role.jobtype>  group<coordinate>
  
  
第三个sheet页为导出的proto和相关管理类的配置
  
  Pro	包名。Package
  Game	            打包的数据结构名字（ 用于生产管理类的数据。）
  Config	          打包的类的后缀名
  AllConfigs	      输出的管理类和文件名字
  ./export/	        打包输出目录
  ./	              excel目录
  ConfigType	      自定义类型定义 
  ConfigTypeGroup	  group类型定义
  layout.layout	    表结构布局文件

  
  打包输出目录会产生几个子文件夹
  cpps    c++管理类
  csharp  c#管理类，另外附带测试工程
  data    二进制数据包
  info    版本迭代信息，数据更新删除等等产生的log
  lua     输出的lua数据
  lua_out pbc接口管理
  pbs     proto文件的二进制
  proto   proto文件
  sql     mysql文件

第四个sheet页为数据检测的配置
  1.每一行的第一个是定义检测的所在的excel文件 第二列是所在文件的sheet的名字
  检测语法
  表.列名  = [[ 条件， 条件，...] ,[ 条件， 条件，...] , ...]
  条件可以为
    表.列名             -- 在表里该列里查找数值
    数值                -- 可以为这个数值
    ?                   -- 任意
    枚举                -- 在定义枚举值中
    枚举.枚举值         -- 必须为枚举值
   
   
   具体检测方法可以查看check
   自定义类型的检测方法，需要自己编写。 
  
  
  
  
  
  



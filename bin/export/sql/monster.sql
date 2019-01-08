--------------------------------------------
---- table monster version:1.0.0.1 ----
--------------------------------------------
SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `monster`;
CREATE TABLE `monster`(
`id` varchar(512) NOT NULL DEFAULT '',
`group_float` json,
`group_string` json,
`job` varchar(255) NOT NULL DEFAULT '',
`level` int(11) NOT NULL DEFAULT '0',
`sub` int(11) NOT NULL DEFAULT '0',
`c1` json,
`c2` json,
`c3` json,
`c4` json,
`c5` json,
`c8` json,
`c6` tinyint(4) NOT NULL DEFAULT '0',
`c7` json,
`c9` json,
`c10` json,
`c11` json,
PRIMARY KEY(`id`),
UNIQUE KEY `job_level_sub` (`job`,`level`,`sub`) USING HASH
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
--------------------------------------
---- record formonster----------
--------------------------------------
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('1','[{"array":[1.2,2]},{"array":[2.1,3.1]},{"array":[4,4,4,4,4,4,4,4]}]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","4"]}]','common_0','1','1','{"y":0,"x":0,"o":0,"z":0}','[]','[]','[11,21]','[{"array":[11,12,13]},{"array":[11,12,14]}]','[true,false,true]','0','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":5,"value2":2,"value4":4,"value1":1,"value3":3}','[{"value5":0,"value2":2,"value4":0,"value1":1,"value3":3},{"value5":0,"value2":11,"value4":0,"value1":12,"value3":100}]','[{"array":[{"value5":0,"value2":0,"value4":0,"value1":1,"value3":0},{"value5":0,"value2":3,"value4":5,"value1":2,"value3":4},{"value5":0,"value2":0,"value4":0,"value1":1,"value3":0}]},{"array":[{"value5":5,"value2":2,"value4":4,"value1":1,"value3":3},{"value5":0,"value2":0,"value4":0,"value1":0,"value3":0}]}]');
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('3','[{"array":[1,2.3]}]','[]','common_0','3','2','{"y":0,"x":0,"o":0,"z":0}','[]','[{"array":[{"y":2,"x":1,"o":0,"z":3},{"y":2,"x":1,"o":0,"z":0}]},{"array":[{"y":0,"x":1,"o":0,"z":0},{"y":0,"x":3,"o":0,"z":0}]}]','[3]','[{"array":[11,12,13]},{"array":[11,12,16]}]','[true,false,true]','1','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":7,"value2":2,"value4":4,"value1":1,"value3":3}','[]','[]');
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('2','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","4"]}]','swordman_2','2','1','{"y":2,"x":1,"o":0,"z":3}','[{"y":2,"x":1,"o":0,"z":3},{"y":2,"x":1,"o":4,"z":3},{"y":2,"x":1,"o":0,"z":3}]','[{"array":[{"y":2,"x":1,"o":0,"z":3},{"y":2,"x":1,"o":0,"z":0}]},{"array":[{"y":0,"x":1,"o":0,"z":0},{"y":0,"x":2,"o":0,"z":0}]}]','[11,11,11,2]','[{"array":[11,12,13]},{"array":[11,12,15]}]','[true,true]','1','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":6,"value2":2,"value4":4,"value1":1,"value3":3}','[]','[]');
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('5','[{"array":[1,2]},{"array":[2,3]},{"array":[4,4,4,4,4,4,4,4]}]','[]','swordman_2','5','3','{"y":0,"x":0,"o":0,"z":0}','[]','[{"array":[{"y":2,"x":1,"o":0,"z":3},{"y":2,"x":1,"o":0,"z":0}]},{"array":[{"y":0,"x":1,"o":0,"z":0},{"y":0,"x":5,"o":0,"z":0}]}]','[1]','[{"array":[11,12,13]},{"array":[11,12,18]}]','[true,false,true]','1','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":9,"value2":2,"value4":4,"value1":1,"value3":3}','[]','[]');
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('4','[]','[]','swordman_2','4','2','{"y":0,"x":0,"o":0,"z":0}','[]','[{"array":[{"y":2,"x":1,"o":0,"z":3},{"y":2,"x":1,"o":0,"z":0}]},{"array":[{"y":0,"x":1,"o":0,"z":0},{"y":0,"x":4,"o":0,"z":0}]}]','[4]','[{"array":[11,12,13]},{"array":[11,12,17]}]','[true,false,true]','1','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":8,"value2":2,"value4":4,"value1":1,"value3":3}','[]','[]');
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('7','[{"array":[1,2]},{"array":[2,3]},{"array":[4.1,1.42,2.4,3.4,4.4,66.4,111.4,2222.4]}]','[]','swordman_2','7','5','{"y":0,"x":0,"o":0,"z":0}','[]','[{"array":[{"y":2,"x":1,"o":0,"z":3},{"y":2,"x":1,"o":0,"z":0}]},{"array":[{"y":0,"x":1,"o":0,"z":0},{"y":0,"x":7,"o":0,"z":0}]}]','[1]','[{"array":[11,12,13]},{"array":[11,12,20]}]','[true]','0','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":11,"value2":2,"value4":4,"value1":1,"value3":3}','[]','[]');
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('6','[{"array":[1,2]},{"array":[2,3]},{"array":[4.1,1.42,2.4,3.4,4.4,66.4,111.4,2222.4]}]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","4"]}]','swordman_2','6','4','{"y":0,"x":0,"o":0,"z":0}','[]','[{"array":[{"y":2,"x":1,"o":0,"z":3},{"y":2,"x":1,"o":0,"z":0}]},{"array":[{"y":0,"x":1,"o":0,"z":0},{"y":0,"x":6,"o":0,"z":0}]}]','[1]','[{"array":[11,12,13]},{"array":[11,12,19]}]','[true,false,true]','0','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":10,"value2":2,"value4":4,"value1":1,"value3":3}','[]','[]');
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('9','[{"array":[1,2]},{"array":[2,3]},{"array":[4.1,1.42,2.4,3.4,4.4,66.4,111.4,2222.4]}]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","4"]}]','swordman_2','9','3','{"y":0,"x":0,"o":0,"z":0}','[]','[{"array":[{"y":2,"x":1,"o":4,"z":3},{"y":2,"x":1,"o":0,"z":0}]},{"array":[{"y":0,"x":1,"o":0,"z":0},{"y":0,"x":9,"o":0,"z":0}]}]','[1]','[{"array":[11,12,13]},{"array":[11,12,22]}]','[true,false,true]','0','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":13,"value2":2,"value4":4,"value1":1,"value3":3}','[]','[]');
INSERT INTO `monster` (`id`,`group_float`,`group_string`,`job`,`level`,`sub`,`c1`,`c2`,`c3`,`c4`,`c5`,`c8`,`c6`,`c7`,`c9`,`c10`,`c11`) VALUES('8','[{"array":[1,2]},{"array":[2,3]},{"array":[4.1,1.42,2.4,3.4,4.4,66.4,111.4,2222.4]}]','[{"array":["\\\"aaaa\\\"","\\\"2.0\\\""]},{"array":["bbbbb","3.1"]},{"array":["ccc","4d","4f","43","4d","4d","4d","4d"]}]','swordman_2','8','4','{"y":0,"x":0,"o":0,"z":0}','[]','[{"array":[{"y":2,"x":1,"o":0,"z":3},{"y":2,"x":1,"o":0,"z":0}]},{"array":[{"y":0,"x":1,"o":0,"z":0},{"y":0,"x":8,"o":0,"z":0}]}]','[1]','[{"array":[11,12,13]},{"array":[11,12,21]}]','[true,false,true]','0','[{"array":[true,false]},{"array":[true,false]},{"array":[true,false]},{"array":[true,false]}]','{"value5":12,"value2":2,"value4":4,"value1":1,"value3":3}','[]','[]');

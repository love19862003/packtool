--------------------------------------------
---- table role version:1.0.0.1 ----
--------------------------------------------
SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `role`;
CREATE TABLE `role`(
`id` int(11) NOT NULL DEFAULT '0',
`group_float` json,
`group_string` json,
`camp` varchar(255) NOT NULL DEFAULT '',
`camp_array` json,
`camp_group` json,
`job` json,
`job2` json,
PRIMARY KEY(`id`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
--------------------------------------
---- record forrole----------
--------------------------------------
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('1','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","4"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('2','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","5"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('3','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","6"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('4','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","7"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('5','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","8"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('6','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","9"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('7','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","10"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('8','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","11"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('9','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","12"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('10','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","13"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('11','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","14"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('12','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","15"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('13','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","16"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('14','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","17"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('15','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","18"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('16','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","19"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('17','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","20"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');
INSERT INTO `role` (`id`,`group_float`,`group_string`,`camp`,`camp_array`,`camp_group`,`job`,`job2`) VALUES('18','[]','[{"array":["1.2","2.0"]},{"array":["2.1","3.1"]},{"array":["4","4","4","4","4","4","4","21"]}]','camp_dark','["camp_dark"]','[{"array":["camp_dark"]}]','["swordman_2"]','[{"array":["swordman_2"]}]');

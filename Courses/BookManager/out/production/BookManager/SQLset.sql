
--创建管理员表
CREATE TABLE uuser(
  id VARCHAR(255) NOT NULL,
  username VARCHAR(255) DEFAULT NULL,
  password VARCHAR(255) DEFAULT NULL,
  is_admin VARCHAR(255) DEFAULT NULL,
  PRIMARY KEY (id)
);

--插入管理员信息
INSERT INTO uuser VALUES ('1', 'admin', '123456', '是');

--创建图书表book
CREATE TABLE book (
  id VARCHAR(255) NOT NULL,
  bookname VARCHAR(255) DEFAULT NULL,
  booktype VARCHAR(255) DEFAULT NULL,
  author VARCHAR(255) DEFAULT NULL,
  translator VARCHAR(255) DEFAULT NULL,
  publisher VARCHAR(255) DEFAULT NULL,
  publish_time DATE DEFAULT NULL,
  price FLOAT DEFAULT NULL,
  num INT DEFAULT NULL,
  page INT DEFAULT NULL,
  PRIMARY KEY (id)
);

--插入图书信息
INSERT INTO book VALUES ('BH000001',	'航空航天概论',		'航空航天',	'贾玉红',		'无',		'北京航空航天大学出版社',	'2020-06-01', '49', '100', '300');
INSERT INTO book VALUES ('BH000002',	'JAVA编程思想',		'编程',		'Bruce Eckel',	'陈昊鹏',	'机械工业出版社',			'2020-06-01', '99', '100', '800');
INSERT INTO book VALUES ('BH000003',	'软件工程实用教程', '软件',		'吕云翔',		'无',		'清华大学出版社',			'2020-06-01', '49', '100', '300');
INSERT INTO book VALUES ('BH000004',	'数据库系统概论',	'数据库',	'王珊',			'无',		'高等教育出版社',			'2020-06-01', '42', '100', '200');

--创建读者表
CREATE TABLE reader (
  id  VARCHAR(255) NOT NULL,
  readername  VARCHAR(255) DEFAULT NULL,
  readertype  VARCHAR(255) DEFAULT NULL,
  sex  VARCHAR(255) DEFAULT NULL,
  max_num INT DEFAULT NULL,
  days_num INT DEFAULT NULL,
  PRIMARY KEY (id)
);

--插入读者信息
INSERT INTO reader VALUES ('R000001', '王嘉琦', '学生', '男', '10', '90');
INSERT INTO reader VALUES ('R000002', '马云龙', '学生', '男', '10', '60');
INSERT INTO reader VALUES ('R000003', '王嘉鑫', '学生', '男', '10', '30');

--创建借书表
CREATE TABLE borrow(
  id VARCHAR(255) NOT NULL,
  book_id VARCHAR(255) DEFAULT NULL,
  reader_id VARCHAR(255) DEFAULT NULL,
  borrow_date DATE DEFAULT NULL,
  back_date DATE DEFAULT NULL,
  if_back VARCHAR(255) DEFAULT NULL,
  PRIMARY KEY (id)
);

--插入借书信息
INSERT INTO borrow VALUES ('B000001', 'BH000001', 'R000001', '2020-06-01', '2020-06-02', '是');
INSERT INTO borrow VALUES ('B000002', 'BH000001', 'R000001', '2020-06-01', '2020-06-02', '否');
INSERT INTO borrow VALUES ('B000003', 'BH000002', 'R000002', '2020-06-01', '2020-06-02', '是');
INSERT INTO borrow VALUES ('B000004', 'BH000003', 'R000003', '2020-06-01', '2020-06-02', '是');



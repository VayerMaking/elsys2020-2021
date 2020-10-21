DROP DATABASE IF EXISTS MANY_TO_MANY;
CREATE DATABASE MANY_TO_MANY;
USE MANY_TO_MANY;

CREATE TABLE student(
  id int primary key not null auto_increment,
  name varchar(20)
);

CREATE TABLE shoe(
  id int primary key not null auto_increment,
  name varchar(20)
);

CREATE TABLE student_shoe(
  id int primary key not null auto_increment,
  shoe_id int,
  student_id int,
  FOREIGN KEY (shoe_id) REFERENCES shoe(id),
  FOREIGN KEY (student_id) REFERENCES student(id)
);

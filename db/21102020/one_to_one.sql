DROP DATABASE IF EXISTS ONE_TO_ONE;
CREATE DATABASE ONE_TO_ONE;
USE ONE_TO_ONE;

CREATE TABLE student(
  id int primary key not null auto_increment,
  name varchar(20)
);

CREATE TABLE shoe(
  id int primary key not null auto_increment,
  name varchar(20)
);

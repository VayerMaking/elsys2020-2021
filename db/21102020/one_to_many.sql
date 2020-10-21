DROP DATABASE IF EXISTS ONE_TO_MANY;
CREATE DATABASE ONE_TO_MANY;
USE ONE_TO_MANY;

CREATE TABLE student(
  id int primary key not null auto_increment,
  name varchar(20)
);

CREATE TABLE shoe(
  id int primary key not null auto_increment,
  name varchar(20),
  student_id int,
  FOREIGN KEY(student_id) REFERENCES Student(id)
);

INSERT INTO shoe

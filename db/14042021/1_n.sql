DROP DATABASE IF EXISTS zadanie7_1_n;
CREATE DATABASE zadanie7_1_n;
USE zadanie7_1_n;

CREATE TABLE Student(
  id int primary key auto_increment not null,
  name varchar(100)
);

CREATE TABLE Book(
  id int primary key auto_increment not null,
  name varchar(100),
  maker varchar(125),
  student_id int,
  FOREIGN KEY(student_id) REFERENCES Student(id),
  CONSTRAINT is_taken unique(name, maker)
);

DROP DATABASE IF EXISTS DNEVNIK;
CREATE DATABASE DNEVNIK;
USE DNEVNIK;

CREATE TABLE Student(
  id int not null primary key auto_increment,
  name varchar(100) not null,
	age int not null
);

CREATE TABLE Grades(
  id int not null primary key auto_increment,
  grade_name Enum('Bel', 'Math', 'Subd'),
  grade int not null default 2,
  CHECK(grade>=2),
  CHECK(grade<=6),
  student_id int,
	FOREIGN KEY(student_id) REFERENCES Student(id)
);

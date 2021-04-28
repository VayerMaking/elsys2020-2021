DROP DATABASE IF EXISTS zadanie7_n_n_unique;
CREATE DATABASE zadanie7_n_n_unique;
USE zadanie7_n_n_unique;

CREATE TABLE Student(
  id int primary key auto_increment not null,
  name varchar(100)
);

CREATE TABLE Computer(
  id int primary key auto_increment not null,
  name varchar(100)
);

CREATE TABLE StudentComputer(
  id int primary key auto_increment not null,
  student_id int,
  computer_id int,
  FOREIGN KEY(student_id) REFERENCES Student(id),
  FOREIGN KEY(computer_id) REFERENCES Computer(id),
  CONSTRAINT is_taken unique(student_id, computer_id)
)

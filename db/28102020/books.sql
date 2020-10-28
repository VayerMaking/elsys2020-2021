DROP DATABASE IF EXISTS LIBRARY;
CREATE DATABASE LIBRARY;
USE LIBRARY;

CREATE TABLE Owner(
  id int not null primary key auto_increment,
  name varchar(100) not null,
  age int not null
);

CREATE TABLE Book(
  id int not null primary key auto_increment,
  title varchar(30) not null,
  owner_id int,
  FOREIGN KEY(owner_id) REFERENCES Owner(id)
);

CREATE TABLE Author(
  id int not null primary key auto_increment,
  name varchar(100) not null,
  book_id int not null,
  FOREIGN KEY(book_id) REFERENCES Book(id)
);

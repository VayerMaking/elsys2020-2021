DROP DATABASE IF exists StoreDB;
CREATE DATABASE StoreDB;
USE StoreDB;

CREATE TABLE Person(
  id int primary key not null auto_increment,
  name varchar(100) unique
);

CREATE TABLE Item(
  id int primary key not null auto_increment,
  name varchar(100) unique,
  type Enum("Phone", "Tablet", "Laptop"),
  price float
);

CREATE TABLE Store(
  id int primary key not null auto_increment,
  created_at timestamp DEFAULT CURRENT_TIMESTAMP,
  person_id int not null,
  FOREIGN KEY(person_id) REFERENCES Person(id),
  item_id int not null,
  FOREIGN KEY(item_id) REFERENCES Item(id)
);

INSERT INTO Person(name) Values("Petko");
INSERT INTO Person(name) Values("Goshko");
INSERT INTO Person(name) Values("Andromed");

INSERT INTO Item(name, type, price) Values("iphone 5 s", "Phone", 1000.00);
INSERT INTO Item(name, type, price) Values("microsoft surface go", "Laptop", 2560.00);
INSERT INTO Item(name, type, price) Values("macbook air 2020 M1", "Laptop", 4444.00);
INSERT INTO Item(name, type, price) Values("ipad air 2020", "Tablet", 1222.00);
INSERT INTO Item(name, type, price) Values("xioami mi 10t pro", "Phone", 999.00);

INSERT INTO Store(person_id, item_id) Values(1, 3);
INSERT INTO Store(person_id, item_id) Values(2, 5);
INSERT INTO Store(person_id, item_id) Values(1, 1);
INSERT INTO Store(person_id, item_id) Values(1, 2);
INSERT INTO Store(person_id, item_id) Values(1, 5);
INSERT INTO Store(person_id, item_id) Values(2, 1);
INSERT INTO Store(person_id, item_id) Values(2, 3);
INSERT INTO Store(person_id, item_id) Values(2, 5);
INSERT INTO Store(person_id, item_id) Values(1, 3);
INSERT INTO Store(person_id, item_id) Values(2, 3);

--select everyone that has bought something
SELECT p.name
FROM Person p
JOIN Store s ON p.id=s.person_id
JOIN Item i ON s.item_id=i.id
GROUP BY p.name;

--select everything that has been bought atleeast once
SELECT i.name
FROM Person p
JOIN Store s ON p.id=s.person_id
JOIN Item i ON s.item_id=i.id
GROUP BY i.name;

DROP DATABASE IF exists WeightDB;
CREATE DATABASE WeightDB;
USE WeightDB;

CREATE TABLE Person(
  id int primary key not null auto_increment,
  name varchar(100),
  age tinyint,
  height int,
  gender Enum("Female", "Male"),
  average_weight float,
  count_weight int DEFAULT 0
);

CREATE TABLE Weight(
  id int primary key not null auto_increment,
  person_id int not null,
  FOREIGN KEY(person_id) REFERENCES Person(id),
  value float not null,
  created_at timestamp DEFAULT CURRENT_TIMESTAMP
);

DELIMITER $$

CREATE TRIGGER update_count_weight
  BEFORE INSERT
  ON Weight FOR EACH ROW

BEGIN
  UPDATE Person
  SET count_weight = (
    SELECT COUNT(count_weight) FROM Weight
    WHERE person_id = NEW.person_id
  )
  WHERE Person.id = NEW.person_id;

END$$

DELIMITER ;

INSERT INTO Person(name, age, height, gender) Values("Misho", 23, 150, "Male");
INSERT INTO Person(name, age, height, gender) Values("Mimi", 24, 160, "Female");

INSERT INTO Weight(person_id, value) Values(1, 70);
INSERT INTO Weight(person_id, value) Values(1, 72);
INSERT INTO Weight(person_id, value) Values(1, 70);
INSERT INTO Weight(person_id, value) Values(1, 72);
INSERT INTO Weight(person_id, value) Values(2, 52);
INSERT INTO Weight(person_id, value) Values(2, 50);
INSERT INTO Weight(person_id, value) Values(2, 52);
INSERT INTO Weight(person_id, value) Values(2, 53);

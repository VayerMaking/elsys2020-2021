DROP DATABASE IF EXISTS kantar;
CREATE DATABASE kantar;
USE kantar;

CREATE TABLE Person(
  id int primary key auto_increment not null,
  name varchar(100),
  gender Enum("M", "F"),
  age int,
  CHECK(age>0)
);

CREATE TABLE Weight_Data(
  id int primary key auto_increment not null,
  created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  weight float NOT NULL,
  person_id int,
  FOREIGN KEY(person_id) REFERENCES Person(id)
);

INSERT INTO Person(name, gender, age) VALUES("Ahron", "M", 18);
INSERT INTO Person(name, gender, age) VALUES("Penka", "F", 16);

INSERT INTO Weight_Data(weight, person_id) VALUES(70, 1);
INSERT INTO Weight_Data(weight, person_id) VALUES(45, 2);
INSERT INTO Weight_Data(weight, person_id) VALUES(72, 1);
INSERT INTO Weight_Data(weight, person_id) VALUES(43, 2);
INSERT INTO Weight_Data(weight, person_id) VALUES(74, 1);
INSERT INTO Weight_Data(weight, person_id) VALUES(42, 2);

SELECT avg(weight) FROM Weight_Data WHERE person_id = 1 AND created_at LIKE '2019-02-%';

SELECT avg(weight)
FROM Weight_Data
LEFT JOIN Person ON Person.id = Weight_Data.person_id
WHERE Person.gender = "F";

SELECT DISTINCT Person.name AS "Nai-debel"
FROM Weight_Data
LEFT JOIN Person ON Person.id = Weight_Data.person_id
WHERE Person.gender = "M" AND created_at >= "2021-03-01" AND created_at <= "2021-04-01";

SELECT gender, count(weight)
FROM Weight_Data
LEFT JOIN Person ON Person.id = Weight_Data.person_id
GROUP BY Person.gender;

SELECT name, avg(weight)
FROM Weight_Data
LEFT JOIN Person ON Person.id = Weight_Data.person_id
GROUP BY Person.name;

-- SELECT weight
-- FROM Weight_Data WHERE (created_at) IN
-- ( SELECT MAX(created_at)
--   FROM Weight_Data
--   GROUP BY person_id
-- ) and person_id = 1
-- (created_at) in
-- (SELECT min(created_at)
--   FROM Weight_Data
--   GROUP BY person_id;

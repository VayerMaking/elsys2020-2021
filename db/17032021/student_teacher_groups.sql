DROP DATABASE IF EXISTS student_teacher_groups;
CREATE DATABASE student_teacher_groups;
USE student_teacher_groups;

CREATE TABLE Groups(
  id int primary key auto_increment not null,
  name varchar(100),
  first_meeting TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Partisipant(
  id int primary key auto_increment not null,
  name varchar(100),
  type Enum("Student", "Teacher"),
  group_id int,
  FOREIGN KEY(group_id) REFERENCES Groups(id)
);

INSERT INTO Groups(name) VALUES("asdf 1");
INSERT INTO Groups(name) VALUES("asdf 2");
INSERT INTO Groups(name) VALUES("asdf 3");

INSERT INTO Partisipant(name, type, group_id) VALUES("Pencho", "Student", 1);
INSERT INTO Partisipant(name, type, group_id) VALUES("Andromed", "Student", 1);
INSERT INTO Partisipant(name, type, group_id) VALUES("gn Ivanov", "Teacher", 1);

INSERT INTO Partisipant(name, type, group_id) VALUES("gn Petrov", "Teacher", 2);

SELECT Groups.name AS "Group Name", Partisipant.name AS "Partisipant Name", Partisipant.type AS "Type"
FROM Groups LEFT JOIN Partisipant
ON Groups.id = Partisipant.group_id;

SELECT Groups.name AS "Group Name" , count(Partisipant.group_id) AS "People in Group"
FROM Groups
LEFT JOIN Partisipant ON Groups.id = Partisipant.group_id
GROUP BY Partisipant.group_id
ORDER BY Groups.name;

SELECT Groups.name AS "Group Name" , count(Partisipant.group_id) AS "Students in Group"
FROM Groups
LEFT JOIN Partisipant ON Groups.id = Partisipant.group_id
WHERE Partisipant.type = "Student"
GROUP BY Partisipant.group_id
ORDER BY Groups.name;

SELECT Groups.name AS "Group Name" , count(Partisipant.group_id) AS "Teachers in Group"
FROM Groups
LEFT JOIN Partisipant ON Groups.id = Partisipant.group_id
WHERE Partisipant.type = "Teacher"
GROUP BY Partisipant.group_id
ORDER BY Groups.name;

SELECT name AS "Group Name", first_meeting AS "First Meeting"
FROM Groups
WHERE first_meeting >= "2010-10-10 00:00:00" AND first_meeting <= "2011-11-11 23:59:59";

DROP DATABASE IF EXISTS better_classbook;
CREATE DATABASE better_classbook;
USE better_classbook;

CREATE TABLE Student(
  id int primary key auto_increment not null,
  name varchar(100) ,
  age int,
  CHECK(age>0)
);

CREATE TABLE Grades(
  id int primary key auto_increment not null,
  grade_name ENUM('BEL', 'MATH', 'SUBD'),
  grade int DEFAULT 2,
  CHECK(grade>=2 && grade<=6),
  student_id int,
  FOREIGN KEY(student_id) REFERENCES Student(id)
);

INSERT INTO Student(name, age) VALUES("Ahron", 18);
INSERT INTO Student(name, age) VALUES("Hadir", 16);
INSERT INTO Student(name, age) VALUES("Zimbab", 15);
INSERT INTO Student(name, age) VALUES("ALEX", 15);
INSERT INTO Student(name, age) VALUES("Ping Pong", 69);

INSERT INTO Grades(grade_name, grade, student_id) VALUES("BEL", 3, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("BEL", 2, 2);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("BEL", 3, 3);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("MATH", 4, 4);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("MATH", 5, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("SUBD", 6, 1);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("SUBD", 6, 2);
INSERT INTO Grades(grade_name, grade, student_id) VALUES("SUBD", 5, 2);

SELECT * FROM Student;
SELECT * FROM Grades;

SELECT AVG(grade) AS AverageGrade FROM Grades;

SELECT AVG(grade) AS AverageGradeOfStudentWithId1 FROM Grades WHERE student_id = 1;

SELECT DISTINCT Student.name AS StudentWhoHaveGradeInSUBDBetween4And6
FROM Student
LEFT JOIN Grades ON Student.id = Grades.student_id
WHERE Grades.grade_name = "SUBD" AND Grades.grade BETWEEN 4 AND 6;

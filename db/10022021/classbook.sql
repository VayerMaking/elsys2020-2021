DROP DATABASE IF EXISTS classbook;
CREATE DATABASE classbook;
USE classbook;

CREATE TABLE Student(
    id int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name varchar(100) not null,
    age int,
    CHECK(age>0)
);

CREATE TABLE Grades(
    id int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    grade_bg int DEFAULT 2 NOT NULL,
    grade_math int DEFAULT 2 NOT NULL,
    grade_subd int DEFAULT 2 NOT NULL,
    CHECK(grade_bg>=2 && grade_bg<=6),
    CHECK(grade_math>=2 && grade_math<=6),
    CHECK(grade_subd>=2 && grade_subd<=6),
    student_id int,
    FOREIGN KEY(student_id) REFERENCES Student(id)
);

INSERT INTO Student(name, age) VALUES("Ahron", 18);
INSERT INTO Student(name, age) VALUES("Hadir", 16);
INSERT INTO Student(name, age) VALUES("Zimbab", 15);
INSERT INTO Student(name, age) VALUES("ALEX", 15);
INSERT INTO Student(name, age) VALUES("Ping Pong", 69);

INSERT INTO Grades(grade_bg, grade_math, grade_subd, student_id) VALUES(5,6,6,1);
INSERT INTO Grades(grade_bg, grade_math, grade_subd, student_id) VALUES(4,4,4,2);
INSERT INTO Grades(grade_bg, grade_math, grade_subd, student_id) VALUES(3,4,3,3);
INSERT INTO Grades(grade_bg, grade_math, grade_subd, student_id) VALUES(3,4,3,4);
INSERT INTO Grades(grade_bg, grade_math, grade_subd, student_id) VALUES(3,4,4,5);

SELECT Student.name, Grades.grade_bg, Grades.grade_math, Grades.grade_subd 
FROM Student 
LEFT JOIN Grades ON Student.id = Grades.student_id 
WHERE name = "ALEX";

SELECT Student.name, Grades.grade_bg, Grades.grade_math, Grades.grade_subd
FROM Student 
LEFT JOIN Grades ON Student.id = Grades.student_id
WHERE name LIKE '%a%';

SELECT Student.name, Grades.grade_bg, Grades.grade_math, Grades.grade_subd 
FROM Student 
LEFT JOIN Grades ON Student.id = Grades.student_id 
WHERE ((grade_bg + grade_math + grade_subd)/3) > 5;

SELECT Student.name, Grades.grade_bg, Grades.grade_math, Grades.grade_subd 
FROM Student 
LEFT JOIN Grades ON Student.id = Grades.student_id 
WHERE ((grade_bg + grade_math)/2) > 5;


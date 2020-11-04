--average grades
SELECT AVG(grade) AS AverageGrades FROM Grades;
--average grades of student with id=1
SELECT AVG(grade) FROM Grades WHERE Grades.student_id = 1;
-- average by subjects
SELECT AVG(grade) AS MathAverage FROM Grades WHERE Grades.grade_name = 'Math';
SELECT AVG(grade) AS BelAverage FROM Grades WHERE Grades.grade_name = 'Bel';
SELECT AVG(grade) AS SUBDAverage FROM Grades WHERE Grades.grade_name = 'Subd';

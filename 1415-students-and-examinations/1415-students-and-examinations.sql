# Write your MySQL query statement below
#SELECT *
SELECT S.student_id, S.student_name, SB.subject_name, COUNT(E.student_id) AS attended_exams
FROM Students S
CROSS JOIN Subjects SB
LEFT JOIN Examinations E ON E.student_id = S.student_id AND E.subject_name = SB.subject_name
GROUP BY S.student_id, SB.subject_name
ORDER BY S.student_id, SB.subject_name
# Write your MySQL query statement below
SELECT T.teacher_id, COUNT(DISTINCT(T.subject_id)) AS cnt
FROM
Teacher T
GROUP BY T.teacher_id
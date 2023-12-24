# Write your MySQL query statement below
SELECT
    s.student_id, s.student_name, su.subject_name, COUNT(e.subject_name) AS "attended_exams"
FROM
    Students s
CROSS JOIN
    Subjects su
LEFT JOIN
    Examinations e
ON
    su.subject_name = e.subject_name AND e.student_id = s.student_id
GROUP BY
    s.student_id, su.subject_name  # wrong answer s.student_id, e.subject_name -> e can't express null attribute
ORDER BY
    s.student_id, su.subject_name  ASC; # wrong anwer s.id before su.subject_name
#ORDER BY
#    E.subject_name ASC;
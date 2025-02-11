SELECT
    S.student_id,
    S.student_name,
    SU.subject_name,
    COUNT(E.student_id) as 'attended_exams'
FROM
    Students S
CROSS JOIN Subjects SU
LEFT JOIN
    Examinations E 
    ON SU.subject_name = E.subject_name
    AND S.student_id = E.student_id 
GROUP BY SU.subject_name, S.student_id
ORDER BY S.student_id, SU.subject_name ASC


# S.student_id
# E.student_id
# E.subject_name
# SU.subject_name

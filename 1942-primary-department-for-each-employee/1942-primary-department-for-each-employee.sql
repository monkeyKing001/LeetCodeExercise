# Write your MySQL query statement below
SELECT E.employee_id, E.department_id
FROM Employee E
WHERE E.primary_flag = 'Y' OR employee_id IN (
    SELECT EE.employee_id 
    FROM Employee EE
    GROUP BY EE.employee_id
    HAVING (COUNT(EE.employee_id) = 1)
    )
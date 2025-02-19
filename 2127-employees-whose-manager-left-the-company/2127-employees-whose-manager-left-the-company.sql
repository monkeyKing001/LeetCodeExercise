# Write your MySQL query statement below
#SELECT *
SELECT E.employee_id
FROM Employees E
LEFT JOIN Employees EE ON E.manager_id = EE.employee_id
WHERE E.salary < 30000 AND E.manager_id IS NOT NULL AND EE.employee_id IS NULL
ORDER BY E.employee_id
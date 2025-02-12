# Write your MySQL query statement below
SELECT E.employee_id
FROM Employees E
LEFT JOIN Employees EE ON E.manager_id = EE.employee_id
WHERE EE.employee_id IS NULL AND E.manager_id IS NOT NULL AND E.salary < 30000
ORDER BY E.employee_id ASC
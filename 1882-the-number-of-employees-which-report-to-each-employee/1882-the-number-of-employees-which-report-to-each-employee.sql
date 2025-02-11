# Write your MySQL query statement below
SELECT 
    E1.employee_id,
    E1.name,
    count(E2.employee_id) as 'reports_count',
    ROUND(SUM(E2.age) / count(E2.employee_id)) as 'average_age'
FROM Employees E1
LEFT JOIN Employees E2 ON E1.employee_id = E2.reports_to
WHERE E2.employee_id IS NOT NULL
GROUP BY E1.employee_id
ORDER BY E1.employee_id
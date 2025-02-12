# Write your MySQL query statement below
#Employee
#Project
SELECT P.project_id, ROUND(SUM(E.experience_years) / COUNT(p.project_id), 2) AS average_years
#SELECT P.project_id, SUM() AS average_years
FROM Project P
LEFT JOIN Employee E ON E.employee_id = P.employee_id
GROUP BY project_id

# Write your MySQL query statement below
SELECT 
E.name AS Employee
FROM
Employee E
INNER JOIN Employee EE ON E.managerId = EE.id
WHERE E.salary > EE.salary
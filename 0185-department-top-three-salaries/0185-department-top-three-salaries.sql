# Write your MySQL query statement below
SELECT D.name AS 'Department', E.name AS 'Employee', E.salary AS 'Salary'
FROM Employee E
INNER JOIN Department D ON E.departmentId = D.id
WHERE 3 > (
    SELECT COUNT(DISTINCT(EE.salary))
    FROM Employee EE
    WHERE EE.departmentId = E.departmentId AND EE.salary > E.salary
)
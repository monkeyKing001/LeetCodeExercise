# Write your MySQL query statement below
SELECT EmployeeUNI.unique_id AS unique_id, Employees.name
FROM Employees
LEFT JOIN EmployeeUNI on EmployeeUNI.id = Employees.id

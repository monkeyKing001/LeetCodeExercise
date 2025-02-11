SELECT E.name, B.bonus
FROM Employee E
LEFT JOIN Bonus B ON B.empId = E.empId
WHERE bonus IS NULL OR bonus < 1000

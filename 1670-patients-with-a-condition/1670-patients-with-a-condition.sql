# Write your MySQL query statement below
SELECT *
FROM Patients P
WHERE P.conditions LIKE "DIAB1%" OR P.conditions LIKE "% DIAB1%"
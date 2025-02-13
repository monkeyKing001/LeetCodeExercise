# Write your MySQL query statement below
DELETE P
FROM Person P
INNER JOIN Person PP ON P.email = PP.email AND P.id > PP.id
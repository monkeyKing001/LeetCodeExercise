# Write your MySQL query statement below
SELECT U.user_id, CONCAT(UCASE(SUBSTR(U.name, 1, 1)), LCASE(SUBSTR(U.name, 2)))as name
FROM Users U
ORDER BY U.user_id

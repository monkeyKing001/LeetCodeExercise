# Write your MySQL query statement below
SELECT MAX(MM.num) AS num
FROM (
    SELECT M.num
    FROM MyNumbers M
    GROUP BY M.num
    HAVING COUNT(num) = 1
    ORDER BY num DESC
    LIMIT 1
) as MM
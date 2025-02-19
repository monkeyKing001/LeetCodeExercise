# Write your MySQL query statement below
SELECT
R.contest_id, 
ROUND(COUNT(U.user_id) * 100 / (
    SELECT COUNT(UU.user_id)
    FROM Users UU
    ), 2) AS percentage
FROM Register R
LEFT JOIN Users U ON U.user_id = R.user_id
GROUP BY R.contest_id
ORDER BY percentage DESC, R.contest_id ASC
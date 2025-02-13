# Write your MySQL query statement below
SELECT L.user_id, MAX(L.time_stamp) AS 'last_stamp'
FROM Logins L
WHERE L.time_stamp LIKE '2020%' 
GROUP BY L.user_id
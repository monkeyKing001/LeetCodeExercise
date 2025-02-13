# Write your MySQL query statement below
SELECT L.user_id, L.time_stamp AS 'last_stamp'
FROM Logins L
WHERE DATEDIFF(L.time_stamp, '2020-01-01') >= 0 
    AND DATEDIFF(L.time_stamp, '2021-01-01') < 0
    AND (
        SELECT COUNT(*)
        FROM Logins LL
        WHERE LL.user_id = L.user_id
        AND L.time_stamp < LL.time_stamp
        AND DATEDIFF(LL.time_stamp, '2020-01-01') >= 0 
        AND DATEDIFF(LL.time_stamp, '2021-01-01') < 0
    ) = 0
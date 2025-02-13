# Write your MySQL query statement below
SELECT A.activity_date AS 'day', COUNT(DISTINCT(A.user_id)) AS 'active_users'
FROM (
        SELECT *
        FROM Activity AA
        WHERE DATEDIFF(AA.activity_date, '2019-07-27') <= 0 AND DATEDIFF('2019-07-27', AA.activity_date) < 30
    ) AS A
GROUP BY activity_date

#COUNT(CASE WHEN (activity_type != 'end_session' AND DATEDIFF('2019-07-27', A.activity_date) <= 30 THEN 1 ELSE 0 END) AS day active_users
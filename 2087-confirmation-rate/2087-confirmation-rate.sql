# Write your MySQL query statement below
SELECT
    S.user_id,
    CASE WHEN C.user_id IS NOT NULL THEN
    (
        ROUND
        (
            COUNT(CASE WHEN C.action ='confirmed' THEN 1 ELSE NULL END) / 
            COUNT(C.action),
            2
        )
    )
    ELSE
    0.00
    END AS confirmation_rate
FROM Signups S
LEFT JOIN Confirmations C ON S.user_id = C.user_id
GROUP BY S.user_id
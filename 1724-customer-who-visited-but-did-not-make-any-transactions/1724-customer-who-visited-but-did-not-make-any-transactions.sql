# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.customer_id) AS 'count_no_trans'
FROM Visits V
LEFT JOIN Transactions t ON v.visit_id = t.visit_id #AND transaction_id IS NULL
WHERE T.transaction_id IS NULL
GROUP BY v.customer_id
ORDER BY v.visit_id

#debug sql
#SELECT *
#FROM Visits V
#LEFT JOIN Transactions t ON v.visit_id = t.visit_id #AND transaction_id IS NULL
#WHERE T.transaction_id IS NULL
#GROUP BY v.customer_id
#ORDER BY v.visit_id
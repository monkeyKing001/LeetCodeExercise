# Write your MySQL query statement below
SELECT
    customer_id, COUNT(V.visit_id) AS "count_no_trans"
FROM
    Visits AS V
LEFT JOIN
    Transactions AS T
ON
    T.visit_id = V.visit_id
WHERE
    T.transaction_id IS NULL
GROUP BY
    customer_id;
   
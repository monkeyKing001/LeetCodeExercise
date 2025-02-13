# Write your MySQL query statement below
#SELECT *
SELECT P.product_name, SUM(O.unit) AS unit
FROM (
    SELECT *
    FROM Orders OO
    WHERE DATEDIFF(OO.order_date, '2020-02-01') >= 0 AND DATEDIFF(OO.order_date, '2020-03-01') < 0 
) AS O
INNER JOIN Products P ON P.product_id = O.product_id
GROUP BY O.product_id
HAVING SUM(O.unit) >= 100
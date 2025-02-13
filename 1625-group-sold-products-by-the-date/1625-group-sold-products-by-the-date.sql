# Write your MySQL query statement below
SELECT A.sell_date, COUNT(DISTINCT(A.product)) AS 'num_sold', GROUP_CONCAT(DISTINCT product ORDER BY product ASC SEPARATOR ',') AS 'products'
FROM Activities A
GROUP BY A.sell_date
ORDER BY A.sell_date ASC
# Write your MySQL query statement below
#UnitsSold
#Prices
#SELECT *, ROUND(SUM(P.price * U.units) / SUM(U.units), 2) AS average_price 
SELECT P.product_id, IF(COUNT(U.product_id) != 0, ROUND(SUM(P.price * U.units) / SUM(U.units), 2), 0) AS average_price 
FROM Prices P
LEFT JOIN UnitsSold U
    ON P.product_id = U.product_id 
    AND datediff(U.purchase_date, P.start_date) >= 0
    AND datediff(P.end_date, U.purchase_date) >= 0
GROUP BY
    P.product_id
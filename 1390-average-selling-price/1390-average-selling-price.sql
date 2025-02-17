# Write your MySQL query statement below
#SELECT *
SELECT P.product_id,
    CASE WHEN COUNT(U.units) != 0
    THEN ROUND(SUM(P.price * U.units)/ SUM(U.units), 2) 
    ELSE 0 END AS average_price
FROM Prices P
LEFT JOIN UnitsSold U 
    ON P.product_id = U.product_id
    AND DATEDIFF(U.purchase_date, P.start_date) >= 0 AND DATEDIFF(P.end_date, U.purchase_date) >= 0
GROUP BY P.product_id
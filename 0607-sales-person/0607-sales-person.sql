# Write your MySQL query statement below
#SELECT *
SELECT S.name
FROM SalesPerson S
LEFT JOIN Orders O ON O.sales_id = S.sales_id
LEFT JOIN Company C On O.com_id = C.com_id 
GROUP BY S.sales_id 
HAVING COUNT(CASE WHEN C.name = "RED" THEN 1 ELSE NULL END) < 1
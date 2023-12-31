SELECT
p.product_name, year, price
FROM
Sales s
Join
Product p 
ON
p.product_id = s.product_id;

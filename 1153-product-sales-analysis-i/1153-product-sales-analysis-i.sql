SELECT
    p.product_name, s.year, s.price
FROM
    Product p
INNER JOIN Sales s on p.product_id = s.product_id 
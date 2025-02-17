# Write your MySQL query statement below
#SELECT query_name, ROUND(AVG(Q.rating / Q.position), 2) AS quality
SELECT Q.query_name, ROUND(AVG(Q.rating / Q.position), 2) AS quality, ROUND(COUNT(CASE WHEN Q.rating < 3 THEN 1 ELSE NULL END) * 100 / COUNT(Q.rating), 2) AS poor_query_percentage
FROM Queries Q
GROUP BY Q.query_name
# Write your MySQL query statement below
#SELECT S.score, (SELECT COUNT(DISTINCT(SS.score)) FROM Scores SS WHERE SS.score >= S.score) AS 'rank'
#FROM Scores S
#ORDER BY S.score DESC


# Write your MySQL query statement below
SELECT score,
DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank' 
FROM Scores
SELECT w2.id as Id
FROM Weather w1
LEFT JOIN Weather w2 ON DATEDIFF(w2.recordDate, w1.recordDate) = 1
WHERE w2.temperature > w1.temperature

#debug sql
#SELECT *
#FROM Weather w1
#LEFT JOIN Weather w2 ON DATEDIFF(w2.recordDate, w1.recordDate) = 1
#WHERE w2.recordDate + 1 = w1.recordDate AND w2.temperature > w1.temperature
#WHERE DATEDIFF(w2.recordDate, w1.recordDate) = 1 #AND w2.temperature > w1.temperature
#WHERE w2.temperature > w1.temperature
# Write your MySQL query statement below
SELECT
    W1.id#, W1.recordDate, W1.temperature
FROM
    Weather W1
INNER JOIN
    Weather W2
ON
    DATEDIFF(W1.recordDate, W2.recordDate) = 1
WHERE
    W1.temperature > W2.temperature
   
    
    

  
    
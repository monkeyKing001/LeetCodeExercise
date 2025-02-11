SELECT
A1.machine_id, ROUND(SUM(A2.timestamp - A1.timestamp) / COUNT(A1.process_id), 3) as 'processing_time'
FROM
Activity A1
INNER JOIN
Activity A2 
    ON A1.machine_id = A1.machine_id 
WHERE 
    A2.machine_id = A1.machine_id 
    AND A2.process_id = A1.process_id 
    AND A1.activity_type = 'start' 
    AND A2.activity_type = 'end'
GROUP BY A1.machine_id
ORDER BY machine_id
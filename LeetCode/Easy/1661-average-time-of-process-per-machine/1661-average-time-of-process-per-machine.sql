# Write your MySQL query statement below
SELECT
    A1.machine_id, ROUND(AVG(A2.timestamp - A1.timestamp), 3) as processing_time
FROM
    Activity A1
INNER JOIN
    Activity A2
ON 
    A1.machine_id = A2.machine_id 
    AND A1.process_id = A2.process_id 
    AND A1.activity_type = 'start'
    AND A2.activity_type = 'end'
GROUP BY
    A1.machine_id

































#SELECT
#    a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time
#    #a1.machine_id, a1,timestamp, a2.machine_id, a2.timestamp
#FROM
#    Activity AS a1,
#    Activity AS a2
#WHERE 
#    a1.machine_id = a2.machine_id
#AND
#    a1.process_id = a2.process_id
#AND
#    a1.activity_type = 'start' AND a2.activity_type = 'end'
#GROUP BY
#    a1.machine_id;
#  分组查询
SELECT Email   
    FROM Person  
    GROUP BY Email   
    HAVING COUNT(Email)>1; 

SELECT Email   
    FROM Person  
    GROUP BY Email   
    HAVING COUNT(*)>1;  


# Jion语句

SELECT DISTINCT a.Email   
    FROM Person a  
    JOIN Person b  
    ON a.Email=b.Email  
    where a.id!=b.id; 


# 子查询
# Write your MySQL query statement below  
SELECT DISTINCT a.Email  
FROM Person a  
WHERE EXISTS(  
    SELECT 1  
    FROM Person b  
    WHERE a.Email = b.Email  
    LIMIT 1, 1  
);  


# 左外连接
SELECT DISTINCT a.Email FROM Person a  
LEFT JOIN (SELECT Id, Email from Person GROUP BY Email) b  
ON (a.email = b.email) AND (a.Id = b.Id)  
WHERE b.Email IS NULL   
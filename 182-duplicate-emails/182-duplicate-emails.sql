# Write your MySQL query statement below

Select email AS Email from Person group by email having count(email)>1;
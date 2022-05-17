# Write your MySQL query statement below

select T1.name AS Employee  from Employee T1 , Employee T2 where T1.managerId=T2.id and T1.salary>T2.salary


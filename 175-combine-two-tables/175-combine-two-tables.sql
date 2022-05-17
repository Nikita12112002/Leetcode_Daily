# Write your MySQL query statement below

select Person.firstName , Person.lastName , Address.city ,Address.state
from Person left join Address on person.personId=Address.personId;

# SELECT Person.FirstName, Person.LastName, Address.City, Address.State from Person LEFT JOIN Address on Person.PersonId = Address.PersonId;
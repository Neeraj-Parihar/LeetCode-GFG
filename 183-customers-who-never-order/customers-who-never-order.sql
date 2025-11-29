-- Write your PostgreSQL query statement below

select name As "Customers" from Customers where id NOT IN (select customerId from Orders where customerId is NOT NULL);
# Write your MySQL query statement below
with 
t as (
    select departmentId
        , max(salary) as salary 
    from Employee 
    group by departmentId
)
,m as (
    select t.departmentId
        ,name
        ,t.salary 
    from t join Department 
    on t.departmentId = Department.id
)

select m.name as Department
    ,Employee.name as Employee
    ,m.salary as Salary
from m, Employee     
where m.departmentId = Employee.departmentId 
    and m.salary = Employee.salary

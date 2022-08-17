select name 
from SalesPerson
where sales_id not in ( 
    select SalesPerson.sales_id 
    from SalesPerson join Company join Orders
    on SalesPerson.sales_id=Orders.sales_id and Company.com_id=Orders.com_id
    where Company.name="RED"
)
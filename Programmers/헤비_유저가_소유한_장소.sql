select *
from places 
where host_id in (
    select host_id
    from places
    group by host_id
    having count(id)>1
)
order by id
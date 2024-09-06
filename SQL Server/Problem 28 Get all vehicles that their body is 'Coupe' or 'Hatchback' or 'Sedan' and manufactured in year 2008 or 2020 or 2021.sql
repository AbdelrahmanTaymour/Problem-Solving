
--Problem 28 Get all vehicles that their body is 'Coupe' or 'Hatchback' or 'Sedan' and manufactured in year 2008 or 2020 or 2021

SELECT       bodyName, VehicleDetails.*
FROM            VehicleDetails INNER JOIN
                         Bodies ON VehicleDetails.BodyID = Bodies.BodyID
Where BodyName in ('Coupe','Hatchback','Sedan') and Year in ( 2008, 2020, 2021)
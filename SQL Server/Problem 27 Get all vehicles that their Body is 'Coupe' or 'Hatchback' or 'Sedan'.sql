
-- Problem 27: Get all vehicles that their Body is 'Coupe' or 'Hatchback' or 'Sedan'

SELECT       bodyName, VehicleDetails.*
FROM            VehicleDetails INNER JOIN
                         Bodies ON VehicleDetails.BodyID = Bodies.BodyID
Where BodyName in ('Coupe','Hatchback','Sedan')

--Problem 26 Get all vehicles that their body is 'Sport Utility' and Year > 2020

SELECT		Bodies.BodyName, VehicleDetails.*
FROM		VehicleDetails INNER JOIN
				Bodies ON VehicleDetails.BodyID = Bodies.BodyID
WHERE	Bodies.BodyName = 'Sport Utility' AND YEAR > 2020
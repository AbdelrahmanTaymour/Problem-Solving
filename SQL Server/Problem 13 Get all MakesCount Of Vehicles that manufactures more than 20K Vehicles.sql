
--Problem 13: Get all Makes/Count Of Vehicles that manufactures more than 20K Vehicles

SELECT		Makes.Make,COUNT(*) AS NumberOfVehicles
FROM		VehicleDetails INNER JOIN Makes ON VehicleDetails.MakeID = Makes.MakeID
GROUP BY Makes.Make
Having COUNT(*) > 20000
ORDER BY NumberOfVehicles DESC
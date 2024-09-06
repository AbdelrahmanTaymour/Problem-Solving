
--Problem 12 Count Vehicles by make and order them by NumberOfVehicles from high to low.

SELECT		Makes.Make,COUNT(*) AS NumberOfVehicles
FROM		VehicleDetails INNER JOIN Makes ON VehicleDetails.MakeID = Makes.MakeID
GROUP BY Makes.Make
ORDER BY NumberOfVehicles DESC

-- Problem 8 Get Make, FuelTypeName and Number of Vehicles per FuelType per Make

Select	Makes.Make, FuelTypes.FuelTypeName, COUNT(*) AS NumberOfVehicles
FROM	VehicleDetails INNER JOIN
			Makes ON VehicleDetails.MakeID = Makes.MakeID INNER JOIN
				FuelTypes ON VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
	
WHERE	(VehicleDetails.Year BETWEEN 1950 AND 2000)
GROUP BY Makes.Make, FuelTypes.FuelTypeName
ORDER BY Makes.Make;

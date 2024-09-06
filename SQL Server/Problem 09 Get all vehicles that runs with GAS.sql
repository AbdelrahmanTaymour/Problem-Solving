
--Problem 9: Get all vehicles that runs with GAS

SELECT  VehicleDetails.*, FuelTypes.FuelTypeName
FROM		VehicleDetails INNER JOIN FuelTypes ON FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID
WHERE		(FuelTypes.FuelTypeName = N'GAS')

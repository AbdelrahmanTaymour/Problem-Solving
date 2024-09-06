
--Problem 9: Get all vehicles that runs with GAS


Select		VehicleDetails.*, FuelTypes.FuelTypeName
From		VehicleDetails Inner join FuelTypes ON FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID
Where		(FuelTypes.FuelTypeName = N'GAS')

--Problem 10 Get all Makes that runs with GAS

Select		Distinct Makes.Make, FuelTypes.FuelTypeName
From		VehicleDetails Inner join 
				
				FuelTypes ON FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID inner join
				Makes ON VehicleDetails.MakeID = Makes.MakeID 

Where		(FuelTypes.FuelTypeName = N'GAS')
GROUP BY Makes.Make, FuelTypes.FuelTypeName
ORDER BY Makes.Make

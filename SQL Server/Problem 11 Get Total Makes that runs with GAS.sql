
-- Problem 11 Get Total Makes that runs with GAS

select count(*) from
(
	Select	Distinct Makes.Make, FuelTypes.FuelTypeName
	From	VehicleDetails Inner join 
				FuelTypes ON FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID inner join
					Makes ON VehicleDetails.MakeID = Makes.MakeID 
	
	Where	(FuelTypes.FuelTypeName = N'GAS')
) R1

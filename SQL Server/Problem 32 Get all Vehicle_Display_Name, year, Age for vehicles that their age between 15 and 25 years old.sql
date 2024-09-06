
--Problem 32 Get all Vehicle_Display_Name, year, 
--Age for vehicles that their age between 15 and 25 years old

select * from
( 
	Select VehicleDetails.Vehicle_Display_Name, Year, Age= YEAR(GetDate()) - VehicleDetails.year
	from VehicleDetails
) R1

Where Age between 15 and 25
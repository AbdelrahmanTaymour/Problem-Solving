
-- Problem 31 Get all Vehicle_Display_Name, year 
-- and add extra column to calculate the age of the car then sort the results by age desc.

Select VehicleDetails.Vehicle_Display_Name, Year, Age= YEAR(GetDate()) - VehicleDetails.year
from VehicleDetails
Order by Age Desc

-- Problem 03  Get number vehicles made between 1950 and 2000

Select count(*) as NumberOfVehicles from VehicleDetails
Where Year between 1950 and 2000;

--Problem 35 Get all vehicles that have the Maximum Engine_CC

Select * from VehicleDetails
wHERE Engine_CC = (SELECT MAX(Engine_CC) as MinimimEngine FROM VehicleDetails)
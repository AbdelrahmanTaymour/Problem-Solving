
-- Problem 34 Get all vehicles that have the minimum Engine_CC

Select VehicleDetails.Vehicle_Display_Name from VehicleDetails
where Engine_CC = ( select  Min(Engine_CC) as MinEngineCC  from VehicleDetails )

--Problem 36 Get all vehicles that have Engin_CC below average

Select VehicleDetails.Vehicle_Display_Name from VehicleDetails
where Engine_CC < ( select  avg(Engine_CC) as MinEngineCC  from VehicleDetails )


--Problem 37 Get total vehicles that have Engin_CC above average

select Count(*) as NumberOfVehiclesAboveAverageEngineCC from
(
 
	Select ID,VehicleDetails.Vehicle_Display_Name from VehicleDetails
	where Engine_CC > ( select  Avg(Engine_CC) as MinEngineCC  from VehicleDetails )

) R1
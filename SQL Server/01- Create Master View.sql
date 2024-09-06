-- Problem 1 Create Master View

CREATE VIEW VehicleDetailsView AS (
SELECT 
	VehicleDetails.ID,
	Makes.Make,
	MakeModels.ModelName,
	SubModels.SubModelName,
	Bodies.BodyName,
	VehicleDetails.Vehicle_Display_Name,
	VehicleDetails.Year,
	DriveTypes.DriveTypeName,
	VehicleDetails.Engine,
	VehicleDetails.Engine_CC,
	VehicleDetails.Engine_Cylinders,
	VehicleDetails.Engine_Liter_Display,
	FuelTypes.FuelTypeName,
	VehicleDetails.NumDoors
FROM VehicleDetails
LEFT JOIN SubModels ON SubModels.SubModelID = VehicleDetails.SubModelID
LEFT JOIN MakeModels ON MakeModels.ModelID = SubModels.ModelID
LEFT JOIN Makes ON Makes.MakeID = MakeModels.MakeID
LEFT JOIN Bodies ON Bodies.BodyID = VehicleDetails.BodyID
LEFT JOIN DriveTypes ON DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID
LEFT JOIN FuelTypes ON FuelTypes.FuelTypeID = VehicleDetails.FuelTypeID
);

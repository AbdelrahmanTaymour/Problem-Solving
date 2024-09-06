
--Problem 22 Get percentage of vehicles that has no doors specified

 SELECT
 (
		CAST( (SELECT COUNT(*) FROM VehicleDetails) AS float)
		/
		CAST( (SELECT COUNT(*) FROM VehicleDetails WHERE NumDoors is NULL) AS float)

 ) AS PercOfNoSpecifiedDoors


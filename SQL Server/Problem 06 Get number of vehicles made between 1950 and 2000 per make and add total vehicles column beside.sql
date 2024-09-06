
-- Problem 6 Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside

SELECT Makes.Make, COUNT(*) AS NumberOfVehicle, 
	(select Count(*) from VehicleDetails As TotalVehicle) As TotalVehicle
FROM Makes INNER JOIN 
	VehicleDetails ON Makes.MakeID = VehicleDetails.MakeID
	
WHERE (VehicleDetails.Year BETWEEN 1950 AND 2000)
GROUP BY Makes.Make
ORDER BY COUNT(*) DESC;

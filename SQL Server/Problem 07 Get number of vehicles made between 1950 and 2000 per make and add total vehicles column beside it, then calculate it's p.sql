
--Problem 7 Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside it, then calculate it's percentage

Select *, CAST(NumberOfVehicle AS float) / CAST(TotalVehicle AS float) AS Perc  from
(
	SELECT	Makes.Make, COUNT(*) AS NumberOfVehicle, (select Count(*) from VehicleDetails As TotalVehicle) As TotalVehicle 
	FROM	Makes INNER JOIN 
			VehicleDetails ON Makes.MakeID = VehicleDetails.MakeID
	WHERE	(VehicleDetails.Year BETWEEN 1950 AND 2000)
	GROUP BY Makes.Make
) R1
ORDER BY NumberOfVehicle DESC

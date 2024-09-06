--Problem 4 : Get number vehicles made between 1950 and 2000 per make and order them by Number Of Vehicles Descending

Select Makes.Make, COUNT(*) As NumberOfVeicles
	From VehicleDetails inner join Makes ON Makes.MakeID = VehicleDetails.MakeID
	Where Year between 1950 and 2000
GROUP BY Makes.Make
ORDER BY NumberOfVeicles desc;

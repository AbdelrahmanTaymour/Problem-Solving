
--Problem 5 : Get All Makes that have manufactured more than 12000 Vehicles in years 1950 to 2000

--Using Having
Select Makes.Make, COUNT(*) As NumberOfVeicles
	From VehicleDetails inner join Makes ON Makes.MakeID = VehicleDetails.MakeID
	Where Year between 1950 and 2000
GROUP BY Makes.Make
Having COUNT(*) > 12000
ORDER BY NumberOfVeicles desc;


--Without Having
Select * from 
(
	Select Makes.Make, COUNT(*) As NumberOfVeicles
		From VehicleDetails inner join Makes ON Makes.MakeID = VehicleDetails.MakeID
	Where Year between 1950 and 2000
	GROUP BY Makes.Make

) Results

Where Results.NumberOfVeicles > 12000
ORDER BY NumberOfVeicles desc



--Problem 23 Get MakeID , Make, SubModelName for all vehicles that have SubModelName 'Elite'

 SELECT		distinct VehicleDetails.MakeID, Makes.Make, SubModelName 
 From		VehicleDetails INNER JOIN
				SubModels ON VehicleDetails.SubModelID = SubModels.SubModelID INNER JOIN
				Makes On VehicleDetails.MakeID = Makes.MakeID 
WHERE		SubModelName = 'Elite'


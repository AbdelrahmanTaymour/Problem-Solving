
--Problem 18 Get total vehicles per DriveTypeName Per Make and order them per make asc then per total Desc

SELECT        distinct Makes.Make, DriveTypes.DriveTypeName, COUNT(*) AS Total
FROM            DriveTypes INNER JOIN
						 VehicleDetails ON DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID INNER JOIN
						 Makes ON VehicleDetails.MakeID = Makes.MakeID
WHERE		 DriveTypes.DriveTypeName ='FWD'
GROUP BY Makes.Make, DriveTypes.DriveTypeName
ORDER BY Makes.Make ASC, DriveTypes.DriveTypeName DESC
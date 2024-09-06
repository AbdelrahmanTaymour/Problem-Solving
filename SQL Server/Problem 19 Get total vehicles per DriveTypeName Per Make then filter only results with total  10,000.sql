
--Problem 19 Get total vehicles per DriveTypeName Per Make then filter only results with total > 10,000

SELECT        distinct Makes.Make, DriveTypes.DriveTypeName, Count(*) AS Total
FROM            DriveTypes INNER JOIN
                         VehicleDetails ON DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID INNER JOIN
                         Makes ON VehicleDetails.MakeID = Makes.MakeID

Group By Makes.Make, DriveTypes.DriveTypeName
Having Count(*) > 10000
Order By Make ASC, Total Desc
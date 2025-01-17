
--Problem 43 Get Make and Total Number Of Doors Manufactured Per Make

SELECT        Makes.Make, Sum(VehicleDetails.NumDoors) AS TotalNumberOfDoors
FROM            VehicleDetails INNER JOIN
                         Makes ON VehicleDetails.MakeID = Makes.MakeID

Group By Make
Order By TotalNumberOfDoors desc

-- Problem 44 Get Total Number Of Doors Manufactured by 'Ford'

SELECT        Makes.Make, Sum(VehicleDetails.NumDoors) AS TotalNumberOfDoors
FROM            VehicleDetails INNER JOIN
                         Makes ON VehicleDetails.MakeID = Makes.MakeID

Group By Make
Having Make='Ford'
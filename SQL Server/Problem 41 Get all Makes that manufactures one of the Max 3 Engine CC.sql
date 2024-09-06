
-- Problem 41 Get all Makes that manufactures one of the Max 3 Engine CC

SELECT        distinct Makes.Make
FROM            VehicleDetails INNER JOIN
                         Makes ON VehicleDetails.MakeID = Makes.MakeID
WHERE        (VehicleDetails.Engine_CC IN
                             (SELECT DISTINCT TOP (3) Engine_CC
                               FROM            VehicleDetails 
                               ORDER BY Engine_CC DESC)
							 )

Order By Make;

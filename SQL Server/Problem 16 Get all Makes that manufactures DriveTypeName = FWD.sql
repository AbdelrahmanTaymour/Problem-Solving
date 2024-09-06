
--Problem 16 Get all Makes that manufactures DriveTypeName = FWD

SELECT  distinct Makes.Make, DriveTypes.DriveTypeName
FROM    DriveTypes INNER JOIN
                      VehicleDetails ON DriveTypes.DriveTypeID = VehicleDetails.DriveTypeID INNER JOIN
                           Makes ON VehicleDetails.MakeID = Makes.MakeID
WHERE DriveTypes.DriveTypeName ='FWD'

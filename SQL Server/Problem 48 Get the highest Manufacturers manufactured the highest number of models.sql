
-- Problem 48 Get the highest Manufacturers manufactured the highest number of models ,
-- remember that they could be more than one manufacturer have the same high number of models

SELECT        Makes.Make, COUNT(*) AS NumberOfModels
FROM            Makes INNER JOIN MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
having COUNT(*) = 
(
	select Max(NumberOfModels) as MaxNumberOfModels
	from
	(

			SELECT      MakeID, COUNT(*) AS NumberOfModels
			FROM        MakeModels
			GROUP BY MakeID
	) R1
)


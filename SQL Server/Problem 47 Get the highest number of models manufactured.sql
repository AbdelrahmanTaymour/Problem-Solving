
-- Problem 47: Get the highest number of models manufactured

select Max(NumberOfModels) as MaxNumberOfModels
from
(

		SELECT        Makes.Make, COUNT(*) AS NumberOfModels
		FROM            Makes INNER JOIN
								 MakeModels ON Makes.MakeID = MakeModels.MakeID
		GROUP BY Makes.Make
		
) R1
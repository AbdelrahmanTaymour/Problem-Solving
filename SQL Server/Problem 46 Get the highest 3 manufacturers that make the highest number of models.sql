
-- Problem 46 Get the highest 3 manufacturers that make the highest number of models

SELECT      top 3  Makes.Make, COUNT(*) AS NumberOfModels
FROM            Makes INNER JOIN
                         MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
Order By NumberOfModels Desc
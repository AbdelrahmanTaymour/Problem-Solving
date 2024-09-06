
-- Problem 53 Get all employees that have manager or does not have manager along with Manager's name, incase no manager name the same employee name as manager to himself

SELECT Employees.Name, Employees.ManagerID, Employees.Salary,  
  CASE
    WHEN Managers.Name is Null  THEN Employees.Name
    ELSE Managers.Name
END as ManagerName
FROM Employees Left JOIN
                         Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID;

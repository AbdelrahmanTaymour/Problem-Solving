
-- Problem 52 Get all employees that have manager or does not have manager along with Manager's name, incase no manager name show null

SELECT        Employees.Name, Employees.ManagerID, Employees.Salary, Managers.Name AS ManagerName
FROM            Employees Left JOIN
                         Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID

--Problem 51 Get all employees that have manager along with Manager's name.

SELECT        Employees.Name, Employees.ManagerID, Employees.Salary, Managers.Name AS ManagerName
FROM            Employees INNER JOIN
                         Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID
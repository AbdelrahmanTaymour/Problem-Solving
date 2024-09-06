
-- Problem 54 Get All Employees managed by 'Mohammed'

SELECT        Employees.Name, Employees.ManagerID, Employees.Salary, Managers.Name AS ManagerName
FROM            Employees INNER JOIN
                         Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID
where Managers.Name='Mohammed'



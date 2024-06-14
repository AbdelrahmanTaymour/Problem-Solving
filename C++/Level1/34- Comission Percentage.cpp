#include <iostream>
using namespace std;

//Program 34 - Comission Percentage

int GetTotalSales() {
    int TotalSales;
    cout << "Enter The Total Sales: ";
    cin >> TotalSales;
    return TotalSales;
}
float GetComissionPrecentage(float TotalSales) {
    if (TotalSales >= 1000000)
        return 0.01;
    else if (TotalSales >= 500000)
        return 0.02;
    else if (TotalSales >= 100000)
        return 0.03;
    else if (TotalSales >= 50000)
        return 0.05;
    else
        return 0.00;
}
float CalculateTotalCommetion(float TotalSales) {
    return GetComissionPrecentage(TotalSales) * TotalSales;
}

int main()
{
    //Program 34 - Comission Percentage
    float TotalSales = GetTotalSales();
    cout << "Comission Precentage: " << GetComissionPrecentage(TotalSales) << endl;
    cout << "Total Comission: " << CalculateTotalCommetion(TotalSales) << endl;
}

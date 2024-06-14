#include <iostream>
using namespace std;

//Problem 15 - Rectangle Area
void ReadHightWidth(float& Hight, float& Width) {
	cout << "Hight: ";
	cin >> Hight;
	cout << "Width: ";
	cin >> Width;
}
float CalculateRectangleArea(float Hight, float Width) {
	return Hight * Width;
}
void PrintRectangleArea(float Area) {
	cout << "\nArea: " << Area << endl;
}

int main()
{
	//Problem 15 - Rectangle Area
	/*float Hight, Width;
	ReadHightWidth(Hight, Width);
	PrintRectangleArea(CalculateRectangleArea(Hight, Width));*/
}

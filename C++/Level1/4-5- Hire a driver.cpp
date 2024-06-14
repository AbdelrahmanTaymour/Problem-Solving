//Problem #4 Hire a driver Case 1 && Problem #5 Hire a driver Case 2

#include <iostream>
#include <string>
using namespace std;

struct stInfo {
	int Age;
	bool HasDrivingLicense;
	bool HasRecommendation;
};

stInfo ReadInfo() {
	stInfo Info;

	cout << "Please Enter your Age?" << endl;
	cin >> Info.Age;

	cout << "Do you have driver Liense?" << endl;
	cin >> Info.HasDrivingLicense;

	cout << "Do you have Recommendation?" << endl;
	cin >> Info.HasRecommendation;

	return Info;
}

bool IsAccepted(stInfo Info) {
	if (Info.HasRecommendation) {
		return true;
	}
	else {
		return (Info.Age > 21 && Info.HasDrivingLicense);
	}
}

void PrintResult(stInfo Info) {
	if (IsAccepted(Info))
		cout << "Haird" << endl;
	else
		cout << "Rejected" << endl;
}

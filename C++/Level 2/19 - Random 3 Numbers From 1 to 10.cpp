#include <iostream>
#include <cstdlib>
using namespace std;

//Program 19 - Random 3 Numbers From 1 to 10

int RandomNumber(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

int main()
{
    //Program 19 - Random 3 Numbers From 1 to 10

    srand((unsigned)time(NULL));
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
}

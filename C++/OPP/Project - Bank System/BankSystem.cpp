#include <iostream>
#include "clsLoginRegisterScreen.h"

int main()
{
    while (true)
    {
        if (!clsLoginRegisterScreen::ShowLoginRegisterScreen())
            break;
    }
   
    return 0;
}

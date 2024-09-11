
#include <iostream>
#include "inc/BL_ctrl.hpp"
#include "src/BL_ctrl.cpp"
#include "inc/wifi_ctrl.hpp"
#include "src/wifi_ctrl.cpp"
#include <cstdlib>

using namespace std;




int main(int argc, char *argv[])
{
    int input=0;
    while(1)
    {  // system(CLEAR);
        cout<<"Control Program\n---------------------------------"<<endl;
        cout<<"1-WiFi Control"<<endl;
        cout<<"2-Bluetooth Control"<<endl;
        cout<<"3-Exit"<<endl;
        cin>>input;

        switch(input)
        {
            system(CLEAR);
            case 1:
                wifi_main_menu();
                break;
            case 2:
                BL_main_menu();
                break;
            case 3:
                return 0;
                break;
            default:
                cout<<"Wrong Input,Try Again"<<endl;
                break;
        }
    }

    return 0;
}
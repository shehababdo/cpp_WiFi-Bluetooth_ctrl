#include "../inc/BL_ctrl.hpp"
#include "common.cpp"
using namespace std;
void BL_main_menu()
{
    int input;
    cout<<"Bluetooth Control Program"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"1-Display Bluetooth Status"<<endl;
    cout<<"2-Turn Bluetooth ON"<<endl;
    cout<<"3-Turn Bluetooth OFF"<<endl;
    cout<<"4-Connect to Bluetooth Device"<<endl;
    cout<<"please Enter your choice :";
    cin>>input;
    switch (input)
    {
        system(CLEAR);
        case 1:
            BL_status();
            break;
        case 2:
            BL_on();
            break;
        case 3:
            BL_off();
            break;
        case 4:
        {
            std::string device;
            cout<<"Please Enter Device Name :"<<endl;
            cin>>device;
            BL_device_connect(device);
            break;
        }
        default:
            break;
    }
}
void BL_status()
{
 std::string ret =executeCommand(BLUETOOTH_STATUS);
 if(ret.find("Powered: yes") != std::string::npos)
    {
        cout<< "Bluetooth is Enabled"<<endl;
    } 
 else
    {
        cout<< "Bluetooth is Disabled"<<endl;
    }
    
}
void BL_on()
{
std::cout<<executeCommand(BLUETOOTH_ON)<<endl;
}
void BL_off()
{
std::cout<<executeCommand(BLUETOOTH_OFF)<<endl;
}
void BL_device_connect(std::string device)
{
std::string concat = BLUETOOTH_PAIR ;

std::string ret = executeCommand((concat + " " +device).c_str());
if (ret.find("Pairing successful") != std::string::npos)
    {cout<<"Paired successfully to"+device<<endl;}
else 
{cout<<"Failed to Pair"<<endl;}

concat=BLUETOOTH_CONNECT;
ret = executeCommand((concat + " " +device).c_str());

if (ret.find("Connection successful") != std::string::npos)
    cout<<"Connected successfully to"+device<<endl;
else 
{cout<<"Failed to connect"<<endl;}
}
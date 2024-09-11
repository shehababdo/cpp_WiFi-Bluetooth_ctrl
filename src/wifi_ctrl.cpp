#include "../inc/wifi_ctrl.hpp"
#include "../inc/common.hpp"
#include <cstdlib>
//#include "common.cpp"
//#include <cstddef>
using namespace std;


void wifi_main_menu()
{
   // system(CLEAR);
    cout<<"WiFi Control Program"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"1-Display WiFi Status"<<endl;
    cout<<"2-Turn WiFi ON"<<endl;
    cout<<"3-Turn WiFi OFF"<<endl;
    cout<<"4-Connect to WiFi Network"<<endl;
    cout<<"5-Removed a saved Network"<<endl;
    cout<<"6-Search for a Networks"<<endl;
    cout<<"7-Back to main menu"<<endl;
    int input;
    cout<<"please Enter your choice :";
    cin>>input;

    switch (input)
    {   system(CLEAR);
        case 1:
        display_wifi_status();
            break;
        case 2:
        wifi_on();
            break;
        case 3:
        wifi_off();
            break;
        case 4:
            std::cout<<"1-Connect to New WiFi"<<endl;
            std::cout<<"2-Connect to Saved WiFi"<<endl;
            std::cout<<"please Enter your choice :";
            std::cin>>input;
            switch (input)
            {
                case 1:
                {
                    std::string ssid;
                    std::string pass;
                    std::cout<<"please Enter SSID :";
                    std::cin>>ssid;
                    std::cout<<"please Enter Password :";
                    std::cin>>pass;
                    connect_2_new_network(ssid,pass);
                    break;
                }
                case 2:
                {   
                    std::cout<<"NOT YET havndeled"<<endl;
                    break;
                }
            }
            break;
        case 5:
        {
            std::string ssid;
            std::cout<<"please Enter SSID :";
            std::cin>>ssid;
            remove_network(ssid);
            break;
        }
        case 6:
            show_available_network();
            break;
        case 7:
            break;
        default:
            cout<<"No Inputs"<<endl;
            break;
    }
}

void display_wifi_status()
{
    std::cout<<executeCommand(WIFI_STATUS)<<endl;
}
void wifi_on()
{
    std::cout<<executeCommand(WIFI_ON)<<endl;
}
void wifi_off()
{
    std::cout<<executeCommand(WIFI_OFF)<<endl;
}

void connect_2_new_network(std::string ssid,std::string password)
{
    std::string concat =CONNECT_2_NEW_WIFI;
    cout<<executeCommand((concat + " " + "'" +ssid + "'" + " password '" + password + "'" ).c_str())<<endl;
}

void connect_2_saved_network(std::string ssid)
{
    std::string concat =CONNECT_2_SAVED_WIFI;
    executeCommand((concat+ " '" + ssid + "'").c_str());
}
void remove_network(std::string ssid)
{
    std::string concat=DELETE_SAVED_NETWORK;
    if(CheckIFNetworkExist(ssid))
    {
    cout<<executeCommand((concat+ " '" + ssid + "'").c_str())<<endl;
    }
    else{cout<<"Network Not exist"<<endl;}

}
void modify_network(std::string old_ssid,std::string new_ssid)
{
    if(CheckIFNetworkExist(old_ssid))
    {
    }
    else{cout<<"Network Not exist"<<endl;}
}

void show_available_network()
{
    std::cout << executeCommand(AVAILABLE_WIFI)<<endl;
}
void show_saved_network()
{
    std::cout << executeCommand(SAVED_WIFI)<<endl;
}

bool CheckIFNetworkExist(const std::string ssid)
{   
    std::string concat=SAVED_WIFI;
    std::string savednetworks = executeCommand(( concat+ "| grep wifi").c_str());

    if(savednetworks.find(ssid) != std::string::npos)
    {
        return true;
    }
    return false;
}

void saveWifiNetworks(const vector<WifiNetwork>& networks, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const WifiNetwork& network : networks) {
        file << network.ssid << endl;
        file << network.password << endl;
    }

    file.close();
}

vector<WifiNetwork> parseNetworkData(const vector<string>& data) {
    vector<WifiNetwork> networks;
    regex pattern(R"(([^:]+)nmconnection:psk=([^#]+))");
     saveWifiNetworks(networks, "saved_networks.txt");
    for (const string& line : data) {
        smatch matches;
        if (regex_search(line, matches, pattern)) {
            WifiNetwork network;
            network.ssid = matches[1];
            network.password = matches[2];
            networks.push_back(network);
        }
    }

    return networks;
}   
#ifndef __COMMON__H__
#define __COMMON__H__

#include <string>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <string.h>
#include <fstream>


 #define WIFI_STATUS                "nmcli radio wifi"
 #define WIFI_ON                    "nmcli radio wifi on"
 #define WIFI_OFF                   "nmcli radio wifi off"
 #define AVAILABLE_WIFI             "nmcli device wifi list"
 #define SAVED_WIFI                 "nmcli connection show |grep wifi"
 #define CONNECT_2_SAVED_WIFI       "nmcli connection up"
 #define CONNECT_2_NEW_WIFI         "nmcli device wifi connect"
 #define DELETE_SAVED_NETWORK       "nmcli connection delete"
 #define MODIFY_SSID                "sudo nmcli connection modify"
 #define SAVED_WIFI_DATA            "MYCWD=`pwd`; cd /etc/NetworkManager/system-connections/ ; sudo grep -e '^psk=' * | less ; cd $MYCWD"
 #define BLUETOOTH_STATUS           "bluetoothctl show"
 #define BLUETOOTH_ON               "bluetoothctl power on"
 #define BLUETOOTH_OFF              "bluetoothctl power off"
 #define BLUETOOTH_PAIR             "bluetoothctl pair"
 #define BLUETOOTH_CONNECT          "bluetoothctl connect"
 #define CLEAR                      "clear"
 

 struct WifiNetwork {
    std::string ssid;
    std::string password;
};

std::string executeCommand(const char* cmd);
#endif  //!__COMMON__H__
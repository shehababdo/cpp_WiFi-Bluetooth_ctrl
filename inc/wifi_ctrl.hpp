#ifndef __WIFI_CTRL__H__
#define __WIFI_CTRL__H__

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <cstdlib>

//std::vector<std::vector<std::string>>continer{0};

void wifi_main_menu();
void display_wifi_status();
void wifi_on();
void wifi_off();
void connect_2_new_network(std::string ssid,std::string password);
void connect_2_saved_network(std::string ssid);
void remove_network(std::string);
void modify_network();
void save_network();
void show_available_network();
bool CheckIFNetworkExist(const std::string ssid);
#endif  //!__WIFI_CTRL__H__
#ifndef __BL_CTRL__H__
#define __BL_CTRL__H__
#include <string>
#include <iostream>
#include "common.hpp"

void BL_main_menu();
void BL_status();
void BL_on();
void BL_off();
void BL_display_devices();
void BL_device_connect(std::string device);
#endif  //!__BL_CTRL__H__
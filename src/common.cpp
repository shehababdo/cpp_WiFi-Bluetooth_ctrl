#include "../inc/common.hpp"
#include <iostream>




std::string executeCommand(const char* cmd) {

    std::array<char, 128> buffer;
    std::string result;

     std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    auto it = result.find("Error");
    if(it != std::string::npos)
    {
        return "Error";    
    } 
    return result;
}
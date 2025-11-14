#include "register_file.h"
#include <iostream>


RegisterFile::RegisterFile() {
    for (int i = 0; i < 32; i++) {
        reg[i] = 0;
    }
    // Initialize regMap with register names without '$'
    regMap["zero"] = 0; regMap["at"] = 1;
    regMap["v0"] = 2; regMap["v1"] = 3;
    regMap["a0"] = 4; regMap["a1"] = 5;
    regMap["a2"] = 6; regMap["a3"] = 7;
    regMap["t0"] = 8; regMap["t1"] = 9;
    regMap["t2"] = 10; regMap["t3"] = 11;
    regMap["t4"] = 12; regMap["t5"] = 13;
    regMap["t6"] = 14; regMap["t7"] = 15;
    regMap["s0"] = 16; regMap["s1"] = 17;
    regMap["s2"] = 18; regMap["s3"] = 19;
    regMap["s4"] = 20; regMap["s5"] = 21;
    regMap["s6"] = 22; regMap["s7"] = 23;
    regMap["t8"] = 24; regMap["t9"] = 25;
    regMap["k0"] = 26; regMap["k1"] = 27;
    regMap["gp"] = 28; regMap["sp"] = 29;
    regMap["fp"] = 30; regMap["ra"] = 31;
    // Debug: Print map contents to verify initialization
    std::cout << "Register map initialized with size: " << regMap.size() << std::endl;
    for (const auto& pair : regMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}


unsigned int RegisterFile::getReg(const std::string& regName) {
    std::string cleanName = regName.substr(regName.find('$') == std::string::npos ? 0 : 1);
    std::cout << "Looking up register: " << cleanName << std::endl; // Debug
    if (regMap.find(cleanName) != regMap.end()) {
        return reg[regMap[cleanName]];
    }
    std::cout << "Error: Invalid register name: " << regName << std::endl;
    return 0;
}


void RegisterFile::setReg(const std::string& regName, unsigned int value) {
    std::string cleanName = regName.substr(regName.find('$') == std::string::npos ? 0 : 1);
    std::cout << "Setting register: " << cleanName << std::endl; // Debug
    auto it = regMap.find(cleanName);
    if (it != regMap.end() && it->second != 0) {
        std::cout << "Setting " << cleanName << " to " << value << std::endl; // Debug
        reg[it->second] = value;
    } else {
        std::cout << "Error: Cannot set register: " << regName << std::endl;
    }
}


void RegisterFile::displayRegisters() {
    std::cout << "Registers:" << std::endl;
    for (const auto& pair : regMap) {
        std::cout << "$" << pair.first << ": " << reg[pair.second] << std::endl;
    }
}

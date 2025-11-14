#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <iostream>
#include <string>
#include <map>

class RegisterFile
{

public:
    RegisterFile();
    unsigned int getReg(const std::string& regName);
    void setReg(const std::string& regName, unsigned int value);
    void displayRegisters();
private:
    unsigned int reg[32];
    std::map<std::string, int> regMap;
};

#endif

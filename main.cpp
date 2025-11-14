/********************************************************************************************************
File : main.cpp
Author : Brysen Landis

Description : MIPs Interpreter for CISS360 
*******************************************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
#include "register_file.h"
#include "memory.h"
#include "utils.h"


class MIPSInterpreter
{
public:
    MIPSInterpreter() : PC(0x400000)
    {}

    void runInteractive()
    {
        std::string input;
        std::cout << "TEXT:" << std::hex << PC << "> ";
        
        while (std::getline(std::cin, input))
        {
            if (input == "quit") break;
            executeInstruction(input);
            regFile.displayRegisters();
            std::cout << "TEXT:" << std::hex << PC << "> ";
        }
    } 
private:
    RegisterFile regFile;
    Memory mem;
    std::vector<std::string> instructions;
    unsigned int PC;

    std::vector<std::string> splitInstruction(const std::string& instr)
    {
        std::vector<std::string> tokens;
        std::stringstream ss(instr);
        std::string token;
        while (ss >> token)
        {
            // Remove any trailing commas or unwanted characters
            size_t end = token.find_last_not_of(", \t");
            if (end != std::string::npos)
            {
                token = token.substr(0, end + 1);
            }
            tokens.push_back(token);
        }
        return tokens;
    }

    void executeInstruction(const std::string& instr)
    {
        std::vector<std::string> tokens = splitInstruction(instr);
        if (tokens.empty()) return;
        
        if (tokens[0] == "add")
        {
            if (tokens.size() == 4)
            {
                regFile.setReg(tokens[1], regFile.getReg(tokens[2]) + regFile.getReg(tokens[3]));
                PC += 4;
            }
            else
            {
                std::cout << "Warning: Invalid add instruction format" << std::endl;
            }
        }
        else if (tokens[0] == "sub")
        {
            if (tokens.size() == 4)
            {
                regFile.setReg(tokens[1], regFile.getReg(tokens[2]) - regFile.getReg(tokens[3]));
                PC += 4;
            }
            else
            {
                std::cout << "Warning: Invalid sub instruction format" << std::endl;
            }
        }
        else if (tokens[0] == "li")
        {
            if (tokens.size() == 3)
            {
                unsigned int imm = std::stoul(tokens[2]);
                regFile.setReg(tokens[1], imm);
                PC += 4;
            }
            else
            {
                std::cout << "Warning: Invalid li instruction format" << std::endl;
            }
        }
        else if (tokens[0] == "move")
        {
            if (tokens.size() == 3)
            {
                regFile.setReg(tokens[1], regFile.getReg(tokens[2]));
                PC += 4;
            }
            else
            {
                std::cout << "Warning: Invalid move instruction format" << std::endl;
            }
        }
        else
        {
            std::cout << "Warning: Unsupported instruction: " << tokens[0] << std::endl;
        }
        instructions.push_back(instr);
    }
};


int main()
{
    MIPSInterpreter sim;
    sim.runInteractive();
    return 0;
}

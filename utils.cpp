#include "utils.h"
#include <iomanip>
#include <sstream>


std::string uintToHex(unsigned int value)
{
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}


std::string uintToChars(unsigned int value)
{
    std::string chars;
    for (int i = 0; i < 4; i++)
    {
        chars += static_cast<char>((value >> (i * 8)) & 0xFF);
    }
    return chars;
}


unsigned int hexToUint(const std::string& hex)
{
    unsigned int value;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> value;
    return value;
}


unsigned int charsToUint(const std::string& chars)
{
    unsigned int value = 0;
    for (int i = 0; i < 4 && i < chars.length(); i++)
    {
        value |= (static_cast<unsigned char>(chars[i]) << (i * 8));
    }
    return value;
}

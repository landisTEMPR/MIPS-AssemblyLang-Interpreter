#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cstdint>

std::string uintToHex(unsigned int value);
std::string uintToChars(unsigned int value);
unsigned int hexToUint(const std::string& hex);
unsigned int charsToUint(const std::string& chars);

#endif

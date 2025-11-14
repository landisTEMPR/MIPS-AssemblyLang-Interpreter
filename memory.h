#ifndef MEMORY_H
#define MEMORY_H

#include <map>
#include <cstdint>

class Memory
{
  public:
    Memory() {}
    unsigned int fetch(unsigned int addr);
    void store(unsigned int addr, unsigned char value);
  private:
    std::map<unsigned int, unsigned char> mem;
};

#endif

#include "memory.h"


unsigned int Memory::fetch(unsigned int addr)
{
    if (mem.find(addr) != mem.end())
    {
        return mem[addr];
    }
    return 0; // Return 0 for uninitialized memory
}


void Memory::store(unsigned int addr, unsigned char value)
{
    mem[addr] = value;
}

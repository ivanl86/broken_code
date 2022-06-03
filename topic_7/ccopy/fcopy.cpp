
#include <iostream>
#include <fstream>
#include <cstdlib>

#define BUFFER_SZ 8196

std::ofstream *openFile(const std::string &, std::ios);

int main(int argc, char const *argv[])
{
    char buff[BUFFER_SZ];
    int qty;
    std::ifstream src("building.h", std::ios::in | std::ios::binary); // can use absoulute path or relative path
    std::ofstream dst("building_copy.h", std::ios::out | std::ios::binary);
    if (!src || !dst)
        exit(EXIT_FAILURE);
    while (src)
    {
        src.read(buff, BUFFER_SZ);
        qty = src.gcount();
        dst.write(buff, qty);
    }
    
    return 0;
}

std::ofstream *openFile(const std::string &name, std::ios mode)
{
    std::ofstream *file = new std::ofstream(name);
    //file->open(name, mode);
}
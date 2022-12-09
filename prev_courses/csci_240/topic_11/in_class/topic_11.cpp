
#include <iostream>
#include <sstream>
#include <array>
#include <fstream>

int main(int argc, char const *argv[])
{
    std::ifstream in("cost.txt");
    std::string line;
    int u;
    int v;
    int c;

    const std::array<std::string, 20> cityName{};

    while (in) {
        std::getline(in, line);
        std::stringstream ss(line);
        ss >> u;
        while (ss)
        {
            ss >> v;
            ss >> c;
            std::cout << "from " << u << "to " << v << "wiith a cost of " << c << "\n";
        }
        
    }

    return 0;
}


#include <iostream>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    std::string S{"ABCBCADEEABBCDEAEE"};
    std::unordered_map<char, uint32_t> map;

    for (size_t c{'A'}; c <= 'Z'; ++c)
        map[c] = 0;

    for (char c : S)
        ++map[c];

    for (std::pair<char, uint32_t> i : map)
        if (i.second > 0)
            std::cout << i.first << " = " << i.second << "\n";
    // {
    //     {'A',0}, {'B',0}, {'C',0}, {'D',0}
    // };

    // for (char c : S)
    //     ++map[c];

    // for (std::pair<char, uint32_t> i : map)
    //     std::cout << i.first << " = " << i.second << "\n";
    
    return 0;
}

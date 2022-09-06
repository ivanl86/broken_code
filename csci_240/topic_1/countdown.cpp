#include<iostream>

// using std::cout;

int main(int argc, char const *argv[])
{
    // std::cout << argc << " " << argv[0] << std::endl;
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << std::endl;
    std::cout << sizeof(argc) << " " << sizeof argv << std::endl;
    return 0;
}

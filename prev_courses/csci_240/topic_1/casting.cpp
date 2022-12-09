
void func(long long a)
{

}

int main(int argc, char const *argv[])
{
    int left{0};
    long long down{};
    down = left; // implicitly cast
    down = (long long)left; // C style explicitly cast
    down = static_cast<long long>(left); // C++ explicity cast
    func(left); // implicitly cast
    {
        long long down{};
    }
    return 0;
}

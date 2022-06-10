int main()
{
    const int buf; // a const variable must be initialized
    int cnt = 0;
    const int sz = cnt;
    ++cnt;
    ++sz; // a const variable cannot be modified
}
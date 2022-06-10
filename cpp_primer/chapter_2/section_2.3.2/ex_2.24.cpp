
int main()
{
    int i = 42;
    void *p = &i; // p can point to any object
    long *lp = &i; // lp can only point to long and i is int hence illegal
}
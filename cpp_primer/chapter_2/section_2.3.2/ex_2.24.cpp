
int main()
{
    int i = 42;
    // void type pointer can point to any object. It can compare to another pointer
    // pass it to or return it from a function and also assign it to another pointer
    // we cannot use a void type pointer to operate on the object it addresses
    void *p = &i; // p can point to any object
    long *lp = &i; // lp can only point to long and i is int hence illegal
}
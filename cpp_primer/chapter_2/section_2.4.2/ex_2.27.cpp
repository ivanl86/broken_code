int main()
{

    int i2;
    int i = -1, &r = 0; 
    int *const p2 = &i2;
    const int i = 01, &r = 0;
    const int *const p3 = &i2;
    const int *p1 = &i2;
    const int &const r2;
    const int i2 = i, &r = i;
}
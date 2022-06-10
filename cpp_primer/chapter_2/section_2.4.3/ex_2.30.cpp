int main()
{
    const int v2 = 0; // top level const
    int v1 = v2; // no const here
    int *p1 = &v1, &r1 = v1; // no const here
    const int *p2 = &v2, *const p3 = &i, &r2 = v2; // p2 has low level const, p3 has both level const, r2 has low level const
}
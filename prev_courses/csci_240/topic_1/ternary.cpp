

int main(int argc, char const *argv[])
{
    int left{0};
    int right{1};
    left = (right > left) ? right : left;
    ((right > left) ? right : left) = 5;
    return 0;
}

#include "stdlib.h"
#include "stdio.h"

#define BUF_SZ 4096

int main(int argc, char const *argv[])
{
    unsigned char buffer[BUF_SZ];
    int qty;

    FILE *src = NULL;
    FILE *dst = NULL;

    if ((src = fopen("building.h", "rb")) == NULL)
    {
        printf("Couldnot open source file\n");
        exit(1);
    }
    if ((dst = fopen("building_copy.h", "wb")) == 0)
    {
        fclose(src);
        printf("Could not open destination file\n");
        exit(2);
    }
    while ((qty = fread(buffer, sizeof(char), BUF_SZ, src)) > 0)
    { fwrite(buffer, sizeof(char), qty, dst); }
    fclose(src);
    fclose(dst);
    return 0;
}

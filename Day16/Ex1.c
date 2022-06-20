#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");

    if(NULL == fp)
    {
        fprintf(stderr, "Can not open file.\n");
        return -1;
    }

    fseek(fp, sizeof(fp) /2 , SEEK_SET);
    int c;

    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }
    putchar('\n');
    fclose(fp);    

    return 0;
}
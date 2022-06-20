#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    FILE *fpRead;
    FILE *fpWrite;

    if(strcmp(argv[3], "TB\n"))
    {
        fpRead = fopen(argv[1], "r");
        fpWrite = fopen(argv[2], "wb");
        if(fpRead == NULL)
        {
            fprintf(stderr, "You can not open file.");
            return -1;
        }
        if(fpWrite == NULL)
        {
            fprintf(stderr, "You can not create file.");
            return -1;
        }

        int num;

        while (fscanf(fpRead, "%d", &num) != EOF)
        {
            fwrite(&num, sizeof(num), 1, fpWrite);
        }
    }
    else if(strcmp(argv[3], "BT\n"))
    {
        fpRead = fopen(argv[1], "rb");
        fpWrite = fopen(argv[2], "w");
        if(fpRead == NULL)
        {
            fprintf(stderr, "You can not open file.");
            return -1;
        }
        if(fpWrite == NULL)
        {
            fprintf(stderr, "You can not create file.");
            return -1;
        }

        int num;

        while (fread(&num, sizeof(num), 1, fpRead) == 1)
        {
            fprintf(fpWrite, "%d\n", num);
        }
    }

    fclose(fpRead);
    fclose(fpWrite);

    return 0;
}
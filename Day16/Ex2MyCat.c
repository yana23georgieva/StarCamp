#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fr = 0;
    int fw = 1;

    int c;
    int file = 1;
    for(int i = 1; i <= argc; i++)
    {
        if(argc > 1)
        {
            fr = open(argv[file], O_RDONLY);
            file++;
        }

        while((read(fr, &c, 1)) > 0)
        {
            write(fw, &c, 1);
        }

        if (argc > 1)
        {
            close(fr);
        }
        
    }
    return 0;
}
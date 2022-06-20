#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fr = 0;
    int fw = 1;

    int c;
    int file = 1;

    int opt;
    int optCount = 0;
    int nFlag = -1, cFlag = -1;
    int qFlag = -1, vFlag = -1;
    while ((opt = getopt(argc, argv, ":n:c:qv")) != -1)
    {
        switch (opt)
        {
            case 'n': 
                scanf(optarg, "%d", &nFlag);
                optCount += 2;
                break;
            case 'c': 
                scanf(optarg, "%d", &cFlag);
                optCount += 2;
                break;
            case 'q': 
                qFlag = 1;
                optCount ++;
                break;
            case 'v': 
                vFlag = 1;
                optCount ++;
                break;
            case '?':
                printf("Unknown option: %c\n", optopt);
            break;
            case ':':
                printf("Missing arg for %c\n", optopt);
            break;
        }
    }

    printf("%d %d\n", nFlag, cFlag);   

    for(int i = 1; i <= (argc - optCount); i++)
    {
        if(argc > 1)
        {
            fr = open(argv[file], O_RDONLY);
            if (vFlag != -1 && fr > 2)
            {
                char *buff = "\n==> ";
                write(fw, buff, 5);
                write(fw, argv[file], sizeof(argv[file]));
                char *buff2 = " <==\n";
                write(fw, buff2, 5);
            }
            file++;           
        }
        int sym = 0, lines = 0;
        while((read(fr, &c, 1)) > 0)
        {        
            if(nFlag != -1 && lines >= nFlag)
            {
                return 0;
            }
            if(cFlag != -1 && sym >= cFlag)
            {
                return 0;
            }
            write(fw, &c, 1);
            sym++;
            if (c == '\n')
            {
                lines++;
            }
            
        }
        if (argc > 1)
        {
            close(fr);
        }        
    }
    return 0;
}
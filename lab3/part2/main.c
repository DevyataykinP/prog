#include "coder.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
        printf("Usage:\ncoder encode <in-file-name> <out-file-name>\ncoder decode <in-file-name> <out-file-name>\n");
    else
        if ((strcmp(argv[1], "encode") == 0) && (argc == 4))
            encode_file(argv[2], argv[3]);
        else 
            if ((strcmp(argv[1], "decode") == 0) && (argc == 4)) 
                decode_file(argv[2], argv[3]);
            else
                printf("Usage:\ncoder encode <in-file-name> <out-file-name>\ncoder decode <in-file-name> <out-file-name>\n");
    return 0;
}

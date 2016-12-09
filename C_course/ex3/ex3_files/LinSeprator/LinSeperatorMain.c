#include "LinSeperator.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
	{
		fprintf(stderr, "Error: wrong usage.\n");
        fprintf(stderr, "Usage: %s <input file name> <output file name>\n", argv[0]);
        exit(1);
	}
    char *In = argv[1];
    char *Out = argv[2];
    LinSeperator(In, Out);

    return 0;
}

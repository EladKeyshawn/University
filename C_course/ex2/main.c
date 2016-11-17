
#include <stdio.h>
#include "MyString.h"


int main(int argc, char* argv[]) {

    const char* str1 = "keyshawnf";
    const char* str2 = "keyshawn";

    printf("index: %d\n",extendedSubStr(1, 1, str1, str2));

    return 0;
}

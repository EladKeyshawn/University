
#include <stdio.h>
#include "MyString.h"


int main(int argc, char* argv[]) {

    const char* str1 = "keyshawnf";
    const char* str2 = "eak";

    printf("index: %d\n",extendedSubStr(1, 4, str1, str2));

    return 0;
}


#include <stdio.h>
#include "MyString.h"


int main(int argc, char* argv[]) {

    const char* str1 = "keyshawnf";
    const char* str2 = "esan";

    printf("index: %d\n",extendedSubStr(1, 2, str1, str2));
    
    char str[] = "aaa*test,hello.world*abcd.zzz";
    const char* delim = ",.*";
    
    sortDelim(str, delim);
    
    printf("%s \n", str);
    
    

    return 0;
}

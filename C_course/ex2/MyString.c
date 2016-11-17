#include <stdio.h>

int extendedSubStr(int isCyclic, int step, const char* str1, const char* str2) {
    int len1 = 0;
    const char* r1 = str1;
    while (*r1 != '\0' ) {
        len1++;
        r1++;
    }
    
    
    if (*str1 == '\0' || *str2 == '\0') {
        return -1;
    }
    int i,j,temp;

    for(i=0;str1[i]!='\0' ;i++)
    {
        j=0;
        if(str1[i]==str2[j])
        {
            temp=i+1;
            while(str1[i]==str2[j] && str2[j] != '\0')
            {
                 if(str1[i+1] == '\0' && isCyclic == 1) {
                   i = step-1; // end of string cycle back
                   j++; // str2 keep going
                 } else {
                     if (i + step > len1-1 ) {
                         i = step-(len1-i); // iter on str1
                     } else {
                         i += step; // iter on str1
                     }
                   j++; // iter on str2
                 }
                
            }
            if(str2[j] == '\0') {
                return temp-1;
            } else {
                i=temp;
                temp=0;
            }
        }
    }


    return -1;

}

//
//  main.c
//  C_course
//
//  Created by Elad Keyshawn on 04/11/2016.
//  Copyright © 2016 Elad Keyshawn. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int chr; // holds input
    const int CAP_TO_LOWER = 32;
    const int NUM_ASCI_START = 48;
    printf( "Enter a value : \n");
    chr = getchar();
    
    if (chr <= 90 && chr >= 65) {
        printf("%c->%c\n", chr, chr + CAP_TO_LOWER);
        return 0;
    } else if (chr <= 122 && chr >= 97) {
        printf("%c->%c\n", chr, chr - CAP_TO_LOWER);
        return 0;
    } else if (chr >= 48 && chr <= 57) {
        printf("%d\n", (int) pow((double)(chr - NUM_ASCI_START), 2));
        return 0;
    }
    
    printf("%c->invalid\n", chr);
    
    return 0;
}

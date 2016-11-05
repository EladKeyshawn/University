//
//  ex1_2.c
//  C_course
//
//  Created by Elad Keyshawn on 04/11/2016.
//  Copyright © 2016 Elad Keyshawn. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int getY(float a,float b,float c,float d , int x, int Y_RANGE);
void drawPoly(float a,float b,float c,float d);


int main(int argc, const char * argv[]) {
    float a,b,c,d;
    
    printf("y(x)=a+b*x+c*x^2+d*x^3\n");
    printf("Select a:\n");
    scanf("%f", &a);
    printf("Select b:\n");
    scanf("%f", &b);
    printf("Select c:\n");
    scanf("%f", &c);
    printf("Select d:\n");
    scanf("%f", &d);
    printf("y(x)=(%0.3f)+(%0.3f)*x+(%0.3f)*x^2+(%0.3f)*x^3\n", a, b, c, d);
    
    drawPoly(a, b, c, d);
    
    return 0;
    
}



void drawPoly(float a,float b,float c,float d) {
    const int X_RANGE = 35;
    const int Y_RANGE = 10;
//    int Y_ROW_COUNT = 0;
    int y_index = 10;
    for (int y = y_index; y >= -Y_RANGE; y--) {
        for (int x = -X_RANGE; x <= X_RANGE; x++) {
            if (getY(a, b, c, d, x, Y_RANGE) == y) {
                printf("*");
            } else if (x ==0 && y==0) {
                printf("+");
            } else if (x == 0 ){
                printf("|");
            } else if (y == 0) {
                printf("-");
            } else {
                printf(" ");
            }
            
            if (x == X_RANGE) {
                printf("\n");
            }
        }
    }
    
    
}


int getY(float a,float b,float c,float d , int x, int Y_RANGE) {
    float Y = 0;
    
    Y += a + b*x + c*pow(x,2) + d*pow(x,3);
    
    if (Y < 0 && (Y-Y_RANGE) < -0.5) {
        if((Y-(int)Y) <= -0.5)
            return (int)Y - 1;
        return (int)Y;
    } else if (Y > 0 && (Y-Y_RANGE) < 0.5) {
        if((Y-(int)Y) > 0.5)
            return (int)Y + 1;
        return (int)Y;
    } else if (Y == 0){
        return Y;
    }
    return 11;
}

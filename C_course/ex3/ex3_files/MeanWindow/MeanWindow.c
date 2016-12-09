#include "MeanWindow.h"
#include "MeanWindowHelperFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_COLUMN 100
#define MAX_ROW 100


void MeanWindow(const char *InFile, const char *OutFile)
{
    int dimens[3]; //  0 (n) - rows, 1 (m) - columns, 2 (w) - window
    int i,j;
    float A[4][4];
    float S[4][4];
    int windowSize;
    int r;
    int columns=4,rows=4;

    FILE *input_f = fopen(InFile, "r");

    if (input_f == NULL) {
        printf("could not open file\n");
    }
    
    // reading dimention from file
    for (i = 0 ; i < 3; i++)
    {
        fscanf(input_f,"%d",&dimens[i]);
        printf("i=%d -> %d \n",i,dimens[i]);
    }
    
    windowSize = dimens[2];
    r = (windowSize-1)/2;
    
    printf("w = %d\nr= %d\n", windowSize, r);
    
    // reading matrix from file
    for(i = 0; i < rows; i++)
    {
        for (j = 0 ; j < columns; j++)
        {
            fscanf(input_f,"%f",&A[i][j]);
            printf("%f ",A[i][j]);
        }
        printf("\n");
    }
    
    fclose(input_f);
    
    
    // adding up rowss in algorithm
    for (int i=0; i<rows; i++) {
        for (int j=1; j<columns; j++) {
            A[i][j] += A[i][j-1];
        }
    }
    
    // adding up columns as in the algorithm
    for (int j=0; j<columns; j++) {
        for (int i=1; i<rows; i++) {
            A[i][j] += A[i-1][j];
        }
    }
    
    
//    = A[i+r , j+r] ­- A[i­-r-­1 , j+r] ­- A[i+r , j­-r-­1] + A[i­-r-­1 , j­-r­-1];
    
    // avging cells by window
    for ( i=0;i < rows; i++) {
        for ( j=0;j < columns; j++) {
            float sum = 0;
            
            if((i+r) < rows && (j+r) < columns){
                sum += A[i+r][j+r];
            }
            if( (i-r-1)>0 && (j+r)<columns) {
                sum -= A[i-r-1][j+r];
            }
            if((i+r)<rows && (j-r-1)>0) {
                sum -= A[(i+r)][j-r-1];
            }
            if((i-r-1)>0 && (j-r-1)>0) {
                sum += A[i-r-1][j-r-1];
            }
            sum /= (windowSize*windowSize);
            S[i][j] = sum;
        }
    }
   
    printf("\n S= \n");

    // printing the output matrix
    for(i = 0; i < 4; i++)
    {
        for (j = 0 ; j < 4; j++)
        {
            printf("%f ",S[i][j]);
        }
        printf("\n");
    }
    
    
    // writing result to file
    
    FILE *out_f = fopen(OutFile, "w");
    if (out_f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    for (i=0; i<rows; i++) {
        for (j=0; j<columns; j++) {
            fprintf(out_f, "%f  ", S[i][j]);
        }
        fprintf(out_f, "\n");
    }
    
    fclose(out_f);
    
    
}


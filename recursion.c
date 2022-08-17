v/* Paul Fierman */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get.h"
void recurDerivative(int aVal, int bVal,int* curr){
        int* aVal_array = (int*)malloc(bVal* sizeof(int));
        if(bVal > 0) {
                aVal = getA(aVal,bVal);
                bVal = getB(bVal);
                aVal_array[*curr] = aVal;
                printf("derivative %d = %dx^%d\n", *curr+1, aVal_array[*curr],bVal);
                (*curr)+=1;
                recurDerivative(aVal, bVal, curr);
        } else {
                printf("derivative %d = %d\n", *curr+1, 0);
                free(aVal_array);
        }
}

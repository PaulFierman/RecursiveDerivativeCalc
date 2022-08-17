#include <string.h>
#include "get.h"
#include "recursion.h"

int main()
{
        printf("Please enter function in form of ax^b+c\n");

        char input[64];
        if (fgets(input, sizeof input, stdin)) {
                /* input has worked */
                printf("input = %s",input);
                /* get a */
                char a[2];
                /* incase a is multiple digits */
                char *xIndex = strstr(input, "x");
                int aLen;
                aLen = xIndex - input;
                memcpy(a, &input[0], aLen );
                a[aLen] = '\0';
                /* printf("a = %s\n", a); */
                int aVal = atoi(a);


                /* get b */
                char b[2];
                /* incase b is multiple digits */
                char *plusIndex = strstr(input, "+");
                int bLen = plusIndex - xIndex -2;
                memcpy(b, &input[aLen+2], bLen );
                b[bLen] = '\0';
                /* printf("b = %s\n", b); */
                int bVal =  atoi(b);

        /*
                * get c *
                char c[2];
                * incase c is multiple digits *
                char *endIndex = strstr(input, "\0");
                int cLen = endIndex - plusIndex;
                memcpy(c, &input[cLen],cLen);
                c[cLen] = '\0'; 
                printf("c = %s\n", c);
        */


        /*      
                int curr = 1;
                while(bVal > 0) { 
                        aVal = getA(aVal,bVal);
                        bVal = getB(bVal);      
                        printf(" derivative %d: %dx^%d\n",curr,aVal,bVal);
                        curr++;
                }
                printf(" derivative %d: %d\n",curr, 0);
        */

                int curr = 0;
                recurDerivative(aVal, bVal, &curr);
        }
        return 0;
}

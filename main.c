#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bigint.h"
int main()
{
    char *c1 = (char *) malloc(1000* sizeof(char));
    char *c2 = (char *) malloc(1000* sizeof(char));
    printf("enter two no:- ");
    scanf("%s",c1);
    getchar();
    scanf("%s",c2);
    printf("addition: ");
    add(c1, c2);
    printf("subtraction: ");
    sub(c1, c2);
    printf("multiplication: ");
    mul(c1, c2);
    printf("division: ");
    divide(c1, c2);
    return 0;
}

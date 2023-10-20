#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BigInteger.h"
int main()
{
    struct BigInteger a = initialize("4567865456");
    struct BigInteger b = initialize("2");
    display(a);
    display(b);
    struct BigInteger c = add(a,b);
    display(c);
    c = sub(a,b);
    display(c);
    c= mul(a,b);
    display(c);
    c = div1(a,b);
    display(c);
    return 0;
}
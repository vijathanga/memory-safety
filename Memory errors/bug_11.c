// There is a possible format string vulnerability in line 12


#include <stdio.h> 
#include <stdlib.h> 


int main() 
{ 
    /*@untainted@*/ char c[256];
    fgets(c, 200, stdin);
    printf(c);
}

// There is unwanted aliasing in line 16


#include <stdio.h> 
#include <stdlib.h> 

  
static char *p;


 static void func_1( /*@only@*/ /*@null@*/ char *i) 
{ 
    char *q = i; 

    // Unwanted aliasing
    p = q;
    free(i);
} 

   
int main() 
{ 
    /*@only@*/ char *k = malloc(5);
    func_1(k);
}

// There is a cross stack access error in this program


#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
static int *p;


/*@null@*/ static void func_1() 
{ 
    int q[1024]; 
    p = q;
    q[0] = 1;
} 


/*@null@*/ static void func_2() 
{ 
    // Cross stack access
    p[0] = 2;

} 
   
int main() 
{ 
    pthread_t t1, t2; 


    func_1();
    func_2();

    exit(0); 
}
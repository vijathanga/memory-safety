// There is a undefined memory acess error in function 'test'.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void test()
{
  char *buf = (char*) malloc(25);
  /*@unused@*/ char c = buf[0];  
  free(buf);

}

int main()
{
  test();
  return 0;
}

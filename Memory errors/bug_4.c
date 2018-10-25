// There is a double free error in function 'test'.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void test()
{
  /*@unused@*/ char *buf = (char*) malloc(25);
  free(buf);
  free(buf);

}

int main()
{
  test();
  return 0;
}

// There is a invalid memory access in line 14.  (Temporal memory error)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void test()
{
  char *buf = (char*) malloc(25);
  free(buf);

  buf[1] = 'a';

}

int main()
{
  test();
  return 0;
}

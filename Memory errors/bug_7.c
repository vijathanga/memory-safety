// There is a buffer over read in function 'create'.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void create( /*@temp@*/ char *buf)
/*@requires maxRead(buf) >= 256@*/
{
  /*@unused@*/ char c = buf[200];
}

int main()
{
  /*@only@*/ char *p = (char*) malloc(25);
  create(p);

  free(p);
  return 0;
}

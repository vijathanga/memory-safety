// There is null pointer dereferencing in line 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void create( /*@notnull@*/ char *buf)
/*@requires maxRead(buf) >= 256@*/
{
  /*@unused@*/ char c = buf[21];
}

int main()
{
  /*@only@*/ char *p = NULL;
  create(p);

  free(p);
  return 0;
}

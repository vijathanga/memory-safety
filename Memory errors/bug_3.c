// There is a memory leak in function 'copy'.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void copy(/*@unused@*/ char *data)
{
  /*@unused@*/ char *buf = (char*) malloc(25);

}

int main()
{
  copy("copy_data");
  return 0;
}

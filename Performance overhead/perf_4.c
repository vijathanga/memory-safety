/* 
  In this code, large number of heap and stack allocations are done
  to determine overhead introduced by SoftBound+CETS and Splint.
  Heap deallocation is not done.

  Result - SoftBound+CETS has a memory leak even when pointers are deallocated.
           This is attributed to the stale keys in meta data table.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void assign() {

  char a[256];
  int i;
  for (i=0; i<25; i++)
    a[i] = 'a' + i;

  char *c = malloc(256);

  for (i=0; i<120; i++, c++)
    *c = 'a' + i;
}

int main(int argc, char *argv[])
{
  int i,j,k;

  for(j=0; j<400; j++) {
    for(i=0; i<2000; i++) {
      assign();
    }

  }

  return 0;
}
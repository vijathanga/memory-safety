/* 
  In this code, large number of heap allocation and partial deallocations are done
  to determine overhead introduced by SoftBound+CETS and Splint

  Result - SoftBound+CETS has a memory leak even when pointers are deallocated.
           This is attributed to the stale keys in meta data table.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void assign(char *a) {

  int i;
  for (i=0; i<25; i++)
    a[i] = 'a' + i;
}

int main(int argc, char *argv[])
{

  char *ptr_1[200000];
  char *ptr_2[200000];

  int i,j,k;

  for(j=0; j<200; j++) {
    for(i=0; i<20000; i++) {
      char *buf = malloc(200);
      assign(buf);
      ptr_1[i] = buf;
      ptr_2[i] = buf;
 
    }

    for (int k=0; k<200; k++)
      free(ptr_1[k]);
  }

  


  return 0;
}
// There is a possible out of bound buffer access in line 9.  (Spatial memory error)

#include <stdio.h>

char *STR = "Hello World";

void copy(char * str)
{
    strcpy (str, STR);
}

void copySafe (char * str, size_t strSize)
/*@requires maxSet(str) >= strSize @*/
{
  strncpy (str, STR, strSize -1); 
  str[strSize -1] = '/0';
}

int main() {
    char a[2];
    copySafe (a, 2);
    copy(a);
}
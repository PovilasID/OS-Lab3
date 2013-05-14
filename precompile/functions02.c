#ifndef FUNCTIONS02_C
#define FUNCTIONS02_C

#if __INCLUDE_LEVEL__ == 0
#include <unistd.h>
#include <errno.h>
int main() {
   return function2();
}
#endif
#include <stdio.h>
#include "functions01.c"
int function2(){
   int x;
   x = function1();
   printf("%d \n",x);
   return function1();
}
#endif
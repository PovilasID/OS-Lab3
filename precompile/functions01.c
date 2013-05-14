#ifndef FUNCTIONS01_C
#define FUNCTIONS01_C
int function1();
#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main() {
   return function1();
}
#endif

int function1(){
   return 10;
}
#endif
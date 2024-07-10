#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

int rand(void){
int (*real_rand)(void) = NULL;
real_rand = dlsym(RTLD_NEXT, "rand");
int random_number = real_rand();
printf("  -> Generated Number: %i\n", random_number);
return random_number;
}

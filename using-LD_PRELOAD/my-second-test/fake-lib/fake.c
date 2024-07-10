#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

ssize_t write(int fd, const void buf[.count], size_t count){
ssize_t (*real_fnc)(int f, const void bf[.cnt], size_t cnt) = dlsym(RTLD_NEXT, "write");
ssize_t s = real_fnc(fd, "Hello World\n", count);
return s;

}

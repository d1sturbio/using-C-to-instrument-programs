#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

  char foo[] = "This is some text from program 1";

  printf("  ./prog2  %d  %lx  %lu\n", getpid(), (long unsigned int) foo, strlen(foo)+1);

  printf("Press any key\n");
  getchar();

  printf("the foo is: %s\n", foo);

}

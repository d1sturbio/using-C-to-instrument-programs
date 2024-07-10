#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
  // argc must be 4 :)
  if (argc != 4) {
    printf("./prog2  pid  addr  length\n");
    exit(1);
  }
  // gets the args
  int pid  = strtol (argv[1], NULL, 10);
  unsigned long addr = strtoul(argv[2], NULL, 16);
  int len  = strtol (argv[3], NULL, 10);

  char* proc_mem = malloc(50); // alloc path string
  sprintf(proc_mem, "/proc/%d/mem", pid); // make the path to the file "mem" of the process

  printf("opening %s, address is %ld\n", proc_mem, addr);
  int fd_proc_mem = open(proc_mem, O_RDWR); // open fd to read/write in /proc/mem
  if (fd_proc_mem == -1) {
    printf("Could not open %s\n", proc_mem); // exit if can't open fd
    exit(1);
  }

  char* buf = malloc(len); // alloc buffer

  lseek(fd_proc_mem, addr, SEEK_SET); //seek for address in fd
  read (fd_proc_mem, buf , len     ); //read what is in the address

  printf("String at %ld in process %d is:\n", addr, pid);
  printf("  %s\n", buf); // string in mem

  printf("\nNow, this string is modified\n"); // simple message
  strncpy(buf, "Hello from prog2", len); // copy string to buff

  lseek(fd_proc_mem, addr, SEEK_SET); // seek for address again
  if (write (fd_proc_mem, buf , len     ) == -1) { // overwrite string in memory
     printf("Error while writing\n"); // exit if can't overwrite string in memory
     exit(1);
  }
  // free memory
  free(buf);
  free(proc_mem);
  return 0;
}

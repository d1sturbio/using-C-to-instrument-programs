#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
srand(time(NULL));
int number = rand() % 101;
printf("The number is %i\n", number);
return 0;
}

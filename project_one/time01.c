#include <stdio.h>
#include <time.h> // the time.h header file is required, lest the compiler become cross to you

int main () {

  time_t now;

  time(&now);  // the & address of operator
  printf("The computer thinks it's %ld\n",now); 
  printf("%s",ctime(&now)); // its require a pointer arg and returns a string appended new line 

  return(0);
}

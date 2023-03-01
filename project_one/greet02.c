#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc<2){ // the argument count is always 1 for the program name;if print default message
    puts("Hellow, your buddy!");
  }else{
    printf("Hello, %s!\n",argv[1]); // the first typed after program name is represanted as arg[]
  }
  return(0);
}

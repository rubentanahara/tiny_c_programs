#include <stdio.h>
#include <time.h>

int main(){
  
  time_t now;
  struct tm *clock;// Because localtime returns a pointer, it's better to declare the struc as a pointer

  time(&now);
  clock = localtime(&now);
  puts("Time details:");
  printf(" Day of the year: %d\n", clock->tm_yday);
  printf(" Day of the week: %d\n", clock->tm_wday); //The first day of the week is 0 for Sunday
  printf("            Year: %d\n", clock->tm_year+1900); //add 1900
  printf("           Month: %d\n", clock->tm_mon+1);//the tm_mon member ranges from 0 to 11
  printf("Day of the month: %d\n", clock->tm_mday);
  printf("            Hour: %d\n", clock->tm_hour);
  printf("          Minute: %d\n", clock->tm_min);
  printf("          Second: %d\n", clock->tm_sec);
  
  return(0);
}

/*
 * struct tm is a data struct to represent DateTime data , is standard library from time.h 
 * it has the following fields
 * tm_sec
 * tm_min
 * tm_hour
 * tm_mday
 * tm_mon
 * tm_year
 * tm_wday
 * tm_yday
 * tm_isdst
 *
 * */

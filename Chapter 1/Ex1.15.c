/* Ex 1.15 from "The C Programming Language" by Kernighan & Ritchie

   Rewrite the temperature conversion program of Section 1.2 to
   use a function for conversion

   https://github.com/andrea-come

   2025 07 15
*/


#include <stdio.h>

// Function that approximately converts from fahrenheit to celsius
int fahrenheit_to_celsius(int f);


int main(void)
{
  int f,            // temperature in fahrenheit degrees
      lower = 0,    // lower limit of temperature
      upper = 300,  // upper limit
      step  = 20;   // step size
  
  f = lower;
  while(f <= upper){
    printf("%3d °F = %3d °C\n", f, fahrenheit_to_celsius(f) );
    f += step;
  }
  
  return 0;
}


int fahrenheit_to_celsius(int f){
  return 5 * (f - 32) / 9;
}

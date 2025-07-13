/* Ex 1.9 from "The C Programming Language" by Kernighan & Ritchie
   
   Write a program to copy its input to its output, replacing each
   string of one or more blanks by a single blank

   https://github.com/andrea-come
   
   2025 07 13
*/

#include <stdio.h>

int main(void)
{
  int c,      // input character
      nb = 0; // number of blanks

  while( (c = getchar()) != EOF ) {
    if(c == ' '){
      nb++;
      if(nb < 2) { putchar(c); }
    }        
    else {
      putchar(c);
      nb = 0; 
    }       
  }
   
  return 0;
}

/* Ex 1.12 from "The C Programming Language" by Kernighan & Ritchie
   
   Write a program that prints its input to its output, one word per line.

   2025 07 15
*/

#define OUT_WORD 0
#define IN_WORD 1

#include <stdio.h>

int main(void)
{
  int c, state = OUT_WORD;      
       
  while( (c = getchar()) != EOF ) {
    if( c == ' ' || c == '\t'|| c == ',' || c == ';' ||
        c == '.' || c == ':' || c == '!' || c == '?' || c == '\n')
    {
      if(state) {
        putchar('\n');
        state = OUT_WORD;
      }
    } 
    else {
      putchar(c);
      state = IN_WORD;
    }       
  }
  
  if( state == IN_WORD){
    putchar('\n');
  }
  
  return 0;
}

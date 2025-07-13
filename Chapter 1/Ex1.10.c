/* Ex 1.10 from "The C Programming Language" by Kernighan & Ritchie
   
   Write a program to copy its input to its output, replacing each
   tab by \t, each backspace by \b, and each backslash by \\.
   This makes tabs and backspace visible in an unambiguos way.

   https://github.com/andrea-come

   2025 07 13
*/

#include <stdio.h>

int main(void)
{
  int c;  // input character
        
  while( (c = getchar()) != EOF ) {
    if(c == '\t')      { fputs("\\t", stdout); }  // fputs to avoid newline
    else if(c == '\b') { fputs("\\b", stdout); }
    else if(c == '\\') { fputs("\\\\", stdout); }
    else               { putchar(c); }       
  }
    
    return 0;
}

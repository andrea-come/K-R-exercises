/* Ex 1.18 from "The C Programming Language" by Kernighan & Ritchie

   Write a program to remove trailing blanks and tabs from each line of
   input, and to delete entirely blank lines

   Alternative version: see `remove_extra_blanks` description
   
   https://github.com/andrea-come

   2025 07 22 
*/

#include <stdio.h>

#define MAX_LINE_LEN 100

/* Read input from stdin, remove redundant blanks (spaces, tabs) and newlines.
   Keep only a single space or newline where appropriate.
   Return the number of characters written to the output buffer.
*/
int remove_extra_blanks(char str[], int max_len);



int main(void)
{
  char str[MAX_LINE_LEN];
  if( remove_extra_blanks(str, MAX_LINE_LEN)> 0 ){
    puts("\n--------------------------------------");    
    printf("%s\n", str);
  }
  puts("");
  return 0;
}



int remove_extra_blanks(char s[], int len){
  int i = 0, c,  
      found_nl = 0,     // flag: last character was a newline
      found_blank = 0;  // flag last character was a space or tab  
  while( i < len -1 && (c = getchar()) != EOF ){
    if( c == '\n'){
      // Skip newline if at the beginning or if the previous character was also a newline
      if( !(i == 0 || found_nl)) { 
        s[i++] = c; 
      }
      found_nl = 1;
      found_blank = 0;
    }
    else if( c == ' ' || c == '\t'){
      // Skip blank if at the beginning, after another blank, or after a newline
      if( !(i == 0 || found_blank || found_nl)) {
        s[i++] = ' ';
      }
      found_blank = 1;
      found_nl = 0;
    }
    else {
      found_nl = found_blank = 0;
      s[i++] = c;    
    }
  }
  
  // Trim trailing newline, space, or tab if present
  if( i > 0 && (s[i-1] == '\n' || s[i-1] == ' ' || s[i-1] == '\t')) {
    s[i-1]  = '\0';
    i--;  
  } 
  else {
    s[i] = '\0';   // Ensure null-terminated string
  }

  return i;
}

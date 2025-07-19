/* Ex 1.17 from "The C Programming Language" by Kernighan & Ritchie

   Write a program to print all input lines that are longer than 80 characters
   
   https://github.com/andrea-come

   2025 07 18
*/

#include <stdio.h>

#define MIN_LINE_LEN 80   // Minimum length required to print a line
#define MAX_LINE_LEN 1000 // Maximum size of input buffer (including null terminator)


// Reads a line into `s` (up to `max_len`), returns total line length
int get_line(char s[], int max_len);



int main(void)
{
  char line[MAX_LINE_LEN];  
  int len = 0;  
 
  while( (len = get_line(line, MAX_LINE_LEN)) > 0){
    if(len > MIN_LINE_LEN){
      if(len >= MAX_LINE_LEN){
        printf("Current line exceeds buffer capacity of %d characters "
               "(excluding null terminator), the stored portion is:\n", 
               MAX_LINE_LEN - 1);
      }
      printf("%s", line);
    }
  }

  return 0;
}



int get_line(char s[], int max_len){
  int c,
      i = 0;

  for(; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; i++){
    s[i] = c;
  }
  if(c == '\n'){  // empty line case
    s[i++] = c;
  }   
  s[i] = '\0';
   
  // Flush remaining chars if line too long
  if(c != '\n' && c != EOF){
    while( (c = getchar()) != '\n' && c != EOF){ 
      i++;
    }
    if(c == '\n'){
      i++;
    }
  }
  
  return i;
}

/* Ex 1.16 from "The C Programming Language" by Kernighan & Ritchie

   Revise the main routine of the longest-line program so it will correctly
   print the length of arbitrart long input lines, and as much as possible 
   of the text
   
   https://github.com/andrea-come

   2025 07 17
*/

#include <stdio.h>

#define MAX_LEN 80

// Function that reads an input line, stores it in `s` (up to `max_len`) 
//  and returns its length
int get_line(char s[], int max_len);

// Function that copy a string `src` into a string `dst`, assuming
//  `dst` is long enough
void copy_string(char src[], char dst[]);



int main(void)
{
  int len,                     // current line length
      max = 0;                 // max length so far
  char line[MAX_LEN] = {},     // current input line
       longest[MAX_LEN] = {};  // longest line so far

  while( (len = get_line(line, MAX_LEN)) > 0){
    if(len > max){
      max = len;
      copy_string(line, longest);
    }
  }
  
  
  if(max > 0){
    printf("Longest line is %d characters long ", max);
    
    if(max > MAX_LEN){ // Check if `line` is too long
      printf("and exceeds buffer capacity of %d characters "
             "(excluding null terminator),\n"
             "the stored portion is:\n%s", 
             MAX_LEN -1, longest);
    } else {
      printf("and is:\n%s", longest);
    }  
  }  

  return 0;
}



int get_line(char s[], int max_len){
  int c,
      i = 0;  
  for(i; i < max_len-1 && (c = getchar()) != EOF && c != '\n'; i++){
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

void copy_string(char src[], char dst[]){
  int i = 0;
  while( (dst[i] = src[i]) != '\0'){
    i++;
  }
}

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

  while( (len = get_line(line, MAX_LEN)) > 0 ){
    if(len > max) {
      max = len;
      copy_string(line, longest);
    }
  }
  
  // Check if `line` is too long  
  if(len > MAX_LEN){
    printf("Curent line is longer than %d characters ", MAX_LEN - 1);
    printf("(including newline and null character),\n");
    // Print what stored    
    printf("the first part of it is:\n%s", longest);
  }

  else{
    printf("Longest string is %d characters long and is:\n%s", max, longest);
  }  

  return 0;
}



int get_line(char s[], int max_len){
  int c,
      i = 0;  
  for(i; i < max_len-1 && (c = getchar()) != EOF && c != '\n'; i++){
		s[i] = c;
	}
  if(c == '\n'){ s[i++] = c; }  // empty line case 
  s[i] = '\0';
   
  // Clean buffer if current line is too long
  if( c != '\n' && c != EOF){
    while( (c = getchar()) != '\n' && c != EOF ) { i++; }
    if( c == '\n') { i++; }
  }


  return i;
}

void copy_string(char src[], char dst[]){
  int i = 0;
  while( (dst[i] = src[i]) != '\0') { i++; }
}

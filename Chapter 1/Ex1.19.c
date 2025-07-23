/* Ex 1.19 from "The C Programming Language" by Kernighan & Ritchie

   Write a function `reverse(s)` that reverses the character string `s`.
   Use it to write a program that reverses its input a line at a time.
   
   https://github.com/andrea-come

   2025 07 23
*/

#include <stdio.h>

#define MAX_LINE_LEN 80

// Read an input line, store it in `s` (up to `max_len`) and return its length
int get_line(char s[], int max_len);
// Reverse a character string
void reverse(char s[], int len);



int main(void)
{
  char str[MAX_LINE_LEN];
  int len = 0;
  while( (len = get_line(str, MAX_LINE_LEN)) > 0 ){
    reverse(str, len);  
    printf("%s", str);
  }
  puts("");

  return 0;
}



int get_line(char s[], int max_len){
  int c, i = 0;  
  for(; i < max_len-1 && (c = getchar()) != EOF && c != '\n'; i++){
		s[i] = c;
	}
  if(c == '\n'){ s[i++] = c; }  // empty line   
  s[i] = '\0';
   
  // Flush remaining chars if line too long
  if(c != '\n' && c != EOF){
    while( (c = getchar()) != '\n' && c != EOF){ i++; }
    if(c == '\n'){ i++; }
  }
  return i;
}


void reverse(char s[], int len){
  // Check if '\n' is the last not null character
  int end = len - 1;                 
  if(end > 0 && s[end] == '\n'){ end--; }
        
  for(int i = 0; i <= end/2; i++){
    char t = s[i];
    s[i] = s[end - i];  
    s[end - i ] = t;    
  }  
}  

/* Ex 1.14 from "The C Programming Language" by Kernighan & Ritchie

   Write a program to print a histogram of the frequencies
   of different characters in its inputs

   https://github.com/andrea-come

   2025 07 15 second version, with histogram
*/

#include <stdio.h>

#define NUM_OF_LETTERS 26

int main(void)
{
  int ch,
      ch_arr[NUM_OF_LETTERS];

  for(int i = 0; i < NUM_OF_LETTERS; i++){ ch_arr[i] = 0; }

  while( (ch = getchar()) != EOF ) {
    if('a' <= ch && ch <= 'z')      { ++ch_arr[ch - 'a']; }
    else if('A' <= ch && ch <= 'Z') { ++ch_arr[ch - 'A']; }
  }

  for(int i = 0; i < NUM_OF_LETTERS; i++){
    if(ch_arr[i] != 0){ printf("%c: %02d\n", i + 'a', ch_arr[i]); }
  }

  int max_height = 0;
  for(int i = 0; i < NUM_OF_LETTERS; i++){ 
    if(ch_arr[i] >= max_height){ max_height = ch_arr[i]; }
  }

  for(int row = max_height; row > 0; row--){
    for(int i = 0; i < NUM_OF_LETTERS; i++){
      if(ch_arr[i] != 0){
        if(ch_arr[i] >= row){ printf("%s", " *** "); }
        else                { printf("%s", "     "); }
      }
    }
    puts("");
  }
  
  for(int i = 0; i < NUM_OF_LETTERS; i++){
    if(ch_arr[i] != 0){ printf(" %c%c%c ", i + 'a', '/', i+ 'A'); }
  }
  puts("");

  return 0;
}

/* Ex 1.13 from "The C Programming Language" by Kernighan & Ritchie

   Write a program to print a histogram of the lengths of words in its input.
   
   https://github.com/andrea-come

   2025 07 15
*/

/* 
   According to Wikipedia the longest English word in a major dictionary is
   "pneumonoultramicroscopicsilicovolcanoconiosis", 45 letters long.
   https://en.wikipedia.org/wiki/Longest_word_in_English
*/

#define MAX_LEN 46 

#include <stdio.h>


int main(void)
{
  int c,                   // input character
      len = 0,             // length of the actual word
      len_arr[MAX_LEN],    // array of lengths
      in_word = 0,         // flag: inside a word?
      prev_is_letter = 0,  // flag: previous char is a letter?
      pending_hyphen = 0;  // count the number of hyphens
  
  for(int i = 0; i < MAX_LEN; i++ ){
    len_arr[i] = 0;
  }

  while( (c = getchar()) != EOF){
    // Inside a word        
    if( ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ){  
      len++;  // update word's length
      in_word = 1;
      prev_is_letter = 1;
      if( pending_hyphen > 0 ){ 
        len++;               // Count only one hyphen 
        pending_hyphen = 0;  
      }
    }
    // internal apostrophe
    else if(c == '\'' && in_word && prev_is_letter) { 
      len++;
      prev_is_letter = 0;
      pending_hyphen = 0;
    }
    // internal hyphen
    else if( c == '-' && in_word && prev_is_letter){
      pending_hyphen++;   
      prev_is_letter = 0;  
    }
    else {
      // discarding extra blanks and punctuation
      if(len > 0 && len < MAX_LEN && pending_hyphen == 0){       
        len_arr[len]++;  // update the array of lengths at index relative to
      }                  //  previous word's length
      len = 0;           // reset for upcoming word
      in_word = 0;
      prev_is_letter = 0;
      pending_hyphen = 0;
    }   
  }
  
  // Handle word at EOF
  if (len > 0 && len < MAX_LEN && pending_hyphen == 0) {
    len_arr[len]++;
  }


  puts("");
          
  // Horizontal orientation histogram
  for( int i = 1; i < MAX_LEN; i++ ) {
    if( len_arr[i] != 0 ) {
      printf("length %2d: ", i);
      for(int j = 0; j < len_arr[i]; j++){ putchar('#'); }
      puts("");
    }
  }
  
  puts("");

  // Vertcal orientation histogram
  int max = 0;  //max value in the array
  for( int i = 1; i < MAX_LEN; i++ ){
    if( len_arr[i] > max ) { max = len_arr[i]; }
  }
    
  for( int row = max; row > 0; row-- ) {
    for( int i = 1; i < MAX_LEN; i++ ){
      if( len_arr[i] != 0 ) {
        if( len_arr[i] == row )     { printf(" #### "); }
        else if( len_arr[i] > row ) { printf(" |  | "); }
        else                        { printf("      "); }
      }
    }
    puts(""); 
  }
  for( int i = 1; i < MAX_LEN; i++ ){
      if( len_arr[i] != 0 ) { printf("  %02d  ", i); }
  }
  
  puts("");

  return 0;
}

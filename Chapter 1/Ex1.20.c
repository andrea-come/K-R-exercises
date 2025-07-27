/* Ex 1.20 from "The C Programming Language" by Kernighan & Ritchie

   Write a program `detab` that replaces tabs in the input with the proper
   number of blanks to space to the next tab stop. Assume a fixed set of
   tab stops, say every `n` columns.

   https://github.com/andrea-come

   2025 07 27
*/

#include <stdio.h>

#define MAX_LEN 1000  
#define TAB_STOPS 4   // e.g., every 4 columns


// Reads an input line, stores it into array `s` (up to `max_len`) 
//  and returns its length (including the newline character, if present).
int get_line(char s[], int max_len);

// Replaces a tab at position `pos` in string `s` with `n_blanks` blanks.
// Shifts the subsequent characters to the right to make room.
// The function assumes `s` has space for at least `max_len` characters.
// Returns 0 on success, or -1 if there's not enough space.
int detab(char s[], int n_blanks, int pos, int len, int max_len);

// Clears the string `s` by setting all characters up to `len` 
//  (or `max_len`, whichever is smaller) to '\0'.
void clean_string(char s[], int len, int max_len);



int main(void)
{
	char line[MAX_LEN];
	int len;
    
  while( (len = get_line(line, MAX_LEN)) > 0 ){
  	for(int i = 0; i < len; i++){
    	if(line[i] == '\t'){
      	// Compute the number of blanks needed to reach the next tab stop
        int n_blanks = TAB_STOPS - (i % TAB_STOPS);
        
        // Replace tab with blanks
        if( !detab(line, n_blanks, i, len, MAX_LEN) ){
          len += n_blanks;
          i += n_blanks - 1;  // Skip over the newly inserted blanks
        }
      }
    }
    printf("%s\n", line);
    
    // Clear the string for the next iteration
    clean_string(line, len, MAX_LEN);
  }
	
	return 0;
}



int get_line(char s[], int max_len){
  int c,
      i = 0;  
  for(; i < max_len-1 && (c = getchar()) != EOF && c != '\n'; i++){
		s[i] = c;
	}
  if(c == '\n'){  // empty line case
    s[i++] = c;
  }   
  s[i] = '\0';
   
   // Discard the rest of the line if it's too long
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

void clean_string(char s[], int len, int max_len){
  int end = len < max_len? len : max_len;
  for(int i = 0; i < end; i++){
      s[i] = '\0';
  }
}


int detab(char s[], int n_blanks, int pos, int len, int max_len){

  // Check if there is enough space to insert `n_blanks` characters
  if(len + n_blanks > max_len - 1) {
		return -1;  // Not enough space
	}

  if(pos < len){
    // Shift characters to the right to make room
    // Subtract 1 from n_blanks since the tab character will be overwritten
	  for(int i = len - 1 + n_blanks - 1; i > pos; i--){
      s[i] = s[i - n_blanks + 1];
    }

	   // Insert `n_blanks` characters in place of the tab 
	  for(int i = pos; i < pos + n_blanks; i++){
      s[i] = '*';  // debug: use ' ' for actual output
    }
	} 
	
	return 0;
}

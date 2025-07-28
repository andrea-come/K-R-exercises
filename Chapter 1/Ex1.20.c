#include <stdio.h>

#define MAX_LEN 1000  
#define TAB_STOPS 4   // e.g., every 4 columns


// Reads input from `stdin`, stores it into array `s` (up to `max_len`) 
//  and returns its length (including the newline character, if present).
int get_string(char s[], int max_len);

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
	char str[MAX_LEN] = {0};
	int len;
  
  while( (len = get_string(str, MAX_LEN)) > 0 ){
    for(int i = 0; i < len; i++){
      if(str[i] == '\t'){
        // Compute the number of blanks needed to reach the next tab stop
        int n_blanks = TAB_STOPS - (i % TAB_STOPS);
        
        // Replace tab with blanks
        if( !detab(str, n_blanks, i, len, MAX_LEN) ){
          len += n_blanks;
          i += n_blanks - 1;  // Skip over the newly inserted blanks
        }
      }
    }
    printf("%s\n", str);
    
    // Clear the string for the next iteration
    clean_string(str, len, MAX_LEN);
  }
	return 0;
}



int get_string(char s[], int max_len){
  int c,
      i = 0;  
  for(; i < max_len-1 && (c = getchar()) != EOF; i++){
		s[i] = c;
	}
     
  s[i] = '\0';
   
  while( (c = getchar()) != '\n' && c != EOF){ 
    i++;
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

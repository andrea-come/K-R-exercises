#include <stdio.h>

#define MAX_LINE_LEN 13
#define TOO_LONG -2          // get_line()

#define INVALID_INPUT -2     // insert_n_copies()
#define NOT_ENOUGH_SPACE -1  // insert_n_copies()

/* Reads a line of input from `stdin` and stores it in string `s`,
    writing at most `max_len - 1` characters plus the null terminator.
    Ensures the string is always null-terminated.
    Ends line with a '\n' if space allows or the input line includes it.
   Returns the line length (including null terminator) if line fits in `s`,
    or `TOO_LONG` if the line was truncated due to insufficient space.
*/
int get_line(char s[], int max_len){
	int c,
		  i = 0;
	// Read until '\n', EOF, or buffer is full (leaving space for '\n' and '\0')
	while( i < max_len - 1 && (c = getchar()) != EOF && c != '\n' ){
		s[i++] = c;
	}
	
	if( i < max_len - 1 ){  // There is enough space to append '\n' and '\0' 
		s[i++] = '\n';        
		s[i] = '\0';          
	}
	
	else {  
    // only one more character can be stored  
    /*********************************************************************
     * Ctrl-D (EOF) is only effective when typed at the beginning of an  *
     * empty line; otherwise, it is ignored by the terminal and the      *
     * full line is passed on ENTER.                                     *
    *********************************************************************/         
		if( (c = getchar()) == EOF){  // Input ends here, store '\0'.
	  	s[i] = '\0';
	  }
	  else{             // Input is too long,
	  	s[--i] = '\n';  // Overwrite last valid character with '\n'
	    s[++i] = '\0';  // Append string terminator
	    i = TOO_LONG;   // Signal that the line was too long
      
      // Discard the rest of the line
	    while( (c = getchar()) != EOF && c != '\n'){ ; }
	  }
	}
  
	return i;
}


/* Inserts `n` copies of character `c` into string `s` at position `pos`.
    Characters from position `pos` onwards are shifted right to make space.
    The string must be null-terminated and have space for at least 
    `max_len` characters.
   Returns 0 on success, -1 if there's not enough space, 
    -2 if position is negative or bigger than `max_len` - 1.
*/
int insert_n_copies(char s[], char c, int n, int pos, int len, int max_len){
	if(pos < 0 || pos > max_len - 1 || n < 0){
    return INVALID_INPUT;
  }	
	if( len + n > max_len - 1){
    return NOT_ENOUGH_SPACE;
  }
	
	if(pos < len && s[pos] != '\n'){
		// Shift characters to the right to make room
		for(int i = len - 1 + n; i >= pos + n; i--){
			s[i] = s[i - n];
		}
	}
	else if(s[pos] == '\n' ){
		// Move '\n' to the end of the string, then add '\0'
		s[pos + n] = '\n';
		s[pos + n + 1] = '\0';
	}
	else{
	// Fill intermediate positions with '#' for debug, ' ' in the final version 
		for(int i = len - 1; i < pos; i++ ){
			s[i] = '#';
		}
	}

	// Insert `n` copies of character `c`
	for(int i = pos; i < pos + n; i++){
    s[i] = c;
  }

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


extern char *  pop();
extern void push(char *);

extern int isEmpty(); // imported extras

int main(int argc, char * argv[])
{
  int ch;
  while ((ch = getchar()) != EOF) { // getchar returns ASCII (int) repping the character,  EOF returns -1 so that's why int
      
      if (ch == '<') { // upon encountering start tag

      int EndTagStatus = 0; // end tage status
      char tag[100]; // hopefully tag name is less than 100 chars
      int i = 0;

      ch = getchar(); // read next char 
		
		//check for end tag status
      if (ch == '/') {
        EndTagStatus = 1;
        ch = getchar(); // read next char
      }

      // read tag name, store into tag array
      while (isalpha(ch)) {
        tag[i] = ch;
        i++;
        ch = getchar(); // read next char
      }
      tag[i] = '\0'; //null terminator so we can turn into string later

      if (!EndTagStatus) {
        // start tag
        char * copy = malloc(i + 1); // dynamic array same length as tag (i+1) includes null terminator
        for (int j = 0; j <= i; j++) { // copy tag to 'copy'
		copy[j] = tag[j];
		}
        push(copy);
      } else {
        // end tag
        char * topTag = pop();
		if (topTag == NULL) {printf("Invalid XML\n"); exit(0);}
		
		int j = 0;
		while (1) {
		//check if prior tag is same, while loop since gotta be careful about mismatching string lengths
			if (topTag[j] != tag[j]) {
				printf("Invalid XML\n");
				exit(0);
			}
			if (topTag[j] == '\0') break;
			j++;
		}
		
		free(topTag); // free memory allocated by malloc
		

        
      }
	}
    // 



  } // while loop terminate
  
  //validate isEmpty now or not
  if (isEmpty()) {
    printf("Valid XML\n");
  } else {
    printf("Invalid XML\n");
  }
  
  exit(0);
}

// why char * and not just char ? is char * just a string (character array)?

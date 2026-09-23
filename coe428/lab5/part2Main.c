#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);

//extra imports
extern int isEmpty();
extern void addHeap(int);
extern int heapDelete();
extern int heapSize();
extern void printXML(int);

int main(int argc, char * argv[])
{
  int value;
  //read and place into heap
  while (scanf("%d", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    addHeap(value);
  }
  // printXML before deleting
  printf("\n\n");
  printXML(0);
  printf("\n\n");
  
  // delete from heap, push to stack (sorted greatest to least)
  while (heapSize() > 0) {
    int x = heapDelete(); // returns max
    printf("%d\n", x); // prints max
    push(x); // pushes max to stack
  }
  
  // reverse using intStack
  while (!isEmpty()) {
    printf("%d\n", pop());
  }

  
  exit(0);
}

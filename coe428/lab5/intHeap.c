/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
#include <stdio.h>

static int heap[100];
static int size = 0;

void swap(int *a, int *b) { //swap function will come in handy later
  int temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete() // basically need to return heap[0] and also rearrange the heap 
{
  if (size == 0) return -1; //if heap is empty return error/false

  int max = heap[0]; // max will be top node.
  heap[0] = heap[size - 1]; // move last element to root node
  size--;

  int i = 0;

  // rearrange to have last element ( currently at parent node ) bubble down to its new place
  while (1) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i; // assume current node is largest for now

    if (left < size && heap[left] > heap[largest]) //switch left with top node if left is larger
      largest = left;

    if (right < size && heap[right] > heap[largest]) //switch right with larger between top node or left (if right is larger than either)
      largest = right;

    if (largest != i) { // swap between largest and the non largest value
      swap(&heap[i], &heap[largest]);
      i = largest; // update i to the node we were at
    } else break; // terminate while loop when we're done rearranging
  }

  return max;
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  heap[size] = thing2add; //set latest indice to thing2add
  int i = size; // size b4 thing2add
  size++;

  // rearrange to have new elemenbt element ( currently at latest indice ) bubble up to its new place
  while (i > 0) {
    int parent = (i - 1) / 2; // this took a while to get. (i-1) in case we start at a rightmost node
    if (heap[parent] < heap[i]) { // keep swapping up until the parent is greater
      swap(&heap[parent], &heap[i]);
      i = parent;
    } else break;
  }
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;  
}

//printing to XML
void printXML(int i)
{
  //if (i >= size) return; // termination. should be an unnecessary safety net. but assuming improper use in main, wouldn't want things to break.

  printf("<node id=\"%d\">", heap[i]);

  int left = 2*i + 1; 
  int right = 2*i + 2;

  if (left < size) {printXML(left);} // print left node
  if (right < size) {printXML(right);} // print right node

  printf("</node>");
} 

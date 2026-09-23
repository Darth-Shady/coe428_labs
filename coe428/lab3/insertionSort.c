#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
		// mycopy(copy,paste)  mycompare(a,b) returns a-b  myswap(a,b) just swaps
		// first == index of first element in an array to sort , last == last. meant for sorting subarrays of arrays. both are inclusive [first,last]
		// therefore num elements sorted is last - first + 1
		// when sorting a full array we'd call mySort(data, 0, n-1) since last is = to the last index, NOT THE NUMBER OF ELEMENTS
		
		
		unsigned int i,j;
		int key;
		
		//pass loop
		for (i = first; i < last ; i++ ) { // one sorted element per pass. stops at n-2 since the last comparison we should do is arr[n-1] < arr[n-2] 
			// (can't access arr[n] or we'll get memory garbage)
			// int key = array[i+1]; 
			myCopy(&array[i+1], &key); //set key to next elem
				
				
			j = i;
				while (j >= first && (myCompare(array[j], key) > 0) ) { /* if current elem is greater than key, then overwrite key with curr elem and shift all prior elems right 
					 until we get to the spot for key, where arr[some index] !> key */
					//array[j+1] = array[j]; // slides the larger curr elem to the right 
					myCopy(&array[j], &array[j+1]);
					
					//since j is an unsigned int, to be safe in the case that first is 0
					if (j == first) {
						break;
					}
					
					j--;
				}	
				
			//array[j+1] = key; 
			myCopy(&key,&array[j+1]);
		}
    }

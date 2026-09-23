#include "mySort.h"

void merge(int data[],unsigned int first, unsigned int mid, unsigned int last) {
	int temp[999]; // assuming this lab doesn't ask for sorting above 999 elements, or anywhere near 999
	unsigned int i = first; // left half
	unsigned int j = mid + 1; // right half
	unsigned int k = first; // for temp 
	
	while (i <= mid && j <= last) { //while iterating through both halves
		
		if (myCompare(data[i], data[j]) <= 0) { // zigzag comparisons.  
            myCopy(&data[i], &temp[k]);
            i++;
        }
        else {
            myCopy(&data[j], &temp[k]);
            j++;
        }

        k++;
		
		

	}
	
		// copy remaining left half
		while (i <= mid) {
			myCopy(&data[i], &temp[k]);
			i++;
			k++;
		}

		// copy remaining right half
		while (j <= last) {
			myCopy(&data[j], &temp[k]);
			j++;
			k++;
		}
		
		// copy temp back into data
		for (i = first; i <= last; i++) {
			myCopy(&temp[i], &data[i]);
		}	
}

void mySort(int array[], unsigned int first, unsigned int last)
    {
		// what to do in case of sorting an odd numbered array? e.g. 9 elements?s
		
		if (first >= last) { return; }
		
		unsigned int mid = (first + last) / 2 ;
		
		mySort(array, first, mid); // left branch
		mySort(array, mid + 1, last); // right branch
		
		merge(array, first, mid, last); // merge
    }

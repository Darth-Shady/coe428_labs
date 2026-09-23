#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int is_Sorted_least_to_greatest(int d[], unsigned int n, int *faulty_index) {
	
	for(unsigned int i = 0; i < n-1; i++) {
	
	
		if (d[i] <= d[i+1]) {continue;}
		else {*faulty_index = i; return 0;}
	
		
	
	}
	return 1;
}

int main(int argc, char * argv[])
{
	// hardcoded array of integers 
	int arr[100000];
	arr[0] = 30;
	arr[1] = 20;
	arr[2] = 40;
	arr[3] = 10;
	int num_elem = 4;
	
	// running the sort algorithm (in our case bubble sort)
	mySort(arr, num_elem);
	
	// is sorted?
	int faulty_index;
	if (!is_Sorted_least_to_greatest(arr, num_elem, &faulty_index)) {
	fprintf(stderr, "Error: Array was not sorted least to greatest \n Sort error: arr[%d] (= %d) should be <= arr[%d] (= %d) \n", faulty_index, arr[faulty_index], faulty_index + 1, arr[faulty_index + 1]) ; 
	exit(1);
	} 
	
	// print to stdout
	else {
	
	for (unsigned int i = 0; i < num_elem; i++) {
		printf("%d \n", arr[i]);
	
	}
	}
	
	return 0;
	
}

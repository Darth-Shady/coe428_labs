void mySort(int d[], unsigned int n)
{
	
	int pass_count = 0;
	
	
	for (int pass_count = 0; pass_count < (n-1);)  {// up to n-1 passes allowed, in worst case
		int swap_count = 0;
		
		for (int j = 1; j < (n-pass_count); j++) { // up to n - pass_count swaps allowed, in worst case
			// j starts at one to bypass index out of bounds errors (can't compare d[-1] to d[0]
			if ( (d[j-1]) > d[j] ) {
						// I want to swap the order of elements i and i -1 in the array
						int a = d[j] ;
						d[j] = d[j-1] ;
						d[j-1] = a ; 
						// we can swap the values like so ^^.
						// counting the swaps:
						swap_count++;
					}
			
		} 
		if (swap_count == 0) { return; }  // if no swaps happened during the pass
		pass_count++;
								
	}
		
		
		
}
	
	
	


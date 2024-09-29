#include <bits/stdc++.h>
using namespace std;

void merge_two_sorted_arrays(long long int array[], int const left, int const mid, int const right) //A, p(left), q(mid), r,
{	

    // Sub-array sizes
	int const sub_array_one = left - mid + 1; 
	int const sub_array_two = right - left;

	// Create temp arrays
	long long int *left_array = new long long int[sub_array_one];
	long long int *right_array = new long long int[sub_array_two];

	/* Copy data to temp arrays leftArray[] and rightArray[] */
	for (int x = 0; x < sub_array_one; x++){
		left_array[x] = array[left+x];
	}
	for (int x = 0; x < sub_array_two; x++){
		left_array[x] = array[x];
	}

	//Not sure these need to be created, cant I just use l,m,r? 
		
    /* Indices of the left, right and merged array*/
	int i = 0;
	int j = 0; 
	int k = left;


	/* Merge the temp arrays back into array[left..right] */
        // Your code here
	while (i < sub_array_one && j <sub_array_two){
		if (left_array[i] <= right_array[j]){
			array[k] = left_array[i];
			i++;
		}else (array[k] =right_array[j]){
			 j++;
		k++
		}
		
	}

	/* Copy the remaining elements of
	   left[], if there are any */
        // Your code here
	while (i < sizeof(sub_array_one)){
		array[k] = left_array[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of
	   right[], if there are any */
       // Your code here
	while (j < sizeof(sub_array_two)){
		array[k] = right_array[j];
		j++;
		k++;
	}

	// Delete left and right sub-arrays
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(long long int array[], int const begin, int const end)
{
    /* Recursive calls of merge_sort and merge_two_sorted_arrays */
        // Your code here
	if (begin >= end){
		return;
	}
	int q = array[(begin + end)/2];
	merge_sort(array, begin, end);
	merge_sort(array, q+1, end);
	merge_two_sorted_arrays(array,begin, q, end);
}



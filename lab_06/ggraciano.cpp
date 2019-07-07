
/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Cormen, et al.
 * 		Page 171: QUICKSORT(A, p, r)
 * 		Page 171: PARTITION(A, p, r)
 * 		Page 179: RANDOMIZED-PARTITION(A, p, r)
 * 	www.cplusplus.com/reference/cstdlib/rand/
 */

#include<iostream>
#include<stdlib.h>

int randomizedPartition(int arr[], int start, int end)
{
	int p, pivot, temp;
	int loc = rand() % (end - start + 1) + start;

	temp = arr[loc];
	arr[loc] = arr[end];
	arr[end] = temp;

	pivot = arr[end];
	p = start;

	for (int i = start; i < end; i++) {
		if (arr[i] <= pivot) {
			temp = arr[i];
			arr[i] = arr[p];
			arr[p] = temp;
			p++;
		}
	}

	temp = arr[p];
	arr[p] = arr[end];
	arr[end] = temp;

	return p;
}

void quicksort(int arr[], int start, int end)
{
	if (start < end) {
		int q = randomizedPartition(arr, start, end);
		quicksort(arr, start, q - 1);
		quicksort(arr, q + 1, end);
	}

	return;
}

int main()
{
	int size;
	std::cin >> size;

	const int len = size;

	int arr[len];

	for (int i = 0; i < len; i++) {
		std::cin >> arr[i];
	}

	quicksort(arr, 0, len - 1);

	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << ";";
	}

	return 0;
}

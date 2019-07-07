
/*
 * References:
 * 	Introduciton to Algorithms by Thomas H. Cormen, et al.
 * 		Page 154: MAX-HEAPIFY(A,i)
 * 		Page 157: BUILD-MAX-HEAP(A)
 * 		Page 160: HEAPSORT(A)
 */

#include<iostream>

void maxHeapify(int arr[], int i, int len)
{
	int max, temp;
	int l = i*2 + 1, r = i*2 + 2;

	if (l <= len && arr[l] > arr[i]) {
		max = l;
	} else {
		max = i;
	}

	if (r <= len && arr[r] > arr[max]) {
		max = r;
	}

	if (max != i) {
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		maxHeapify(arr, max, len);
	}

	return;
}

void buildMaxHeap(int arr[], int len)
{
	for (int i = len/2; i >= 0; i--) {
		maxHeapify(arr, i, len);
	}

	return;
}

void heapSort(int arr[], int len)
{
	int temp;

	buildMaxHeap(arr, len);

	for (int i = len; i > 0; i--) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		maxHeapify(arr, 0, i - 1);
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

	heapSort(arr, len - 1);

	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << ";";
	}

	return 0;
}

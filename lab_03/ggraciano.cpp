
#include <iostream>

void merge(int arr[], int start, int mid, int end)
{
	int arr1[mid - start + 1], arr2[end - mid];

	for (int i = 0; i < (mid - start + 1); i++) {
		arr1[i] = arr[start + i];
	}
	for (int i = 0; i < (end - mid); i++) {
		arr2[i] = arr[mid + i + 1];
	}

	int i = 0, j = 0, k = 0;

	while (i < (mid - start + 1) && j < (end - mid)) {
		if (arr1[i] <= arr2[j]) {
			arr[start + k] = arr1[i];
			i++; k++;
		} else {
			arr[start + k] = arr2[j];
			j++; k++;
		}
	}

	while (i < (mid - start + 1)) {
		arr[start + k] = arr1[i];
		i++; k++;
	}

	while (j < (end - mid)) {
		arr[start + k] = arr2[j];
		j++; k++;
	}

	return;
}

void mergeSort(int arr[], int start, int end)
{
	int mid;

	if (start < end) {
		mid = start + (end - start)/2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);

		merge(arr, start, mid, end);
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

	mergeSort(arr, 0, len - 1);

	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << ";";
	}

	return 0;
}

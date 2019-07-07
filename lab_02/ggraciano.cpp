
#include <iostream>

int binarySearch(int arr[], int start, int end, int value)
{
	int pos, mid;
	mid = start + (end - start)/2;

	if (end >= start) {
		if (arr[mid] == value) {
			return mid;
		}
		if (value < arr[mid]) {
			return pos = binarySearch(arr, start, mid - 1, value);
		}
		if (value > arr[mid]) {
			return pos = binarySearch(arr, mid + 1, end, value);
		}
	}

	return -1;
}

int main()
{
	int size, value;
	std::cin >> size;
	std::cin >> value;

	const int len = size;

	int arr[len];

	for (int i = 0; i < len; i++) {
		std::cin >> arr[i];
	}

	int pos;
	pos = binarySearch(arr, 0, len, value);

	if (pos != -1) {
		std::cout << pos;
	}
	else {
		std::cout << "-1";
	}

	return 0;
}

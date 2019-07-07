
#include <iostream>

int main()
{
	long j, size, temp;
	std::cin >> size;

	const long len = size;

	long arr[len];

	for (long i = 0; i < len; i++) {
		std::cin >> arr[i];
	}

	for (long i = 0; i < len - 1; i++) {
		j = i + 1;
		while (j > 0 && arr[j - 1] < arr[j]) {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}

	for (long i = 0; i < len; i++) {
		std::cout << arr[i] << ";";
	}

	return 0;
}

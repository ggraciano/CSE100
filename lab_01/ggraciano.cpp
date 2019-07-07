
#include <iostream>

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

	for (int i = 0; i < len; i++) {
		if (value == arr[i]) {
			std::cout << i << std::endl;
			return 0;
		}
	}
	std::cout << "-1" << std::endl;

	return 0;
}


/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Cormen, et al.
 * 		Page 195: COUNTING-SORT(A,B,k)
 * 		Page 198: RADIX-SORT(A,d)
 * 	www.cplusplus.com/reference/string/string/
 * 	www.cplusplus.com/reference/vector/vector/
 */

#include <iostream>
#include <string>
#include <vector>

void countingSort(std::vector<std::string> &vec, int index, int size)
{
	std::vector<std::string> temp(size);

	int count[10] = { 0 };

	for (int i = 0; i < size; i++) {
		count[(int)vec[i][index] - (int)'0']++;
	}

	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		temp[count[(int)vec[i][index] - (int)'0'] - 1] = vec[i];
		count[(int)vec[i][index] - (int)'0']--;
	}

	vec = temp;
	temp.clear();

	return;
}

void radixSort(std::vector<std::string> &vec, int len, int size)
{
	for (int i = len - 2; i >= 0; i -= 2) {
		countingSort(vec, i, size);
	}

	return;
}

int main()
{
	int len, size;
	std::cin >> size;
	std::cin.ignore();

	std::vector<std::string> vec(size);

	for (int i = 0; i < size; i++) {
		std::getline(std::cin, vec[i]);
	}

	len = vec[0].length();
	radixSort(vec, len, size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < len; j++) {
			if (vec[i][j] != ' ') {
				std::cout << vec[i][j];
			} else {
				std::cout << ";";
			}
		}

		std::cout << std::endl;
	}

	return 0;
}


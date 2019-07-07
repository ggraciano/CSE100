
/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Cormen, et al.
 * 		Page  18: INSERTION-SORT(A)
 * 		Page 201: BUCKET-SORT(A)
 * 	www.cplusplus.com/reference/vector/vector
 */

#include <iostream>
#include <vector>

void insertionSort(std::vector<double> &vec)
{
	if (vec.size() == 0) {
		return;
	}

	int j;
	double temp;

	for (int i = 0; i < vec.size() - 1; i++) {
		j = i + 1;
		while (j > 0 && vec[j - 1] > vec[j]) {
			temp = vec[j - 1];
			vec[j - 1] = vec[j];
			vec[j] = temp;
			j--;
		}
	}

	return;
}

void bucketSort(double arr[], int len)
{
	std::vector<double> temp[len];

	for (int i = 0; i < len; i++) {
		temp[(int)(len * arr[i])].push_back(arr[i]);
	}

	for (int i = 0; i < len; i++) {
		insertionSort(temp[i]);
	}

	int size, k;
	int j = 0;

	for (int i = 0; i < len; i++) {
		k = 0;
		size = temp[i].size();
		while (k < size) {
			arr[j] = temp[i][k];
			j++; k++;
		}
	}

	return;
}

int main()
{
	int size;
	std::cin >> size;

	const int len = size;

	double arr[len];

	for (int i = 0; i < len; i++) {
		std::cin >> arr[i];
	}

	bucketSort(arr, len);

	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}


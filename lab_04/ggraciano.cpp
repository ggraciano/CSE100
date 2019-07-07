#include<iostream>


int crossingMaxSubarray(int arr[], int start, int mid, int end)
{
	int leftSum = 0, rightSum = 0, sum = 0;

	for (int i = 0; i <= end; i++) {
		if (leftSum > arr[i]) {
			leftSum = arr[i];
			rightSum = arr[i];
		}
	}

	for (int i = mid; i >= start; i--) {
		sum += arr[i];
		if (sum > leftSum) {
			leftSum = sum;
		}
	}

	sum = 0;

	for (int i = mid + 1; i <= end; i++) {
		sum += arr[i];
		if (sum > rightSum) {
			rightSum = sum;
		}
	}

	return leftSum + rightSum;
}

int maxSubarray(int arr[], int start, int end)
{
	if (start == end) {
		return arr[start];
	} else {
		int mid, leftSum, rightSum, crossSum;
		mid = start + (end - start)/2;

		leftSum = maxSubarray(arr, start, mid);
		rightSum = maxSubarray(arr, mid + 1, end);
		crossSum = crossingMaxSubarray(arr, 0, mid, end);

		if (leftSum >= rightSum && leftSum >= crossSum) {
			return leftSum;
		} else if (rightSum >= leftSum && rightSum >= crossSum) {
			return rightSum;
		} else {
			return crossSum;
		}
	}
}

int main ()
{
	int size;
	std::cin >> size;

	const int len = size;

	int arr[len];

	for (int i = 0; i < len; i++) {
		std::cin >> arr[i];
	}

	std::cout << maxSubarray(arr, 0, len - 1);

	return 0;
}


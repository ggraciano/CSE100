
/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Cormen, et al.
 * 		Page  18: INSERTION-SORT(A)
 * 		Page 201: BUCKET-SORT(A)
 */

#include <iostream>

struct Node
{
	double num;
	Node *next;

	Node() {
		num = -1;
		next = NULL;
	}
};

void insertionSort(Node *barr)
{
	if (barr->num < 0) {
		return;
	}

	int j, size = 1;
	double temp;

	Node *curr = barr;
	Node *cnext;

	while (curr->next != NULL) {
		size++;
		curr = curr->next;
	}

	curr = barr;

	for (int i = 0; i < size - 1; i++) {
		j = i - 1;
		cnext = curr->next;
		while (j < 0 && curr->num > cnext->num) {
			temp = curr->num;
			curr->num = cnext->num;
			cnext->num = temp;
			j--;
		}

		curr = curr->next;
	}

	return;
}

void bucketSort(double arr[], const int len)
{
	Node *barr[len], *curr;

	for (int i = 0; i < len; i++) {
		barr[i] = new Node();
	}

	for (int i = 0; i < len; i++) {
		curr = barr[(int)(len * arr[i])];

		if (curr->num < 0) {
			curr->num = arr[i];
		} else {
			Node *temp = new Node();
			temp->num = arr[i];

			while (curr->next != NULL) {
				curr = curr->next;
			}

			curr->next = temp;
		}
	}

	for (int i = 0; i < len; i++) {
		insertionSort(barr[i]);
	}

	int j = 0;

	for (int i = 0; i < len; i++) {
		if (barr[i]->num > -1) {
			do {
			curr = barr[i];
			arr[j] = barr[i]->num;
			barr[i] = barr[i]->next;
			delete curr;
			j++;
			} while (barr[i] != NULL);
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


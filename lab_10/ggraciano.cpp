
/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Cormen, et al.
 * 		Page 270: HASH-INSERT(T,k)
 * 		Page 271: HASH-SEARCH(T,k)
 */

#include <iostream>

#define MAX 13

void hashPrint(int tab[])
{
	for (int i = 0; i < MAX; i++) {
		if (tab[i] < 0) {
			std::cout << std::endl;
		} else {
			std::cout << tab[i] << std::endl;
		}
	}

	return;
}

int doubleHashFunction(int key, int i)
{
	int h1, h2;

	h1 = key % 13;
	h2 = 1 + (key % 11);

	return (h1 + i*h2) % 13;
}

void hashInsert(int tab[], int key)
{
	int i, j;
	i = 0;

	while (i < MAX) {
		j = doubleHashFunction(key, i);

		if (tab[j] < 0) {
			tab[j] = key;
			break;
		}

		i++;
	}

	return;
}

void hashSearch(int tab[], int key)
{
	int i, j;
	i = 0;

	while (i < MAX) {
		j = doubleHashFunction(key, i);

		if (tab[j] < 0) {
			break;
		}

		if (tab[j] == key) {
			std::cout << j << std::endl;
			return;
		}

		i++;
	}

	std::cout << "NOT_FOUND" << std::endl;

	return;
}

void hashDelete(int tab[], int key)
{
	int i, j;
	i = 0;

	while (i < MAX) {
		j = doubleHashFunction(key, i);

		if (tab[j] == key) {
			tab[j] = -1;
			break;
		}

		i++;
	}

	return;
}

int main()
{
	int tab[MAX];

	for (int i = 0; i < MAX; i++) {
		tab[i] = -1;
	}

	int key;

	while (std::cin >> key) {
		if (key == -1) {
			break;
		}

		hashInsert(tab, key);
	}

	hashPrint(tab);

	while (std::cin >> key) {
		if (key == -2) {
			break;
		}

		hashSearch(tab, key);
	}

	while (std::cin >> key) {
		if (key == -3) {
			break;
		}

		hashDelete(tab, key);
	}

	hashPrint(tab);

	return 0;
}


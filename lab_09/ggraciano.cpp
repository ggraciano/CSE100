
/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Cormen, et al.
 * 		Page 258: CHAINED-HASH-INSERT(T,x)
 * 		Page 258: CHAINED-HASH-SEARCH(T,k)
 * 		Page 258: CHAINED-HASH-DELETE(T,x)
 * 	www.cplusplus.com/reference/string/string/
 * 	www.cplusplus.com/reference/sstream/stringstream/
 */

#include <iostream>
#include <string>
#include <sstream>

#define BREAK std::string(20, '+')

struct Node
{
	int key;
	Node *next;

	Node() {
		key = -1;
		next = NULL;
	}
};

void hashInsert(Node *row, int key)
{
	if (row->key < 0) {
		row->key = key;
	} else {
		Node *curr, *temp;

		curr = new Node();
		curr->key = key;

		temp = new Node();
		temp->key = row->key;
		temp->next = row->next;

		row->key = key;
		row->next = temp;
	}

	return;
}

void hashDelete(Node *row, int key)
{
	if (row->next == NULL) {
		if (row->key == key) {
			row->key = -1;
			std::cout << key << " : DELETED" << std::endl;
		} else {
			std::cout << key << " : DELETE FAILED" << std::endl;
		}

		std::cout << BREAK << std::endl;

		return;
	}

	Node *curr, *prev;
	curr = row;

	while (curr != NULL) {
		if (curr->key == key) {
			if (curr->next == NULL) {
				delete curr;
				prev->next = NULL;
			} else {
				curr->key = curr->next->key;
				curr->next = curr->next->next;
			}

			std::cout << key << " : DELETED" << std::endl;
			std::cout << BREAK << std::endl;

			return;
		} else {
			prev = curr;
			curr = curr->next;
		}
	}

	std::cout << key << " : DELETE FAILED" << std::endl;
	std::cout << BREAK << std::endl;

	return;
}

void hashSearch(Node *row, int key, int loc)
{
	int index = 0;

	if (row->key == key) {
		std::cout << key << " : FOUND AT " << loc << "," << index << std::endl;
		std::cout << BREAK << std::endl;

		return;
	}

	Node *curr = row->next;

	while (curr != NULL) {
		index++;

		if (curr->key == key) {
			std::cout << key << " : FOUND AT " << loc << "," << index << std::endl;
			std::cout << BREAK << std::endl;

			return;
		}

		curr = curr->next;
	}

	std::cout << key << " : NOT FOUND" << std::endl;
	std::cout << BREAK << std::endl;

	return;
}

int main()
{
	int size, key, loc;
	std::cin >> size;
	std::cin.ignore();

	const int len = size;

	Node *tab[len];

	for (int i = 0; i < len; i++) {
		tab[i] = new Node();
	}

	std::string str;
	std::stringstream ss;

	Node *temp;

	while (std::getline(std::cin, str)) {
		if (str.length() > 1) {
			ss << str.substr(2, str.length() - 1);
			ss >> key;
			ss.clear();

			loc = key % len;
		}

		if (str[0] == 'i') {
			hashInsert(tab[loc], key);
		} else if (str[0] == 'd') {
			hashDelete(tab[loc], key);
		} else if (str[0] == 's') {
			hashSearch(tab[loc], key, loc);
		} else if (str[0] == 'o') {
			for (int i = 0; i < len; i++) {
				temp = tab[i];
				std::cout << i << " : ";

				while (temp != NULL) {
					if (temp->key < 0) {
						std::cout << std::endl;
					} else {
						std::cout << temp->key;
						if (temp->next != NULL) {
							std::cout << "->";
						} else {
							std::cout << std::endl;
						}
					}

					temp = temp->next;
				}
			}

			std::cout << BREAK << std::endl;
		} else {
			break;
		}
	}

	return 0;
}



/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Cormen et al.
 * 		Page 431: HUFFMAN(C)
 * 	www.cplusplus.com/references/map/map/
 */

#include <iostream>
#include <climits>
#include <map>
#include <string>
#include <vector>

struct Node
{
	int id;
	int freq;
	char chars;
	Node* left;
	Node* right;
	std::string hc;

	Node() {
		id = -1;
		freq = 0;
		chars = '\0';
		left = NULL;
		right = NULL;
		hc = "";
	}
};

Node* minHeap(std::vector<Node*> &nQ)
{
	int j;

	Node *temp = new Node();
	temp->freq = INT_MAX;

	for (int i = 0; i < nQ.size(); i++) {
		if (temp->freq > nQ[i]->freq) {
			j = i;
			temp = nQ[i];
		}

		if (temp->freq == nQ[i]->freq) {
			if (temp->id > nQ[i]->id) {
				j = i;
				temp = nQ[i];
			}
		}
	}

	nQ.erase(nQ.begin() + j);

	return temp;
}

Node* huffman(std::vector<Node*> &nQ, int size)
{
	Node *left, *right;

	for (int i = 1; i < size; i++) {
		Node *z = new Node();

		z->left = minHeap(nQ);
		z->right = minHeap(nQ);

		z->id = z->left->id;
		z->freq = z->left->freq + z->right->freq;

		nQ.push_back(z);
	}

	return nQ[0];
}

void inorderTreeWalk(std::map<char, std::string> &hc_map, Node *hc_tree, std::string hc)
{
	if (hc_tree != NULL) {
		inorderTreeWalk(hc_map, hc_tree->left, hc + "0");

		if (hc_tree->chars != '\0') {
			std::map<char, std::string>::iterator it;
			it = hc_map.find(hc_tree->chars);
			it->second = hc;
		}

		inorderTreeWalk(hc_map, hc_tree->right, hc + "1");
	}

	return;
}

int main()
{
	int size;
	std::cin >> size;

	std::map<char, std::string> hc_map;
	std::vector<Node*> nQ;

	for (int i = 0; i < size; i++) {
		Node *c = new Node();

		c->id = i;
		c->chars = 'A' + i;
		std::cin >> c->freq;
		hc_map.insert(std::pair<char, std::string>('A' + i, ""));
		nQ.push_back(c);
	}

	Node *hc_tree = huffman(nQ, size);

	inorderTreeWalk(hc_map, hc_tree, "");

	for (int i = 0; i < size; i++) {
		std::cout << hc_map.find('A' + i)->second << std::endl;
	}

	hc_map.clear();

	return 0;
}



/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Corman et al.
 * 		Page 431: HUFFMAN(C)
 * 	www.cplusplus.com/reference/map/map/
 * 	www.cplusplus.com/reference/queue/priority_queue/
 */

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

struct Node
{
	int id;
	int freq;
	char chars;
	Node *left;
	Node *right;
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

struct nodeCompare
{
	bool operator()(Node *left, Node *right)
	{
		if (left->freq == right->freq) {
			return left->id > right->id;
		}

		return left->freq > right->freq;
	}
};

Node* huffman(std::priority_queue<Node*, std::vector<Node*>, nodeCompare> &minNQ, int size)
{
	Node *left, *right;

	for (int i = 1; i < size; i++) {
		Node *z = new Node();

		z->left = minNQ.top();
		minNQ.pop();
		z->right = minNQ.top();
		minNQ.pop();

		z->id = z->left->id;
		z->freq = z->left->freq + z->right->freq;

		minNQ.push(z);
	}

	return minNQ.top();
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
	std::priority_queue<Node*, std::vector<Node*>, nodeCompare> minNQ;

	for (int i = 0; i < size; i++) {
		Node *c = new Node();

		c->id = i;
		c->chars = 'A' + i;
		std::cin >> c->freq;
		hc_map.insert(std::pair<char, std::string>('A' + i, ""));
		minNQ.push(c);
	}

	Node *hc_tree = huffman(minNQ, size);

	inorderTreeWalk(hc_map, hc_tree, "");

	for (int i = 0; i < size; i++) {
		std::cout << hc_map.find('A' + i)->second << std::endl;
	}

	hc_map.clear();

	return 0;
}


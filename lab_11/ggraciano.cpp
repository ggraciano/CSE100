
/*
 * References:
 * 	Introduction to Algorithm by Thomas H. Cormen, et al.
 * 		Page 288: INORDER-TREE-WALK(x)
 * 		Page 294: TREE-INSERT(T,z)
 * 	https://en.wikipedia.org/wiki/Tree_traversal#Pre-order_(NLR)/
 */

#include <iostream>
#include <string>
#include <sstream>

#define BREAK std::string(20, '+')

struct BST
{
	int key;
	BST *top;
	BST *left;
	BST *right;

	BST() {
		key = -1;
		top = NULL;
		left = NULL;
		right = NULL;
	}
};

void treeInsert(BST *tree, int key)
{
	if (tree->key < 0) {
		tree->key = key;
		return;
	}

	BST *curr, *prev;
	curr = tree;

	BST *leaf = new BST();
	leaf->key = key;

	while (curr != NULL) {
		prev = curr;

		if (leaf->key < curr->key) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}

	leaf->top = prev;

	if (leaf->key < prev->key) {
		prev->left = leaf;
	} else {
		prev->right = leaf;
	}

	return;
}

void treeDelete(BST *&tree, int key)
{
	BST *curr, *prev, *next;
	curr = tree;
	prev = curr;

	int temp;

	if (curr == NULL) {
		return;
	}

	while (curr->key != key) {
		prev = curr;

		if (key < curr->key) {
			if (curr->left == NULL) {
				return;
			}

			curr = curr->left;
		} else {
			if (curr->right == NULL) {
				return;
			}

			curr = curr->right;
		}
	}

	if (curr->left == NULL && curr->right == NULL) {
		if (curr->top == NULL) {
			tree->key = -1;
		} else {
			if (prev->left->key == key) {
				prev->left = NULL;
			} else {
				prev->right = NULL;
			}
		}

		delete curr;
	} else if (curr->left != NULL && curr->right == NULL) {
		if (curr->top == NULL) {
			tree = tree->left;
			tree->top = NULL;
		} else {
			next = curr->left;
			next->top = prev;

			if (prev->left->key == key) {
				prev->left = next;
			} else {
				prev->right = next;
			}
		}

		delete curr;
	} else if (curr->left == NULL && curr->right != NULL) {
		if (curr->top == NULL) {
			tree = tree->right;
			tree->top = NULL;
		} else {
			next = curr->right;
			next->top = prev;

			if (prev->left->key == key) {
				prev->left = next;
			} else {
				prev->right = next;
			}
		}

		delete curr;
	} else {
		next = curr->right;

		while (next->left != NULL) {
			next = next->left;
		}

		temp = next->key;
		treeDelete(tree, temp);

		if (curr->top == NULL) {
			tree->key = temp;
		} else {
			curr->key = temp;
		}
	}

	return;
}

// NLR
void preorderTreeWalk(BST *tree)
{
	if (tree != NULL) {
		std::cout << tree->key << std::endl;
		preorderTreeWalk(tree->left);
		preorderTreeWalk(tree->right);
	}

	return;
}

// LRN
void postorderTreeWalk(BST *tree)
{
	if (tree != NULL) {
		postorderTreeWalk(tree->left);
		postorderTreeWalk(tree->right);
		std::cout << tree->key << std::endl;
	}

	return;
}

// LNR
void inorderTreeWalk(BST *tree)
{
	if (tree != NULL) {
		inorderTreeWalk(tree->left);
		std::cout << tree->key << std::endl;
		inorderTreeWalk(tree->right);
	}

	return;
}

int main()
{
	BST *tree = new BST();

	std::string str;
	std::stringstream ss;

	int key;

	while (std::getline(std::cin, str)) {
		if (str[0] == 'i' && str[1] == ' ') {
			ss << str.substr(2, str.length() - 1);
			ss >> key;
			ss.clear();

			treeInsert(tree, key);
		} else if (str[0] == 'd') {
			ss << str.substr(2, str.length() - 1);
			ss >> key;
			ss.clear();

			treeDelete(tree, key);
		} else if (str == "pre") {
			preorderTreeWalk(tree);
			std::cout << BREAK << std::endl;
		} else if (str == "post") {
			postorderTreeWalk(tree);
			std::cout << BREAK << std::endl;
		} else if (str == "in") {
			inorderTreeWalk(tree);
			std::cout << BREAK << std::endl;
		} else {
			break;
		}
	}

	return 0;
}


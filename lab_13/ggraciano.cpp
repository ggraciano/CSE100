
/*
 * References:
 * 	Introduction to Algorithms by Thomas H. Cormen et al.
 * 		Page 375: MATRIX-CHAIN-ORDER(p)
 * 		Page 377: PRINT-OPTIMAL-PARENS(s,i,j)
 * 	www.cplusplus.com/reference/climits/
 */

#include <iostream>
#include <climits>
#include <sstream>
#include <string>

void printOptimalParens(int **temp2, int start, int end)
{
	if (start == end) {
		std::cout << "A" << start - 1;
	} else {
		std::cout << "(";
		printOptimalParens(temp2, start, temp2[start][end]);
		std::cout << ".";
		printOptimalParens(temp2, temp2[start][end] + 1, end);
		std::cout << ")";
	}

	return;
}

void matrixChainOrder(int dim[], const int n)
{
	int tab1[n][n] = { 0 };
	int tab2[n][n] = { 0 };

	int end, temp;

	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			end = i + j - 1;
			tab1[j][end] = INT_MAX;
			for (int k = j; k <= end - 1; k++) {
				temp = tab1[j][k] + tab1[k + 1][end] +
					dim[j - 1]*dim[k]*dim[end];
				if (temp < tab1[j][end]) {
					tab1[j][end] = temp;
					tab2[j][end] = k;
				}
			}
		}
	}

	std::cout << tab1[1][n - 1] << std::endl;

	int *temp2[n];

	for (int i = 0; i < n; i++) {
		temp2[i] = tab2[i];
	}

	printOptimalParens(temp2, 1, n - 1);
	std::cout << std::endl;

	return;
}

int main()
{
	int temp;
	std::cin >> temp;
	std::cin.ignore();

	const int n = temp + 1;

	int dim[n] = { 0 };

	std::string str;
	std::getline(std::cin, str);

	std::stringstream ss;
	ss << str;

	for (int i = 0; i < n; i++) {
		ss >> dim[i];
	}

	matrixChainOrder(dim, n);

	return 0;
}


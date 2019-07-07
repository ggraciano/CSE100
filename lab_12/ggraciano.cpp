
/*
 * References:
 * 	Introduction to Algorithm by Thomas H. Cormen, et al.
 * 		Page 369: EXTENDED-BOTTOM-UP-CUT-ROD(p,n)
 * 		Page 369: PRINT-CUT-ROD-SOLUTION(p,n)
 */

#include <iostream>

void extendedBottomUpCutRod(int price[], const int len)
{
	int max[len] = { 0 };
	int sub[len];
	int temp;

	for (int i = 1; i <= len; i++) {
		temp = -1;
		for (int j = 1; j <= i; j++) {
			if (temp < price[j] + max[i - j]) {
				temp = price[j] + max[i - j];
				sub[i] = j;
			}
		}
		max[i] = temp;
	}

	std::cout << max[len - 1] << std::endl;

	int i = len - 1;

	while (i > 0) {
		std::cout << sub[i] << " ";
		i -= sub[i];
	}

	std::cout << "-1" << std::endl;

	return;
}

int main()
{
	int size;
	std::cin >> size;

	const int len = size + 1;

	int price[len] = { 0 };

	for (int i = 1; i < len; i++) {
		std::cin >> price[i];
	}

	extendedBottomUpCutRod(price, len);

	return 0;
}


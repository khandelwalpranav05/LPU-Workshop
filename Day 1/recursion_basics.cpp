#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int sumTillN(int n) {
	// BASE CASE
	if (n == 1) {
		return 1;
	}

	// Recursive Case
	int recResult = sumTillN(n - 1);
	int total = recResult + n;

	return total;
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}

	int facn1 = factorial(n - 1);
	int total = facn1 * n;

	return total;
}

int power(int n, int p) {
	if (p == 0) {
		return 1;
	}

	int powen1 = power(n, p - 1);

	int total = powen1 * n;

	return total;
}

void printDecreasing(int n) {
	if (n == 1) {
		cout << n << endl;
		return;
	}

	cout << n << endl;

	printDecreasing(n - 1);
}

void printIncreasing(int n) {
	if (n == 1) {
		cout << n << endl;
		return;
	}

	printIncreasing(n - 1);

	cout << n << endl;
}

void printDecInc(int n) {
	if (n == 0) {
		return;
	}

	cout << n << endl;

	printDecInc(n - 1);

	cout << n << endl;
}

int linearSearch(int arr[], int si, int n, int data) {
	if (si == n) {
		return -1;
	}

	if (arr[si] == data) {
		return si;
	} else {
		int rescursionResult = linearSearch(arr, si + 1, n, data);
		return rescursionResult;
	}
}

bool isSorted(int arr[], int si, int n) {
	if (si == n - 1) {
		return true;
	}

	if (arr[si] > arr[si + 1]) {
		return false;
	} else {
		return isSorted(arr, si + 1, n);
	}
}

int lastIndex(int arr[], int si, int n, int data) {
	if (si == n) {
		return -1;
	}

	int idx = lastIndex(arr, si + 1, n, data);

	if (idx == -1) {
		if (arr[si] == data) {
			return si;
		} else {
			return -1;
		}
	} else {
		return idx;
	}
}

int fib(int n) {
	if (n == 0 or n == 1) return n;
	// if (n == 0) {
	// 	return 0;
	// }

	// if (n == 1) {
	// 	return 1;
	// }

	int fibn1 = fib(n - 1);
	int fibn2 = fib(n - 2);

	int fibn = fibn1 + fibn2;
	return fibn;

	// return fib(n - 1) + fib(n - 2);
}

int countBinaryString(int n) {
	if (n == 1 or n == 2) {
		return n + 1;
	}

	int zero = countBinaryString(n - 1);
	int one = countBinaryString(n - 2);

	int total = one + zero;
	return total;
}

int pairingProblem(int n) {
	if (n == 1 or n == 2) return n;

	int akela = pairingProblem(n - 1);
	int saath = pairingProblem(n - 2);

	int total = akela + (n - 1) * saath;
	return total;
}

int countBoardPath(int start, int end) {
	if (start == end) {
		return 1;
	}

	if (start > end) {
		return 0;
	}

	int count = 0;

	for (int dice = 1; dice <= 6; dice++) {
		count += countBoardPath(start + dice, end);
	}

	return count;
}

int countMazePath(int sr, int sc, int er, int ec) {
	if (sr == er and sc == ec) {
		return 1;
	}

	if (sc > ec or sr > er) {
		return 0;
	}

	int horizontal = countMazePath(sr, sc + 1, er, ec);
	int vertical = countMazePath(sr + 1, sc, er, ec);

	int total = horizontal + vertical;
	return total;
}

int main() {

	// cout << sumTillN(5) << endl;

	// cout << factorial(5) << endl;

	// cout << power(2, 5) << endl;

	// printDecreasing(5);

	// printIncreasing(5);

	// printDecInc(5);

	// int arr[] = {5, 3, 2, 6, 8, 9, 10};
	// int n = 7;
	// int data = 8;

	// cout << linearSearch(arr, 0, n, data) << endl;

	// int arr[] = {1, 2, 3, 14, 5, 6};
	// int n = 6;

	// cout << isSorted(arr, 0, n) << endl;

	// int arr[] = {1, 2, 3, 4, 5, 2, 3, 5};
	// int n = 8;
	// int data = 2;

	// cout << lastIndex(arr, 0, n, data) << endl;

	// cout << fib(7) << endl;

	// cout << countBinaryString(4) << endl;

	// cout << pairingProblem(3) << endl;

	// cout << countBoardPath(0, 10) << endl;

	// cout << countMazePath(0, 0, 2, 2) << endl;

	// int x = linearSearch();
	// cout << x << endl;

	// cout << linearSearch() << endl;

	return 0;
}
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

bool subarraySumZero(int arr[], int n) {

	unordered_map<int, bool> h;

	h[0] = true;

	int sum = 0;

	for (int i = 0; i < n; i++) {

		sum += arr[i];

		if (h.count(sum)) {
			return true;
		}

		h[sum] = true;
	}

	return false;
}

int LongestSubarrySumZero(int arr[], int n) {

	unordered_map<int, int> h;

	int sum = 0;

	h[0] = -1;

	int maxLen = 0;

	for (int i = 0; i < n; i++) {

		sum += arr[i];

		if (h.count(sum)) {
			int prev = h[sum];

			int len = i - prev;

			maxLen = max(len, maxLen);
		} else {
			h[sum] = i;
		}
	}

	return maxLen;
}

bool subarraySumWithK(int arr[], int n, int k) {



}

int main() {

	// int arr[] = {0, 3, 3, 3, 9, 8};
	// int n = 7;

	// cout << subarraySumZero(arr, n) << endl;

	// int arr[] = {3, 3, -5, 0, 2, 5};
	// int n = 6;

	// cout << LongestSubarrySumZero(arr, n) << endl;

	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;
	int k =
	    cout <<

	    return 0;
}
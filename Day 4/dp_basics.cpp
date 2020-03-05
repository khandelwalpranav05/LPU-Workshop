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

int fib(int n) {
	if (n == 1 or n == 0) {
		return 0;
	}

	int fibn1 = fib(n - 1);
	int fibn2 = fib(n - 2);

	int total = fibn1 + fibn2;
	return total;
}

int fibMemo(int n, int dp[]) {
	if (n == 1 or n == 0) {
		dp[n] = n;
		return n;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int fibn1 = fibMemo(n - 1, dp);
	int fibn2 = fibMemo(n - 2, dp);

	int total = fibn1 + fibn2;

	dp[n] = total;

	for (int i = 0; i <= 5; i++) {
		cout << dp[i] << " ";
	}
	cout << endl << "*****************" << endl;

	return total;
}

int fibDP(int n) {

	int dp[n + 1];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int reduceToOne(int n) {
	if (n == 1) {
		return 0;
	}

	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	if (n % 3 == 0) {
		count3 = reduceToOne(n / 3);
	}

	if (n % 2 == 0) {
		count2 = reduceToOne(n / 2);
	}

	count1 = reduceToOne(n - 1);

	int result = min(count1, min(count2, count3)) + 1;

	return result;
}


int reduceToOneMemo(int n, int dp[]) {
	if (n == 1) {
		dp[n] = 0;
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	if (n % 3 == 0) {
		count3 = reduceToOneMemo(n / 3, dp);
	}

	if (n % 2 == 0) {
		count2 = reduceToOneMemo(n / 2, dp);
	}

	count1 = reduceToOneMemo(n - 1, dp);

	int result = min(count1, min(count2, count3)) + 1;

	dp[n] = result;

	for (int i = 0; i <= 10; i++) {
		cout << dp[i] << " ";
	}
	cout << endl << "****************" << endl;

	return result;
}

int reduceToOneDP(int n) {

	int dp[n + 1];

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {

		int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

		count1 = dp[i - 1];

		if (i % 2 == 0) {
			count2 = dp[i / 2];
		}

		if (i % 3 == 0) {
			count3 = dp[i / 3];
		}

		dp[i] = min(count1, min(count2, count3)) + 1;
	}

	return dp[n];
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

int countBoardPathMemo(int start, int end, int dp[]) {
	if (start == end) {
		dp[start] = 1;
		return 1;
	}

	if (start > end) {
		return 0;
	}

	//MEMO
	if (dp[start] != -1) {
		return dp[start];
	}

	int count = 0;

	for (int dice = 1; dice <= 6; dice++) {
		count += countBoardPathMemo(start + dice, end, dp);
	}

	dp[start] = count;

	for (int i = 0; i <= end; i++) {
		cout << dp[i] << "\t";
	}

	cout << endl << "****************" << endl;

	return count;
}

int countBoardPathDP(int start, int end) {

	int dp[end + 1];

	dp[end] = 1;

	for (int i = end - 1; i >= 0; i--) {

		dp[i] = 0;

		for (int dice = 1; dice <= 6; dice++) {

			if (dice + i > end) {
				break;
			}

			dp[i] += dp[i + dice];
		}

	}

	return dp[0];
}

int helper(int n, int dp[]) {
	if (n == 0) {
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int minValue = INT_MAX;

	for (int i = 1; i * i <= n; i++) {
		int abhiTakKaAnswer = helper(n - i * i, dp);
		minValue = min(abhiTakKaAnswer, minValue);
	}

	dp[n] = minValue + 1;

	for (int i = 0; i <= 12; i++) {
		cout << dp[i] << "\t";
	}

	cout << endl << "****************" << endl;

	return dp[n];
}

int numSquaresMemo(int n) {

	int dp[n + 1];
	memset(dp, -1, sizeof(dp));

	return helper(n, dp);
}

int numSquaresDP(int n) {

	int dp[n + 1];

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {

		int minValue = INT_MAX;

		for (int j = 1; j * j <= i; j++) {
			minValue = min(minValue, dp[i - j * j]);
		}

		dp[i] = minValue + 1;
	}

	return dp[n];
}


int houseRobber(int si, vector<int> &nums, int dp[]) {
	if (si >= nums.size()) {
		dp[si] = 0;
		return 0;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	int include = nums[si] + houseRobber(si + 2, nums, dp);
	int skip = houseRobber(si + 1, nums, dp);

	int result = max(skip, include);

	dp[si] = result;

	for (int i = 0; i <= nums.size(); i++) {
		cout << dp[i] << " ";
	}
	cout << endl << "*********************" << endl;

	return result;
}

int rob(vector<int>& nums) {
	if (nums.size() == 0) return 0;

	int n = nums.size();
	int dp[n + 2];
	memset(dp, -1, sizeof(dp));

	return houseRobber(0, nums, dp);
}

int robDP(vector<int>& nums) {
	if (nums.size() == 0) return 0;

	int n = nums.size();
	int dp[n + 2];


	dp[n] = 0;
	dp[n + 1] = 0;

	for (int i = n - 1; i >= 0; i--) {
		int include = nums[i] + dp[i + 2];
		int skip = dp[i + 1];

		dp[i] = max(include, skip);
	}

	return dp[0];
}

int main() {

	// int n = 5;
	// // cout << fib(n) << endl;

	// int dp[n + 1];
	// memset(dp, -1, sizeof(dp));

	// cout << fibMemo(n, dp) << endl;

	// cout << fibDP(n) << endl;

	// int n = 10;
	// cout << reduceToOne(n) << endl;
	// int dp[n + 1];
	// memset(dp, -1, sizeof(dp));
	// cout << reduceToOneMemo(n, dp) << endl;
	// cout << reduceToOneDP(n) << endl;

	// int start = 0;
	// int end = 10;
	// // int dp[end + 1];
	// // memset(dp, -1, sizeof(dp));

	// // cout << countBoardPathMemo(start, end, dp) << endl;

	// cout << countBoardPathDP(start, end) << endl;

	// cout << numSquaresMemo(12) << endl;
	// cout << numSquaresDP(12) << endl;

	vector<int> v{2, 7, 9, 3, 1};
	cout << rob(v) << endl;

	for (int val : v) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
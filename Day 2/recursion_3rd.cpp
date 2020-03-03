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

int countMazePathDia(int sr, int sc, int er, int ec) {
	if (sr == er and sc == ec) {
		return 1;
	}

	if (sr > er or sc > ec) {
		return 0;
	}

	int horizontal = countMazePathDia(sr, sc + 1, er, ec);
	int vertical = countMazePathDia(sr + 1, sc, er, ec);
	int diagonal = countMazePathDia(sr + 1, sc + 1, er, ec);

	int total = horizontal + vertical + diagonal;
	return total;
}

string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string key = code[ch - '0'];

	for (int i = 0; i < key.length(); i++) {
		printKeypad(ros, ans + key[i]);
	}
}

bool isPossible(int si, vector<int> &nums, int sum, int total) {
	if (sum == total) return true;

	if (sum > total or si == nums.size()) {
		return false;
	}

	bool include = isPossible(si + 1, nums, sum + nums[si], total);
	bool exclude = isPossible(si + 1, nums, sum, total);

	if (include or exclude) {
		return true;
	}

	return false;
}

bool canPartition(vector<int>& nums) {
	int total = 0;

	for (int i = 0; i < nums.size(); i++) {
		total += nums[i];
	}

	if (total % 2 == 1) return false;

	total = total / 2;

	return isPossible(0, nums, 0, total);
}

int numSquares(int n) {
	if (n == 0) {
		return 0;
	}

	int minValue = INT_MAX;

	for (int i = 1; i * i <= n; i++) {
		int abhiTakKaAnswer = numSquares(n - i * i);
		minValue = min(abhiTakKaAnswer, minValue);
	}

	return minValue + 1;
}

void mappedString(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch1 = str[0];
	string ros1 = str.substr(1);

	int ch1_int = ch1 - '0';

	ch1 = ch1 + 16;

	mappedString(ros1, ans + ch1);

	if (str.length() > 1) {

		char ch2 = str[1];

		int ch2_int = ch2 - '0';

		int num = ch1_int * 10 + ch2_int;

		if (num <= 26) {
			string ros2 = str.substr(2);

			ch2 = num + 64;

			mappedString(ros2, ans + ch2);
		}
	}

}

int main() {

	// cout << countMazePathDia(0, 0, 2, 2) << endl;

	// printKeypad("234", "");

	mappedString("123", "");

	return 0;
}
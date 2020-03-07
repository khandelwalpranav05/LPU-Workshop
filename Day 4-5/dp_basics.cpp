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

// int helper(vector<vector<int>> &grid, int sr, int sc, int er, int ec, vector<vector<int> > &dp) {
// 	if (sr == er and sc == ec) {
// 		return grid[er][ec];
// 	}

// 	if (sr > er or sc > ec) {
// 		return INT_MAX;
// 	}

// 	//MEMO
// 	if (dp[sr][sc] != -1) {
// 		return dp[sr][sc];
// 	}

// 	int val = grid[sr][sc];

// 	int right = helper(grid, sr, sc + 1, er, ec, dp);
// 	int down = helper(grid, sr + 1, sc, er, ec, dp);

// 	int result = min(right, down) + val;

// 	dp[sr][sc] = result;

// 	return result;
// }

// int minPathSum(vector<vector<int>>& grid) {

// 	int n = grid.size();
// 	int m = grid[0].size();

// 	int er = n - 1;
// 	int ec = m - 1;

// 	int row = n;
// 	int col = m;

// 	vector<vector<int> > dp(row, vector<int> (col, -1));

// 	return helper(grid, 0, 0, er, ec, dp);
// }

int helper(string s1, int i, string s2, int j, vector<vector<int> > &dp) {
	if (i == s1.length() or j == s2.length()) {
		dp[i][j] = 0;
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int result;

	if (s1[i] == s2[j]) {

		result = 1 + helper(s1, i + 1, s2, j + 1, dp);

	} else {

		int first = helper(s1, i + 1, s2, j, dp);
		int second = helper(s1, i, s2, j + 1, dp);

		result = max(first, second);
	}

	dp[i][j] = result;

	for (int x = 0; x <= s1.length(); x++) {
		for (int y = 0; y <= s2.length(); y++) {
			cout << dp[x][y] << "\t";
		}
		cout << endl;
	}

	cout << "*****************************************" << endl;

	return result;
}

int longestCommonSubsequence(string text1, string text2) {

	int row = text1.length() + 1;
	int col = text2.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col, -1));

	return helper(text1, 0, text2, 0, dp);
}

int longestCommonSubsequenceDP(string text1, string text2) {

	int row = text1.length() + 1;
	int col = text2.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col, 0));

	for (int i = text1.length() - 1; i >= 0; i--) {
		for (int j = text2.length() - 1; j >= 0; j--) {

			if (text1[i] == text2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	return dp[0][0];
}

int knapSack(int si, int weight[], int value[], int capacity, int n) {
	if (si == n) {
		return 0;
	}

	int include = INT_MIN;

	if (weight[si] <= capacity) {
		include = value[si] + knapSack(si + 1, weight, value, capacity - weight[si], n);
	}

	int skip = knapSack(si + 1, weight, value, capacity, n);

	int result = max(include, skip);

	return result;
}

// int dp[5][9];

// int knapSackMemo(int si, int weight[], int value[], int capacity, int n) {
// 	if (si == n) {
// 		return 0;
// 	}

// 	if (dp[si][capacity] != -1) {
// 		return dp[si][capacity];
// 	}

// 	int include = INT_MIN;

// 	if (weight[si] <= capacity) {
// 		include = value[si] + knapSackMemo(si + 1, weight, value, capacity - weight[si], n);
// 	}

// 	int skip = knapSackMemo(si + 1, weight, value, capacity, n);

// 	int result = max(include, skip);

// 	dp[si][capacity] = result;

// 	for (int i = 0; i < 5; i++) {
// 		for (int j = 0; j < 9; j++) {
// 			cout << dp[i][j] << "\t";
// 		}
// 		cout << endl;
// 	}
// 	cout << "*****************************************" << endl;

// 	return result;
// }

int knapSackDP[5][9];

int knapSackMemo(int value[], int weight[], int si, int capacity, int n) {
	if (si == 0) {
		knapSackDP[si][capacity] = 0;
		return 0;
	}

	if (knapSackDP[si][capacity] != -1) {
		return knapSackDP[si][capacity];
	}

	int include = INT_MIN;
	int exclude = INT_MIN;

	if (weight[si - 1] <= capacity) {
		include = value[si - 1] + knapSackMemo(value, weight, si - 1, capacity - weight[si - 1], n);
	}

	exclude = knapSackMemo(value, weight, si - 1, capacity, n);

	int result = max(include, exclude);

	knapSackDP[si][capacity] = result;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cout << knapSackDP[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "***************************************************" << endl;

	return result;
}

int knapSackPUREDP(int value[], int weight[], int capacity, int n) {

	int row = n + 1;
	int col = capacity + 1;

	vector<vector<int> > dp(row, vector<int> (col, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= capacity; j++) {

			int include = INT_MIN;
			int exclude = INT_MIN;

			if (weight[i - 1] <= j) {
				include = value[i - 1] + dp[i - 1][j - weight[i - 1]];
			}

			exclude = dp[i - 1][j];

			dp[i][j] = max(include, exclude);
		}
	}

	return dp[n][capacity];
}

bool isPossible(int si, vector<int> &nums, int sum, int total, vector<vector<int> > &dp) {
	if (sum == total) return true;

	if (sum > total or si == nums.size()) {
		return false;
	}

	if (dp[si][sum] != -1) {
		return dp[si][sum];
	}

	bool include = isPossible(si + 1, nums, sum + nums[si], total, dp);
	bool exclude = isPossible(si + 1, nums, sum, total, dp);

	dp[si][sum] = include or exclude;

	return dp[si][sum];
}

bool canPartition(vector<int>& nums) {
	int total = 0;

	for (int i = 0; i < nums.size(); i++) {
		total += nums[i];
	}

	if (total % 2 == 1) return false;

	total = total / 2;

	int row = nums.size() + 1;
	int col = total + 1;

	vector<vector<int> > dp(row, vector<int> (col, -1));

	return isPossible(0, nums, 0, total, dp);
}

int lps(string &str, int start, int end, vector<vector<int> > &dp) {
	if (start == end) {
		return 1;
	}

	if (start > end) return 0;

	if (dp[start][end] != -1) {
		return dp[start][end];
	}

	int result;

	if (str[start] == str[end]) {
		result = lps(str, start + 1, end - 1, dp) + 2;
	} else {
		int first = lps(str, start + 1, end, dp);
		int second = lps(str, start, end - 1, dp);

		result = max(first, second);
	}

	dp[start][end] = result;

	return result;
}

int longestPalindromeSubseqMemo(string s) {
	if (s.length() == 0) return 0;

	if (s.length() == 1) return 1;

	vector<vector<int> > dp(s.length(), vector<int> (s.length(), -1));

	return lps(s, 0, s.length() - 1, dp);
}

int longestPalindromeSubseqDP(string s) {
	if (s.length() == 0) return 0;

	if (s.length() == 1) return 1;

	vector<vector<int> > dp(s.length(), vector<int> (s.length(), 0));

	int n = dp.size();

	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	for (int col = 1; col < n; col++) {
		for (int row = col - 1; row >= 0 ; row--) {

			if (s[row] == s[col]) {
				dp[row][col] = dp[row + 1][col - 1] + 2;
			} else {
				dp[row][col] = max(dp[row + 1][col], dp[row][col - 1]);
			}

		}
	}

	return dp[0][n - 1];
}

int lengthOfLIS(vector<int>& nums) {
	if (nums.size() == 0) return 0;

	vector<int> dp(nums.size(), 1);

	int maxLen = 1;

	for (int i = 1; i < nums.size(); i++) {

		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxLen = max(dp[i], maxLen);
	}

	return maxLen;
}

int distinctSubseq(string s, int si, string t, int ti, vector<vector<int> > &dp) {
	if (ti == t.length()) {
		return 1;
	}

	if (si == s.length()) {
		return 0;
	}

	if (dp[si][ti] != -1) {
		return dp[si][ti];
	}

	int count = 0;

	if (s[si] == t[ti]) {
		count += distinctSubseq(s, si + 1, t, ti + 1, dp);
	}

	count += distinctSubseq(s, si + 1, t, ti, dp);

	dp[si][ti] = count;

	return count;
}

int numDistinctMemo(string s, string t) {

	int row = s.length() + 1;
	int col = t.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col, -1));

	return distinctSubseq(s, 0, t, 0, dp);
}

int numDistinctDP(string s, string t) {

	int row = s.length() + 1;
	int col = t.length() + 1;

	vector<vector<long> > dp(row, vector<long> (col, 0));

	for (int i = 0; i < row; i++) {
		dp[i][t.length()] = 1;
		// dp[i][col-1] = 1;
	}

	for (int i = s.length() - 1; i >= 0; i--) {
		for (int j = t.length() - 1; j >= 0; j--) {

			if (s[i] == t[j]) {
				dp[i][j] += dp[i + 1][j + 1];
			}

			dp[i][j] += dp[i + 1][j];
		}
	}

	return dp[0][0];
}

int coinChange2(int si, vector<int> &coins, int amount, vector<vector<int> > &dp) {
	if (amount == 0) {
		return 1;
	}

	if (si == coins.size()) {
		return 0;
	}

	if (dp[si][amount] != -1) {
		return dp[si][amount];
	}

	int count = 0;

	if (coins[si] <= amount) {
		count += coinChange2(si, coins, amount - coins[si], dp);
	}

	count += coinChange2(si + 1, coins, amount, dp);

	dp[si][amount] = count;

	return count;
}

int changeMemo(int amount, vector<int>& coins) {

	int row = coins.size() + 1;
	int col = amount + 1;

	vector<vector<int> > dp(row, vector<int> (col, -1));

	return coinChange2(0, coins, amount, dp);
}

int changeDP(int amount, vector<int>& coins) {

	int row = coins.size() + 1;
	int col = amount + 1;

	vector<vector<int> > dp(row, vector<int> (col, 0));

	for (int i = 0; i < row; i++) {
		dp[i][0] = 1;
	}

	for (int row = coins.size() - 1; row >= 0; row--) {
		for (int col = 1; col <= amount; col++) {

			if (coins[row] <= col) {
				dp[row][col] += dp[row][col - coins[row]];
			}

			dp[row][col] += dp[row + 1][col];
		}
	}

	return dp[0][amount];
}

int MOD = 1e9 + 7;

int diceRolls(int d, int f, int target, vector<vector<int> > &dp) {
	if (d == 0 and target == 0) {
		return 1;
	}

	if (d == 0 or target == 0) {
		return 0;
	}

	if (dp[d][target] != -1) {
		return dp[d][target];
	}

	int count = 0;

	for (int i = 1; i <= f; i++) {
		if (i <= target) {
			count = (count + diceRolls(d - 1, f, target - i, dp)) % MOD;
		} else {
			break;
		}
	}

	dp[d][target] = count;

	return count;
}

int numRollsToTargetMemo(int d, int f, int target) {

	vector<vector<int> > dp(d + 1, vector<int> (target + 1, -1));

	return diceRolls(d, f, target, dp);
}

int numRollsToTargetDP(int d, int f, int target) {

	vector<vector<int> > dp(d + 1, vector<int> (target + 1, 0));

	dp[0][0] = 1;

	for (int row = 1; row <= d; row++) {
		for (int col = 1; col <= target; col++) {

			int count = 0;

			for (int i = 1; i <= f; i++) {

				if (i <= col) {
					count = (count + dp[row - 1][col - i]) % MOD;
				} else {
					break;
				}
			}

			dp[row][col] = count;
		}
	}

	return dp[d][target];
}

int countSubstrings(string s) {

	int ans = 0;

	for (int i = 0; i < s.length(); i++) {
		// ODD LENGTH

		for (int j = 0; i + j < s.length() and i - j >= 0; j++) {
			if (s[i - j] == s[i + j]) {
				ans++;
			} else {
				break;
			}
		}

		// EVEN LENGTH

		for (int j = 0; i + j + 1 < s.length() and i - j >= 0; j++) {
			if (s[i - j] == s[i + j + 1]) {
				ans++;
			} else {
				break;
			}
		}
	}

	return ans;
}

double largestSumOfAverages(vector<int>& A, int K) {
	if (A.size() == 0) return 0;

	int row = A.size() + 1;
	int col = K + 1;

	vector<vector<double> > dp(row, vector<double> (col, -1));

	return helper(0, A, K, dp);
}

double calcAverage(int start, vector<int> &nums) {

	double sum = 0;

	for (int i = start; i < nums.size(); i++) {
		sum += nums[i];
	}

	sum = sum / (nums.size() - start);
	return sum;
}

double helper(int si, vector<int> &nums, int k, vector<vector<double> > &dp) {
	if (si == nums.size()) {
		return 0;
	}

	if (k == 1) {
		return calcAverage(si, nums);
	}

	if (dp[si][k] != -1) return dp[si][k];

	double maxValue = INT_MIN;

	double sum = 0;

	for (int i = si; i < nums.size(); i++) {

		sum += nums[i];

		double bakiKaResult = helper(i + 1, nums, k - 1, dp);

		double avg = sum / (i - si + 1);

		maxValue = max(bakiKaResult + avg, maxValue);
	}

	dp[si][k] = maxValue;

	return maxValue;
}

bool isPalindrome(string &str, int start, int end) {
	while (start <= end) {
		if (str[start] != str[end]) return false;
		start++;
		end--;
	}
	return true;
}

int partitioningPalindromeiiWeak(string &str, int start, int end, vector<vector<int> > &dp) {
	if (start >= end) return 0;

	if (isPalindrome(str, start, end)) return 0;

	if (dp[start][end] != -1) return dp[start][end];

	int minValue = INT_MAX;

	for (int i = start; i < end; i++) {

		int leftCuts = partitioningPalindromeiiWeak(str, start, i, dp);
		int rightCuts = partitioningPalindromeiiWeak(str, i + 1, end, dp);

		minValue = min(minValue, rightCuts + 1 + leftCuts);
	}

	dp[start][end] = minValue;

	return minValue;
}

int partitioningPalindromeii(string &str, int start, int end, vector<vector<int> > &dp) {
	if (start >= end) return 0;

	if (isPalindrome(str, start, end)) return 0;

	if (dp[start][end] != -1) return dp[start][end];

	int minValue = INT_MAX;

	for (int i = start; i < end; i++) {

		if (isPalindrome(str, start, i)) {
			int rightCuts = partitioningPalindromeii(str, i + 1, end, dp);

			minValue = min(minValue, rightCuts + 1);
		}
	}

	dp[start][end] = minValue;

	return minValue;
}

int minCut(string s) {
	if (s.length() == 0 or s.length() == 1) return 0;

	vector<vector<int> > dp(s.length() + 1, vector<int> (s.length() + 1, -1));

	return helper(s, 0, s.length() - 1, dp);
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

	// vector<int> v{2, 7, 9, 3, 1};
	// cout << rob(v) << endl;

	// for (int val : v) {
	// 	cout << val << " ";
	// }
	// cout << endl;

	// cout << longestCommonSubsequence("abcde", "agcte") << endl;

	// int weight[] = {5, 4, 6, 3};
	// int value[] = {50, 40, 60, 40};
	// int capacity = 8;
	// int n = 4;

	// // memset(dp, -1, sizeof(dp));
	// memset(knapSackDP, -1, sizeof(knapSackDP));


	// // cout << knapSackMemo(0, weight, value, capacity, n) << endl;
	// // cout << knapSackMemo(value, weight, n, capacity, n) << endl;

	// cout << knapSackPUREDP(value, weight, capacity, n) << endl;


	return 0;
}

// https://docs.google.com/forms/d/e/1FAIpQLSf-K-fqVB2nGcKQF4-SD10xWD8R0gfL6b3OonAwaxO4RqCsBw/viewform?fbzx=-4433023158536383665
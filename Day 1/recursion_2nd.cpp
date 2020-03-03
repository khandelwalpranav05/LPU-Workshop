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

string removeDuplicates(string str) {
	if (str.length() == 0) {
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = removeDuplicates(ros);

	if (recursionResult[0] == ch) {
		return recursionResult;
	} else {
		return ch + recursionResult;
	}
}

string addStarBetweenDuplicates(string str) {
	if (str.length() == 0) return str;

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = addStarBetweenDuplicates(ros);

	if (recursionResult[0] == ch) {
		// return ch + string("*") + recursionResult;

		recursionResult = '*' + recursionResult;
		return ch + recursionResult;
	} else {
		return ch + recursionResult;
	}
}

string moveXToEnd(string str) {
	if (str.length() == 0) return str;

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = moveXToEnd(ros);

	if (ch == 'x') {
		return recursionResult + ch;
	} else {
		return ch + recursionResult;
	}
}

string replacePi(string str) {
	if (str.length() == 0) return str;

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = replacePi(ros);

	if (ch == 'p' and recursionResult[0] == 'i') {
		return "3.14" + recursionResult.substr(1);

	} else {
		return ch + recursionResult;
	}
}

void printSubsequence(string str, string ans) {
	if (str.length() == 0) {
		cout << "" << endl;
		// cout << ans << endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	printSubsequence(ros, ans + ch);
	printSubsequence(ros, ans);
}

void printPermutations(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];

		string ros = str.substr(0, i) + str.substr(i + 1);

		printPermutations(ros, ans + ch);
	}
}

int main() {

	// cout << removeDuplicates("abbccdggf") << endl;

	// cout << addStarBetweenDuplicates("hhelloo") << endl;

	// cout << moveXToEnd("xabcxxyx") << endl;

	// cout << replacePi("xxpiipixxppix") << endl;

	// printSubsequence("abc", "");

	// printPermutations("abc", "");

	return 0;
}
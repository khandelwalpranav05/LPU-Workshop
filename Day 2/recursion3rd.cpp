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

string code[] = {".", "#", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(string str, string ans = "") {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string key = code[ch - '0'];

	for (int i = 0; i < key.length(); i++) {
		char val = key[i];
		printKeypad(ros, ans + val);
	}
}

int main() {

	printKeypad("234");

	return 0;
}
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

int main() {

	unordered_map<string, int> h;

	h["India"] = 140;
	h["Pak"] = 67;
	h["Sweden"] = 2;
	h["Norway"] = 1;

	h["India"] = 130;

	pair<string, int> p("China", 80);
	h.insert(p);

	h.insert(make_pair("LPU", 76));

	for (pair<string, int> node : h) {
		cout << node.first << " -> " << node.second << endl;
	}

	cout << h.count("India") << endl;
	cout << h.count("US") << endl;

	cout << h["China"] << endl;

	if (h.find("India") != h.end()) {
		cout << "FOUND" << endl;
	}

	if (h.find("US") == h.end()) {
		cout << "NOT FOUND" << endl;
	}

	// vector<int> v({1, 2, 3, 4, 5, 6});

	// vector<string> b({"hi", "hello", "bye", "see ya"});

	// for (auto val : v) {
	// 	cout << val << " ";
	// }
	// cout << endl;

	// for (auto val : b) {
	// 	cout << val << " ";
	// }
	// cout << endl;

	return 0;
}
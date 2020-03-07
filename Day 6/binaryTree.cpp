#include <iostream>
#include <vector>
#include <queue>
#include <list>
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

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* buildTree(node* root) {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	if (root == NULL) {
		root = new node(data);
	}

	root->left = buildTree(root->left);
	root->right = buildTree(root->right);

	return root;
}

void preOrder(node* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root) {
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(node* root) {
	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

int size(node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftSize = size(root->left);
	int rightSize = size(root->right);

	int total = leftSize + 1 + rightSize;
	return total;
}

int height(node* root) {
	if (root == NULL) {
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int total = max(leftHeight, rightHeight) + 1;
	return total;
}

int sumOfNodes(node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	int total = leftSum + rightSum + root->data;
	return total;
}

// bool search(node* root, int item) {
// TODO
// }

int diameter(node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftDiameter = diameter(root->left);
	int rightDiameter = diameter(root->right);

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int mereThrough = leftHeight + 2 + rightHeight;

	int total = max(mereThrough, max(leftDiameter, rightDiameter));

	return total;
}

class DiaHeight {
public:
	int height;
	int diameter;
};

DiaHeight diameterOptimized(node* root) {
	DiaHeight val;
	if (root == NULL) {
		val.diameter = 0;
		val.height = -1;
		return val;
	}

	DiaHeight leftPair = diameterOptimized(root->left);
	DiaHeight rightPair = diameterOptimized(root->right);

	int leftDiameter = leftPair.diameter;
	int rightDiameter = rightPair.diameter;

	int leftHeight = leftPair.height;
	int rightHeight = rightPair.height;

	int mereThrough = leftHeight + rightHeight + 2;

	int diameterTotal = max(mereThrough, max(leftDiameter, rightDiameter));

	val.diameter = diameterTotal;

	val.height = max(leftHeight, rightHeight) + 1;

	return val;
}

int main() {


	node* root = NULL;
	root = buildTree(root);

	// preOrder(root);
	// cout << endl;

	// inOrder(root);
	// cout << endl;

	// postOrder(root);
	// cout << endl;

	// cout << size(root) << endl;
	// cout << height(root) << endl;

	// cout << sumOfNodes(root) << endl;

	// cout << diameter(root) << endl;

	DiaHeight val = diameterOptimized(root);
	cout << val.diameter << endl;

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
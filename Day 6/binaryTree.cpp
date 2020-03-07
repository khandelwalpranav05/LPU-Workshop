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

bool isBalanced(node* root) {
	if (root == NULL) {
		return true;
	}

	bool leftBalanced = isBalanced(root->left);
	bool rightBalanced = isBalanced(root->right);

	if (leftBalanced == false or rightBalanced == false) {
		return false;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int gap = abs(leftHeight - rightHeight);

	if (gap > 1) {
		return false;
	} else {
		return true;
	}
}

class HeightBalanced {
public:
	int height;
	bool balance;
};

HeightBalanced isBalancedOptimized(node* root) {
	HeightBalanced val;

	if (root == NULL) {
		val.balance = true;
		val.height = -1;
		return val;
	}

	HeightBalanced leftPair = isBalancedOptimized(root->left);
	HeightBalanced rightPair = isBalancedOptimized(root->right);

	val.height = max(leftPair.height, rightPair.height) + 1;

	if (leftPair.balance == false or rightPair.balance == false) {
		val.balance = false;
		return val;
	}

	int gap = abs(leftPair.height - rightPair.height);

	if (gap > 1) {
		val.balance = false;
	} else {
		val.balance = true;
	}

	return val;
}

void printRootToLeaf(node* root, string path) {
	if (root == NULL) {
		// cout << path << endl;
		return;
	}

	string key = to_string(root->data);

	if (root->left == NULL and root->right == NULL) {
		path = path + key;
		cout << path << endl;
		return;
	}

	printRootToLeaf(root->left, path + key + "->");
	printRootToLeaf(root->right, path + key + "->");
}

string path1 = "";
string path2 = "";

void findPath(node* root, int data1, int data2, string path) {
	if (root == NULL) {
		return;
	}

	string key = to_string(root->data);

	if (root->data == data1) {
		path = path + key;
		path1 = path;
		// return;
	}

	if (root->data == data2) {
		path = path + key;
		path2 = path;
		// return;
	}

	findPath(root->left, data1, data2, path + key + "->");
	findPath(root->right, data1, data2, path + key + "->");
}

node* lowestCommonAncestor(node* root, node* p, node* q) {
	if (root == NULL) {
		return NULL;
	}

	if (root == p or root == q) {
		return root;
	}

	node* leftLCA = lowestCommonAncestor(root->left, p, q);
	node* rightLCA = lowestCommonAncestor(root->right, p, q);

	if (leftLCA == NULL and rightLCA == NULL) {
		return NULL;
	}

	if (leftLCA != NULL and rightLCA != NULL) {
		return root;
	}

	return leftLCA != NULL ? leftLCA : rightLCA;
}

vector<vector<int>> levelOrder(node* root) {

	queue<node*> q;

	vector<vector<int> > res;

	vector<int> temp;

	if (root == NULL) return res;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		node* curr = q.front();
		q.pop();

		if (curr == NULL) {
			res.push_back(temp);
			temp.clear();

			if (q.empty()) {
				break;
			}
			q.push(NULL);
			continue;
		}

		temp.push_back(curr->val);
		cout << curr->val << " ";

		if (curr->left != NULL) {
			q.push(curr->left);
		}

		if (curr->right != NULL) {
			q.push(curr->right);
		}

	}

	return res;
}

int maxPath;

int helper(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftMax = helper(root->left);
	int rightMax = helper(root->right);

	leftMax = max(0, leftMax);
	rightMax = max(0, rightMax);

	int mereThrough = leftMax + rightMax + root->val;

	maxPath = max(maxPath, mereThrough);

	return max(leftMax, rightMax) + root->val;
}

int maxPathSum(TreeNode* root) {

	maxPath = INT_MIN;
	helper(root);
	return maxPath;
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

	// DiaHeight val = diameterOptimized(root);
	// cout << val.diameter << endl;

	// cout << isBalanced(root) << endl;

	// HeightBalanced val = isBalancedOptimized(root);
	// cout << val.balance << endl;

	// printRootToLeaf(root, "");

	// findPath(root, 3, 5, "");
	// cout << path1 << endl;
	// cout << path2 << endl;

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
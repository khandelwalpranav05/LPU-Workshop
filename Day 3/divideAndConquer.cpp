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

int binarySearch(int arr[], int n, int data) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == data) {
			return mid;
		} else if (arr[mid] > data) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return -1;
}

int lowerBound(int arr[], int n, int data) {

	int start = 0;
	int end = n - 1;

	int ans = -1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == data) {
			ans = mid;
			end = mid - 1;
		} else if (arr[mid] > data) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}

int helper(vector<int>&nums, int start, int end, int target) {
	if (start > end) {
		return -1;
	}

	int mid = (start + end) / 2;

	if (nums[mid] == target) {
		return mid;
	}

	if (nums[mid] >= nums[start]) {

		if (nums[mid] > target and nums[start] <= target) {
			return helper(nums, start, mid - 1, target);
		} else {
			return helper(nums, mid + 1, end, target);
		}

	} else {
		if (nums[mid]<target and nums[end] >= target) {
			return helper(nums, mid + 1, end, target);
		} else {
			return helper(nums, start, mid - 1, target);
		}
	}
}

int searchRotatedArray(vector<int>& nums, int target) {
	return helper(nums, 0, nums.size() - 1, target);
}

void merge(int arr[], int start, int end) {

	int n = end - start + 1;

	int temp[n];

	int mid = (start + end) / 2;

	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid and j <= end) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while (j <= end) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	while (i <= mid) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	int pos = 0;
	for (int x = start; x <= end; x++) {
		arr[x] = temp[pos];
		pos++;
	}

}

void mergeSort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	merge(arr, start, end);
}

bool isPossible(int arr[], int n, int k, int time) {

	int painters = 1;
	int painterTime = 0;

	for (int i = 0; i < n; i++) {
		painterTime += arr[i];

		if (painterTime > time) {
			painters++;
			painterTime = arr[i];

			if (painters > k) {
				return false;
			}
		}
	}

	return true;
}

int painterProblem(int arr[], int n, int k) {

	int minTime = arr[0];
	int maxTime = arr[0];

	for (int i = 1; i < n; i++) {
		minTime = max(arr[i], minTime);
		maxTime += arr[i];
	}

	int ans = maxTime;

	while (minTime <= maxTime) {

		int mid = minTime + (maxTime - minTime) / 2;

		if (isPossible(arr, n, k, mid)) {
			ans = mid;
			maxTime = mid - 1;
		} else {
			minTime = mid + 1;
		}
	}

	return ans;
}

bool canPlace(int arr[], int n, int k, int dist) {

	int cows = 1;

	int pos = arr[0];

	for (int i = 1; i < n; i++) {

		if (arr[i] - pos >= dist) {
			cows++;
			pos = arr[i];

			if (cows == k) {
				return true;
			}
		}
	}

	return false;
}

int aggressiveCows(int arr[], int n, int cows) {

	sort(arr, arr + n);

	int minDist = 0;
	int maxDist = arr[n - 1] - arr[0];

	int ans = minDist;

	while (minDist <= maxDist) {

		int mid = minDist + (maxDist - minDist) / 2;

		if (canPlace(arr, n, cows, mid)) {
			ans = mid;
			minDist = mid + 1;
		} else {
			maxDist = mid - 1;
		}

	}

	return ans;
}

void quickSort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}

	int mid = start + (end - start) / 2;

	int pivot = arr[mid];

	int left = start;
	int right = end;

	while (left <= right) {

		while (arr[left] < pivot) {
			left++;
		}

		while (arr[right] > pivot) {
			right--;
		}

		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	quickSort(arr, start, right);
	quickSort(arr, left, end);
}

int main() {

	// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int n = 9;
	// int data = 8;

	// cout << binarySearch(arr, n, data) << endl;

	// int arr[] = {1, 1, 2, 2, 2, 2, 4, 4, 5};
	// int n = 9;
	// int data = 2;

	// cout << lowerBound(arr, n, data) << endl;

	int arr[] = {7, 6, 5, 4, 3, 2, 1};
	int n = 7;

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// int boards[] = {10, 20, 30, 40};
	// int n = 4;
	// int k = 2;

	// cout << painterProblem(boards, n, k) << endl;

	// int arr[] = {1 , 2 , 8 , 4 , 9};
	// int n = 5;
	// int cows = 3;

	// cout << aggressiveCows(arr, n, cows) << endl;

	return 0;
}
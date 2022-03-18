// Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
// https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1

#include<bits/stdc++.h>
#define long long ll
using namespace std;

int maxIndex1(int *arr, int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr[j] > arr[i]) {
				ans = max(ans, j - i);
			}
		}
	}
	return ans;
}
// Using Sorting
// TIme Complexity : O(nlogn)
int maxIndex2(int *arr, int n) {
	vector<pair<int, int>> pairs;
	for (int i = 0; i < n; i++) {
		pairs.push_back({arr[i], i});
	}

	sort(pairs.begin(), pairs.end());


	// Traverse from the end of an array and maintain the maxSoFar and the difference
	int maxSoFar = INT_MIN;
	int diff = INT_MIN;

	for (int i = n - 1; i >= 0; i--) {
		int index = pairs[i].second;

		if (maxSoFar < index) {
			maxSoFar = index;
		}

		diff = max(diff, maxSoFar - index);
	}

	return diff;
}


int maxIndex3(int *arr, int n) {
	// create an auxiliary array of size `n`
	int aux[n];

	// `aux[j]` stores the maximum element in subarray `arr[j, n-1]`
	aux[n - 1] = arr[n - 1];
	for (int j = n - 2; j >= 0; j--) {
		aux[j] = max(arr[j], aux[j + 1]);
	}

	// for(int i = 0; i < n; i++) {
	// 	cout << aux[i] << " ";
	// }
	// cout << endl;

	// stores the maximum value of `j-i` such that `arr[j] > arr[i]`
	int diff = numeric_limits<int>::min();

	// Find maximum `j-i` using the auxiliary array
	int i = 0, j = 0;
	while(i < n && j < n) {
		if (arr[i] < aux[j]) {
			diff = max(diff, j - i);
			j++;
		}
		else {
			i++;
		}
	}

	return diff;
}
int main() {

	// int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
	int arr[] = {65, 6, 74, 94, 56, 89, 9, 63, 75, 25, 34, 68, 93, 48, 16};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxIndex1(arr, n) << endl;
	cout << maxIndex2(arr, n) << endl;

	cout << maxIndex3(arr, n) << endl;


	return 0;
}

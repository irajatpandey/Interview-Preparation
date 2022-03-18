#include<bits/stdc++.h>
#define long long ll
using namespace std;


// Time Complexity : O(logn)
int binarySearch(int arr[], int start, int end, int target) {
	if (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] > target) {
			return binarySearch(arr, start, mid - 1, target);
		}
		else if (arr[mid] < target) {
			return binarySearch(arr, mid + 1, end, target);
		}

		else {
			return mid;
		}
	}

	return -1;
}

int main() {

	int arr[] = {12, 21, 34, 43, 54};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 423;
	cout << binarySearch(arr, 0, n - 1, target);

	return 0;
}

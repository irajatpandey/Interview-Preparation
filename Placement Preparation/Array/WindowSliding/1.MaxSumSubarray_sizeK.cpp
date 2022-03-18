#include<bits/stdc++.h>
#define long long ll
using namespace std;

int maxSumSubarraySizeK(int arr[], int n, int k) {
	int j = 0, i = 0, mx = 0, sum = 0;

	// j - i + 1 is the window size
	while (j < n) {
		sum += arr[j];
		if (j - i + 1 < k) j++;
		else if (j - i + 1 == k) {
			mx = max(mx, sum);
			sum = sum - arr[i];
			i++; j++;
		}
	}
	return mx;
}

int main() {
	int arr[] = {2, 5, 1, 8, 2, 9, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	int k = 3;

	cout << maxSumSubarraySizeK(arr, n, k);
	return 0;
}

#include<bits/stdc++.h>
#define long long ll
using namespace std;

//Time Complexity: O(N).
// Auxiliary Space: O(N).
int lenOfLongSubarr(vector<int> &arr, int target)
{
	// Complete the function
	int n = arr.size();
	unordered_map<int, int> mp;
	mp[0] = -1;
	int len = 0, sum = 0;
	int endIndex =  -1;

	for (int i = 0; i < n; i++) {

		sum += arr[i];

		if (mp.find(sum) == mp.end()) {
			mp[sum] = i;
		}

		if (mp.find(sum - target) != mp.end() && len < i - mp[sum - target]) {
			len =  i - mp[sum - target];
		}


	}

	return len;
}

//Time Complexity: O(N).
// this will fail for the negative numbers
int longestSubArraySumK(vector<int> &arr, int target) {
	int n = arr.size();

	int i = 0, j = 0, mx = INT_MIN, sum = 0;

	while (j < n) {
		sum += arr[j];

		if (sum < target) {
			j++;
		}

		else if (sum == target) {
			mx = max(mx, j - i + 1);
			j++;
		}
		else if (sum > target) {
			while (sum > target) {
				sum = sum - arr[i];
				i++;
			}
			j++;
		}
	}
	return mx;

}
int main() {

	vector<int> arr = {4, 1, 1, 1, 2, 3, 5};
	int k = 5;

	cout << longestSubArraySumK(arr, k);
	return 0;
}

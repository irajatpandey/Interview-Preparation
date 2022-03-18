// Infinite Supply - Find the total Combination
#include<bits/stdc++.h>
using namespace std;


int coinChange1(vector<int> &arr, int target) {
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (int val : arr) {
		for (int i = val; i < dp.size(); i++) {
			dp[i] += dp[i - val];
		}
	}
	return dp[target];
}


int main() {
	vector<int> arr = {1, 2, 3};
	int target = 4;
	cout << coinChange1(arr, target);
	return 0;
}

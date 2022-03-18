// Infinite Supply - Find the total Combination
#include<bits/stdc++.h>
using namespace std;


int coinChange2(vector<int> &arr, int target) {
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < dp.size(); i++) {
		for (int coin : arr) {
	
			if (coin <= i) {
				dp[i] += dp[i - coin];
			}

		}
	}

	// for(int i : dp) cout << i << " ";
	// cout << endl;
	return dp[target];
}
int main() {
	vector<int> arr = {1, 2, 3};
	int target = 4;
	cout << coinChange2(arr, target);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int min_value = INT_MAX;

int stairCaseMinimumJump_Memoization(int n, int arr[], int dp[]) {
	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		int min_value = INT_MAX;
		if(arr[i] > 0)
		for(int jumps = 1; jumps <= arr[i]; jumps++){
			if(dp[i + jumps] != -1)
			min_value = min(min_value,dp[i + jumps]);
		}

		if(min_value != INT_MAX){
			dp[i] = min_value + 1;
		}
		else{
			dp[i] = -1;
		}
	}
	return dp[0];

}
int main() {

	int arr[] = {3, 2, 4, 2, 0, 2, 3, 1, 2, 2};
	int size = sizeof(arr) / sizeof(arr[0]);
	int n = 10;

	int dp[n + 1] = {0};
	memset(dp, 9, sizeof(dp));

	for(int i = 0; i <= n; i++) {
		dp[i] = -1;
	}
	// cout << endl;

	int smallOutput = stairCaseMinimumJump_Memoization(n, arr, dp);
	cout << smallOutput << endl;

	for(int i = 0; i <= n; i++) {
		cout << dp[i] << " "; 
	}
	cout << endl;
	// cout << min_value;

	return 0;
}

// https://leetcode.com/problems/climbing-stairs/
#include<bits/stdc++.h>
#define long long ll
using namespace std;


// Brute Force
// Time Complexity O(2^n)
int climbStairs(int n) {

	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}

	int answer1 = climbStairs(n - 1);
	int answer2 = climbStairs(n - 2);

	return answer1 + answer2;

}

int climbStairs_Memoization(int n, int *dp) {
	if (n == 0) {
		return 1;
	}

	if (n < 0) {
		return 0;
	}

	if (dp[n] != 0) {
		return dp[n];
	}


	int smallOutput = climbStairs_Memoization(n - 1, dp) + climbStairs_Memoization(n - 2, dp);
	dp[n] = smallOutput;
	return smallOutput;

}

// Top-Down Apporach 
int climbStairs_TopDown(int n, int dp[]){
	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}
int main() {

	int n = 5; // output : 8
	// int smallOutput = climbStairs(n);
	// cout << smallOutput << endl;
	
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	// cout << endl;
	// auto ans = climbStairs_Memoization(n, dp);
	// cout << ans << endl;

	int ans3 = climbStairs_TopDown(n, dp);
	// for (int i = 0; i < n + 1; i++) cout << dp[i] << " ";

	cout << ans3 << endl;


	return 0;
}

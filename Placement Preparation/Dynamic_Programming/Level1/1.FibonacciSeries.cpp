#include<bits/stdc++.h>
#define long long ll
using namespace std;

int fibo(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return fibo(n - 1) + fibo(n - 2);
}

int fibo_Memoization(int n, int *dp) {
	if (n == 0 || n == 1) {
		return n;
	}

	if (dp[n] != 0) {
		return dp[n];
	}

	int ans = fibo_Memoization(n - 1, dp) + fibo_Memoization(n - 2, dp);
	dp[n] = ans;
	return ans;

}
int main() {

	int n = 10; // output : 55;
	cout << fibo(n) << endl;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n + 1; i++) cout << dp[i] << " ";
	cout << endl;
	cout << fibo_Memoization(10, dp);


	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define M 50
#define N 50
void display(vector<vector<bool>> &dp) {
	for (auto it : dp) {
		for (int j : it) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// Recursive Solution for the target sum having polynomial time complexity
bool targetSumSubset(vector<int> &arr, int sum, int index, int target) {
	if (arr.size() == index) {
		if (sum == target) {
			return true;
		}
		return false;
	}
	if (sum == target) {
		cout << sum << endl;
		return true;
	}

	int choice1 = targetSumSubset(arr, sum, index + 1, target);
	int choice2 = targetSumSubset(arr, sum + arr[index], index + 1, target);


	return choice1 or choice2;
}

bool lookup[M][N];

bool targetSumSubset_Memoization(vector<int> &arr, int n, int sum) {

	if (n <= 0) return false;
	if (sum == 0) return true;

	if (lookup[n - 1][sum] != false) {
		return lookup[n - 1][sum];
	}

	if (arr[n - 1] > sum) {
		return lookup[n - 1][sum] = targetSumSubset_Memoization(arr, n - 1, sum);
	}
	else {

		int choice1 = targetSumSubset_Memoization(arr, n - 1, sum);
		int choice2 = targetSumSubset_Memoization(arr, n - 1, sum - arr[n - 1]);

		lookup[n - 1][sum] = choice1 or choice2;
		return lookup[n - 1][sum];
	}


	// return choice1 or choice2;

}

bool targetSumSubset_tabulation(vector<int> &arr, int target) {
	vector<bool> v(target + 1, false);
	vector<vector<bool>> dp(arr.size() + 1, v);

	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = true;
			}

			else if (i == 0) {
				dp[i][j] = false;
			}

			else if (j == 0) {
				dp[i][j] = true;
			}

			else {
				int val = arr[i - 1];
				if (j >= val) {
					dp[i][j] = dp[i - 1][j] or dp[i - 1][j - val];
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	display(dp);
	return dp[arr.size()][target];
}
int main() {
	vector<int> arr = {4, 2, 7, 1, 3};
	cout << targetSumSubset_tabulation(arr, 10) << endl;
	// cout << targetSumSubset(arr, 0, 0, 10);
	// memset(lookup, false, sizeof(lookup));
	// cout << targetSumSubset_Memoization(arr, arr.size(), 10) << endl;

	// cout << endl;

	// for (int i = 0; i <= arr.size(); i++) {
	// 	for (int j = 0; j <= 10; j++) {
	// 		cout << lookup[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	return 0;
}

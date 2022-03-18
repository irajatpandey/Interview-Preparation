#include<bits/stdc++.h>
using namespace std;
int knapSack_unbounded(vector<int> &value, vector<int> &weight, int capacity) {
	vector<int> v(capacity + 1, 0);
	vector<vector<int>> dp(value.size() + 1, v);
	dp[0][0] = 0;
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j <= capacity; j++) {
			if (j == 0) {
				dp[i][j] = 0;
			}
			else if (i == 0) {
				dp[i][j] = 0;
			}

			else {
				// if the current weight (weight[i - 1]) > then answer will be same as the above row
				if (j < weight[i - 1]) {
					dp[i][j] = dp[i - 1][j];
				}

				else if (j >= weight[i - 1]) {
					int pickTheBag = dp[i][j - weight[i - 1]] + value[i - 1];
					dp[i][j] = max(dp[i - 1][j], pickTheBag);

				}
			}

		}

	}
	// display(dp);
	return dp[value.size()][capacity];
}
int rodCuttingProblem(vector<int> &arr, int n) {
	vector<int> rodLength;
	for (int i = 0; i < n; i++) {
		rodLength.push_back(i + 1);
	}

	return knapSack_unbounded(arr, rodLength, n);
}

int main() {

	int n = 8;
	vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
	cout << rodCuttingProblem(arr, n);
	return 0;
}

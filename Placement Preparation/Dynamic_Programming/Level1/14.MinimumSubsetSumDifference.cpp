#include<bits/stdc++.h>
using namespace std;

vector<bool> targetSumSubset(vector<int> &arr, int sum) {
	int n = arr.size();
	bool dp[n + 1][sum + 1];
	memset(dp, false, sizeof(dp));


	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 && j == 0)
				dp[i][j] = true;
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
	vector<bool> res;
	

	for (int i = 0; i <= sum; i++) {
		res.push_back(dp[n][i]);
	}
	return res;
}
int main() {
	vector<int> arr = {20, 19, 18, 20, 16};
	int sum = 0;
	for (int item : arr) sum += item;

	vector<bool> rangeArray = targetSumSubset(arr, sum);
	// for (auto it : rangeArray) cout << it << " ";
	// cout << endl;

	vector<int> smallOutput;
	for (int i = 0; i <= rangeArray.size() / 2; i++) {
		if (rangeArray[i] == true) {
			int absoluteDifferenceOfSubset = sum - (2 * i);
			smallOutput.push_back(absoluteDifferenceOfSubset);
		}
	}
	int ans = INT_MAX;
	for (auto it : smallOutput) {
		// cout << it << " ";
		ans = min(ans, it);
	}

	cout << endl << ans << endl;
	return 0;
}

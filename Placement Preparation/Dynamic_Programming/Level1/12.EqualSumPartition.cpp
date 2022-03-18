#include<bits/stdc++.h>
using namespace std;

bool equalSumPartition(vector<int> arr) {
	int sum = 0;
	for (int val : arr)
		sum += val;

	if (sum % 2 != 0) return false;


	sum = sum / 2;
	
	bool dp[arr.size() + 1][sum + 1] = {false};
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	for (int i = 0; i <= arr.size(); i++) {
		for (int j = 0; j <= sum; j++) {
			if(i == 0 && j == 0){
				dp[i][j] = true;
			}
			else if(i == 0){
				dp[i][j] = false;
			}

			else if(j == 0){
				dp[i][j] = true;
			}

			else if (arr[i - 1] <= j){
				dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
			}
		
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

		for (int i = 0; i <= arr.size(); i++) {
		for (int j = 1; j <= sum; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}



	return dp[arr.size()][sum];

}
int main() {

	vector<int> arr = {1, 5, 11, 5};
	cout << equalSumPartition(arr);

	return 0;
}

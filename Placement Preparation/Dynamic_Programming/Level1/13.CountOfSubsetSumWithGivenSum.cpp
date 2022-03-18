#include<bits/stdc++.h>
using namespace std;

int countOfSubsetSumWithGivenSum(vector<int> &arr, int sum) {
	int n = arr.size();
	int dp[n + 1][sum + 1] = {0};

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = 1;

			}
			else if (i == 0) {
				dp[i][j] = 0;
			}
			else if(j == 0){
				dp[i][j] = 1;

			}

			else{
				if(j >= arr[i - 1]){
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];

				}
				else{
					dp[i][j] = dp[i - 1][j];

				}
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[n][sum];
}
int main() {

	vector<int> arr = {2, 3, 5, 6, 8, 10};
	int sum = 10;

	cout << countOfSubsetSumWithGivenSum(arr, sum) << endl;



	return 0;
}

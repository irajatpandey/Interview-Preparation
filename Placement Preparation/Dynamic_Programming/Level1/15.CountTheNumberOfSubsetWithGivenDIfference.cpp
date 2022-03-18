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
	return dp[n][sum];
}
int countSubsetWithGivenDifference(vector<int> &arr, int difference){
	int sum = 0;
	for(int it : arr) sum += it;
	int s1 = (difference + sum)/2;
	// cout << s1 << endl;

	return countOfSubsetSumWithGivenSum(arr, s1);
}
	
int main(){

	vector<int> arr = {1, 1, 2, 3};
	int diff = 1;
	cout << countSubsetWithGivenDifference(arr, diff);

	return 0;
}

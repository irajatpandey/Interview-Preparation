#include<bits/stdc++.h>

using namespace std;
/*
Time Complexity :
The time complexity of this method is O(n*c) where n is the total number of items and c is the capacity of the bag given to us. 
This is because we are running a nested loop and the outer loop runs for c times and the inner loop runs for n times.

SPACE COMPLEXITY :
The space complexity of this method is O(n*c) where c is the capacity of the bag given to us as we are making an array dp of size c+1.

*/
int knapSack_unbounded(vector<int> &value, vector<int> &weight, int capacity){
	vector<int> v(capacity + 1, 0);
	vector<vector<int>> dp(value.size() + 1, v);
	dp[0][0] = 0;
	for(int i = 0; i < dp.size(); i++){
		for(int j = 0; j <= capacity; j++){
			if(j == 0){
				dp[i][j] = 0;
			}
			else if(i == 0){
				dp[i][j] = 0;
			}

			else{
				// if the current weight (weight[i - 1]) > then answer will be same as the above row
				if(j < weight[i - 1]){
					dp[i][j] = dp[i - 1][j];
				}

				else if(j >= weight[i -1]){
					int pickTheBag = dp[i][j - weight[i-1]] + value[i - 1];
					dp[i][j] = max(dp[i - 1][j], pickTheBag);

				}
			}

		}

	}
	// display(dp);
		return dp[value.size()][capacity];
}
int main() {

	vector<int> wt = {2, 5, 1, 3, 4};
	vector<int> value = {15, 14, 10, 45, 30};

	int capacity = 7;

	cout << knapSack_unbounded(value, wt, capacity);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> &dp) {
	for (auto it : dp) {
		for (int j : it) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}
// Time Complexity: O(2 ^n)

int knapSack_recursive(vector<int> &value, vector<int> &weight, int capacity, int n){
	if(n == 0 || capacity == 0){
		return 0;
	}

	if(weight[n - 1] > capacity){
		return knapSack_recursive(value, weight, capacity, n - 1);
	}
	else{
		// we have two options either we choose the include the item or we don't include 
		int choice1 = value[n - 1] + knapSack_recursive(value, weight, capacity - weight[n - 1], n - 1);
		int choice2 = knapSack_recursive(value, weight, capacity, n - 1);

		return max(choice1, choice2);
	}

}
/*
The time complexity of this method using tabulation in dynamic programming is O(n*c) where n is the number of items given to us and c is the capacity of the bag. 
This is because we have stored and traversed the values in a 2-D matrix dp which is of the order (n+1)*(c+1). 
Notice how the time complexity is reduced in comparison with the recursion and backtracking method (which was O(2n)).

*/
int knapSack_tabulation(vector<int> &value, vector<int> &weight, int capacity){
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
					int pickTheBag = dp[i - 1][j - weight[i-1]] + value[i - 1];
					dp[i][j] = max(dp[i - 1][j], pickTheBag);

				}
			}

		}

	}
	display(dp);
		return dp[value.size()][capacity];
}
int main(){

	vector<int> wt = {2, 5, 1, 3, 4};
	vector<int> value = {15, 14, 10, 45, 30};

	int capacity = 7;

	cout << knapSack_tabulation(value, wt, capacity) << endl;

	cout << knapSack_recursive(value, wt, capacity, value.size());

	return 0;
}

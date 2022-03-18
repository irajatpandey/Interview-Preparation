#include<bits/stdc++.h>
using namespace std;
int dp[3][3] ={0}; 
int minimumCostPath_Memoization(vector<vector<int>> &path, int i, int j) {
	int m = path.size() - 1;
	int n = path[0].size() - 1;
	if (i > m || j > n) return INT_MAX;

	else if (i == m && j == n){ 
		dp[i][j] = path[i][j];
		return path[i][j];
	}



	if (i == m - 1 && j == n - 1)
		dp[i][j] = path[i][j];
	if (dp[i][j] != 0) {
		return dp[i][j];
	}


	int x = minimumCostPath_Memoization(path, i + 1, j);
	int y = minimumCostPath_Memoization(path, i, j + 1);

	int smallOutput = min(x, y) + path[i][j];
	dp[i][j] = smallOutput;
	return smallOutput;

}

int minimumCostPath_tabulation(vector<vector<int>> &path, int i, int j) {
	int m = path.size();
	int n = path[0].size();
	// int **dp = new int*[m];
	// for(int i = 0; i < m; i++){
	// 	int *arr = new int[n];
	// 	dp[i] = arr;
	// }
	vector<int> v(n, 0);
	vector<vector<int>> dp(m, v);
	

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (i == m - 1 && j == n - 1) {
				dp[i][j] = path[i][j];
			}
			else if(i == m - 1){
				dp[i][j] = dp[i][j + 1] + path[i][j];

			}
			else if (j == n - 1) {
				dp[i][j] = dp[i + 1][j] + path[i][j];
			}
			else {
				dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + path[i][j];
			}
		}
	}
	// for(auto it : dp){
	// 	for(auto j : it){
	// 		std::cout << j << " ";
	// 	}
	// 	std :: cout << endl;
	// }
	return dp[0][0];
}

int minimumCostPath(vector<vector<int>> &path, int i, int j) {
	int m = path.size() - 1;
	int n = path[0].size() - 1;
	if (i > m || j > n) return INT_MAX;
	else if (i == m && j == n) return path[i][j];

	int x = minimumCostPath(path, i + 1, j);
	int z = minimumCostPath(path, i , j + 1);



	int smallOutput = min(z, x) + path[i][j];

	return smallOutput;

}
int main() {

	vector<vector<int>> path = { { 1, 2, 3 }, { 4, 8, 2 }, { 1, 5, 3 } };
	int m = path.size();
	int n = path[0].size();
	// cout << minimumCostPath(path, 0, 0) << endl;

	

	cout << minimumCostPath_tabulation(path, m -1, n - 1) << endl;
	// cout << minimumCostPath_Memoization(path, 0, 0) << endl;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			// dp[i][j] = 0;
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

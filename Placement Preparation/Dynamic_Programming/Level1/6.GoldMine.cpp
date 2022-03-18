#include<bits/stdc++.h>
using namespace std;

int goldMine_recursive(vector<vector<int>> &grid, int i , int j) {
	int m = grid.size();
	int n = grid[0].size();
	if (i < 0) return 0;
	if (j >= n or i >= m ) return 0;


	int x = goldMine_recursive(grid, i - 1, j + 1); // right-top
	int y = goldMine_recursive(grid, i, j + 1); // right
	int z = goldMine_recursive(grid, i + 1, j + 1); // right-bottom

	int smallOutput = grid[i][j] + max(max(x, y), z);
	return smallOutput;

}

void display(vector<vector<int>> &dp) {
	for (auto it : dp) {
		for (int j : it) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int goldMine_memoization(vector<vector<int>> &grid, int i , int j, vector<vector<int>> &lookup) {
	int m = grid.size();
	int n = grid[0].size();
	if (i < 0) return 0;
	if (j >= n or i >= m ) return 0;
	if (lookup[i][j] != 0) return lookup[i][j];

	int x = goldMine_recursive(grid, i - 1, j + 1); // right-top
	int y = goldMine_recursive(grid, i, j + 1); // right
	int z = goldMine_recursive(grid, i + 1, j + 1); // right-bottom
	
	int smallOutput = grid[i][j] + max(max(x, y), z);
	lookup[i][j] = smallOutput;
	// cout << "smallOutput " << smallOutput << endl;
	return smallOutput;

}

int goldMine_tabulation(vector<vector<int>> &grid) {
	vector<int> v(grid[0].size(), 0);
	vector<vector<int>> dp(grid.size(), v);
	int m = grid.size();
	int n = grid[0].size();

	for (int j = n - 1; j >= 0; j--) {
		for (int i = m - 1; i >= 0; i--) {
			if (j == n - 1) {
				dp[i][j] = grid[i][j];
			}
			else if (i == 0) {
				dp[i][j] = grid[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
			}
			else if (i == m - 1) {
				dp[i][j] = grid[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);

			}
			else {
				dp[i][j] = grid[i][j] + max(max(dp[i][j + 1], dp[i + 1][j + 1]), dp[i - 1][j + 1]);

			}
		}
	}


	int max = dp[0][0];
	for (int i = 1; i < m; i++) {
		if (max < dp[i][0]) {
			max = dp[i][0];
		}
	}

	display(dp);
	return max;
}

int main() {

	vector<vector<int>> grid = {{0, 1, 4, 2, 8, 2}, {4, 3, 6, 5, 0, 4}, {1, 2, 4, 1, 4, 6}, {2, 0, 7, 3, 2, 2}, {3, 1, 5, 9, 2, 4}, {2, 7, 0, 8, 5, 1}};
	int maxGold = INT_MIN;

	for (int i = 0; i < grid.size(); i++) {
		int ans = goldMine_recursive(grid, i, 0);
		maxGold = max(maxGold, ans);
	}
	cout << maxGold << endl;
	cout << goldMine_tabulation(grid) << endl;


	// Using Memoization

	vector<int> v(grid[0].size(), 0);
	vector<vector<int>> lookup(grid.size(), v);
	cout << "Using Memoization" << endl;
	int totalGold = INT_MIN;
	for (int i = 0; i < grid.size(); i++){
		int ans = goldMine_memoization(grid, i, 0, lookup);
		totalGold = max(totalGold, ans);
	}
	cout << totalGold << endl;

	cout << "lookup DP \n";
	display(lookup);

	return 0;
}

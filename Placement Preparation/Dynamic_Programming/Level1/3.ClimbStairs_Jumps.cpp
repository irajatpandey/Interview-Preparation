// You are given n representing the number of stairs.
// You are on the 0th step and are required to climb to the top.
// You are given n numbers, where i-th element's value represents - till how far from the step you could jump to in a single move.
// You are required to print the number of different paths via which you can climb to the top.
// Let's say if the value at the 1st index is 4 then it means from the 1st index you can make 1, 2, 3, 4 jumps to index 2, 3, 4, 5 respectively. 
// Provided after the jumps you don't go out of the array. 
// What I mean by that is if we are in the 5-th index and we can make max 3 length jumps but we can't because any jump will take us out of the array.

#include<bits/stdc++.h>
using namespace std;

int stairsCase_Memoization(int n, int startIndex, int arr[], int dp[]){
	// dp[n] = 1;
	if(n == startIndex){		 
		return 1;
	}
	if(dp[startIndex] != -1){
		return dp[startIndex];
	}
	int count = 0;
	for(int jumps = 1; jumps <= arr[startIndex]; jumps++){
		if(jumps + startIndex <= n){
			count += stairsCase_Memoization(n, jumps + startIndex, arr, dp);
		}
		else{
			break;
		}
	}
	dp[startIndex] = count;
	return count;

}
int staircase_tabulation(int n, int arr[]){
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));

	dp[n] = 1;

	for(int i = n - 1; i >= 0; i--){
		for(int jumps = 1; jumps <= arr[i] && i + jumps <= n; jumps++){
			dp[i] = dp[i] + dp[i + jumps];
		}
	}
		
	return dp[0];

}
int main(){

	int arr[] = {2, 4, 1, 0, 3, 2};
	int n = 6;
	int sizeofArr = sizeof(arr)/sizeof(arr[0]);
	int dp[n + 1] = {0};
	memset(dp, -1, sizeof(dp));

	int ans1 = stairsCase_Memoization(n, 0, arr, dp);
	cout << ans1 << endl;


	int ans2 = staircase_tabulation(n, arr);
	cout << ans2 << endl;



	return 0;
}

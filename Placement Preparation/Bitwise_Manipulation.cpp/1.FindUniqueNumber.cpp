// Given a list of number where every number occurs twice except one. Find the unique number.

#include<bits/stdc++.h>
using namespace std;

// Bitwise XOR operation to solve the problem
// Space Complexity: O(1)
int uniqueNumber(int *arr, int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = ans ^ arr[i];
	}
	return ans;
}

int main(){


	int arr[] = {3, 2, 3, 5, 6, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << uniqueNumber(arr, n) << endl;
	return 0;
}
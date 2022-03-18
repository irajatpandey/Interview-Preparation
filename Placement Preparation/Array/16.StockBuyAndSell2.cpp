#include<bits/stdc++.h>
#define long long ll
using namespace std;
// LeetCode - 122
int stockBuyAndSell(int *arr, int n){
	int profit = 0;
	for(int i = 1; i < n; i++){
		if(arr[i] > arr[i - 1]){
			profit += arr[i] - arr[i - 1];
		}
	}
	return profit;
}

int main() {

	int arr[] = {7, 1, 5, 3, 6, 4};
	int n = sizeof(arr) / sizeof(arr[0]);


	cout << stockBuyAndSell(arr, n) << endl;
	return 0;
}

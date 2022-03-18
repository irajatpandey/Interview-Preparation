#include<bits/stdc++.h>
#define long long ll
using namespace std;

// Time Complexity : O(n^2)
int bruteforce_maxSubArraySum(int *arr, int n){
	int maximum = INT_MIN;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i; j < n; j++){
			sum += arr[j];
			if(sum > maximum){
				maximum = sum;
			}
		}
		
	}
	return maximum;
}
	
int kadanesAlgo(int *arr, int n){
	int currentBestSum = arr[0];
	int overallBestSum = arr[0];

	for(int i = 1; i < n; i++){
		if(arr[i] + currentBestSum > arr[i]){
			currentBestSum = arr[i] + currentBestSum;
		}
		else{
			currentBestSum = arr[i];
		}

		overallBestSum = max(overallBestSum, currentBestSum);
	}
	return overallBestSum;
}
int main(){

	int arr[] = {4, 3, -2, 6, -14, 7, -1, 4, 5, 7, -10, 2, 9, -10, -5, -9, 6, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << bruteforce_maxSubArraySum(arr, n) << endl;
	cout << kadanesAlgo(arr, n) << endl;
	return 0;
}

// Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
// Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

// Example 1:

// Input: 
// n = 5 
// A[] = {1,3,5,2,2} 
// Output: 3 
// Explanation: For second test case 
// equilibrium point is at position 3 
// as elements before it (1+3) = 
// elements after it (2+2). 

// Time Complexity: O(n)
#include<bits/stdc++.h>
#define long long ll
using namespace std;

int equilibriumIndex(int *arr, int n){
	int totalSum = 0;
	for(int i = 0; i < n; i++){
		totalSum += arr[i];
	}


	int leftSum = 0;

	for(int i = 0; i < n; i++){

		totalSum = totalSum - arr[i];
		if(totalSum == leftSum){
			return i + 1;
		}

		else{
			leftSum += arr[i];
		}
	}

	return -1;
}
int main(){

	int arr[] = {1, 3, 5, 2, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << "Equilibrium Point is: "<< equilibriumIndex(arr, n);
	return 0;
}

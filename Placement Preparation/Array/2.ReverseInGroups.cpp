// Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

// Example 1:

// Input:
// N = 5, K = 3
// arr[] = {1,2,3,4,5}
// Output: 3 2 1 5 4
// Explanation: First group consists of elements
// 1, 2, 3. Second group consists of 4,5.

#include<bits/stdc++.h>
#define long long ll
using namespace std;
void display(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
void reverse(int *arr, int start, int end, int n){
	while(start < end){
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
}
void reverseArrayInGroups(int *arr, int n, int k){
	int end = -1;
	for(int i = 0; i < n; i += k){
		end += k;
		if(end >= n){
			end = n - 1;
		}
		reverse(arr, i, end, n);
	}


}
	
int main(){

	int arr[] = {1,2,3,4,5};
	// int as; cin >> as;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	// reverseArrayInGroups(arr, n, k);


	// Using STL
	for(int i = 0; i < n; i += k){
		if(i + k <= n)
			reverse(arr + i, arr + i + k);
		else
			reverse(arr + i, arr + n);
	}
	display(arr, n);



	return 0;
}

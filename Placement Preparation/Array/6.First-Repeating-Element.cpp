// Given an array arr[] of size n, find the first repeating element. The element should occurs more than once and the index of its first occurrence should be the smallest.

// Example 1:

// Input:
// n = 7
// arr[] = {1, 5, 3, 4, 3, 5, 6}
// Output: 2

// Time Complexity: O(nlogn)
// Auxilliary Space: O(n)
#include<bits/stdc++.h>
#define long long ll
using namespace std;


int firstRepeatingElement(int *arr, int n) {
	unordered_map<int,int> mp;
	for(int i = 0; i < n; i++) mp[arr[i]]++;

	for(int i = 0; i < n; i++){
		if(mp[arr[i]] > 1){
			return i + 1;
		}
	}
	return -1;
}
int main(){
	
	int arr[] = {1, 5, 3, 4, 3, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << firstRepeatingElement(arr, n);

	return 0;
}

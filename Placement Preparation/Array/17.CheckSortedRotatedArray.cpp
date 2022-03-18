#include<bits/stdc++.h>
#define long long ll
using namespace std;

// LeetCode - 1752	


// If array is sorted and rotated, there will be only 1 break point where arr[i] > arr[i+1].
// else if it is only sorted, then 0 break points.
// Here we will keep track of the break points
bool isSortedRotatedArray(int *arr, int n){
	 int cnt = 0;
	 for(int i = 0; i < n; i++){
	 	if(arr[i] > arr[(i+1)%n]) cnt++;
	 }

	 return cnt <= 1;
}
//the reason we use %n is because when we reach the last index, if we continue with the condition (nums[i+1]), 
// it will go out of bounds.Therefore we use modulo size to get back and check with the first element in the rotated sorted array.
//Time Complexity: O(n)
//Space Complexity: O(1)

int main(){

	int arr[] = {3, 4, 5, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	bool flag = isSortedRotatedArray(arr, n);
	if(flag) cout << "True" << endl;
	else cout << "False" << endl;

	return 0;
}

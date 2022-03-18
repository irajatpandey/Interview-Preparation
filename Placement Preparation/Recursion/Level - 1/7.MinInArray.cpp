#include <bits/stdc++.h>
using namespace std;


int minInArray(int *arr, int start, int n){
	if(n == start){
		return INT_MAX;
	}

	int smallOutput = minInArray(arr, start + 1, n);
	return min(smallOutput, arr[start]);
}
int main(){


	int arr[] = {1, -1, 2, 3, 4, 5,324, 45, 13, 546,1234, 354,23,71, 53};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << minInArray(arr, 0, n);


	return 0;
}
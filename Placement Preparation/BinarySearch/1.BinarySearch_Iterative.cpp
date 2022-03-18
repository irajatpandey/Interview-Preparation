#include<bits/stdc++.h>
#define long long ll
using namespace std;

int binarySearch(int arr[], int n, int target){
	int start = 0, end = n - 1;
	while(start <= end){
		int mid = start + (end - start) / 2;

		if(arr[mid] > target){
			end = mid - 1;
		}
		else if(arr[mid] < target){
			start = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
	
int main(){

	int arr[] = {12, 21, 34, 43, 54};
	int n = sizeof(arr)/sizeof(arr[0]);
	int target = 43;
	cout << binarySearch(arr, n, target);

	return 0;
}

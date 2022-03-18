#include<bits/stdc++.h>
#define long long ll
using namespace std;

int threeSum1(int *arr, int n, int target){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(arr[i] + arr[j] + arr[k] == target){
					return true;
				}
			}
		}
	}
	return false;
}

// TC O(n ^ 2)
int threeSum2(int *arr, int n, int target){
	sort(arr, arr + n);
	int left = 0, right = 0;
	for(int i = 0; i < n; i++){
		left = i + 1;
		right = n - 1;
		while(left < right){
			if(arr[left] + arr[right] + arr[i] == target){
				return true;
			}
			else if(arr[left] + arr[right] + arr[i] > target){
				right--;
			}
			else{
				left++;
			}
		}
	}
	return false;
}
int main(){

	int arr[] = {12, 3, 4, 1, 6, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 24;

	cout << threeSum1(arr, n, sum) << endl;
	cout << threeSum2(arr, n, sum) << endl;



	return 0;
}

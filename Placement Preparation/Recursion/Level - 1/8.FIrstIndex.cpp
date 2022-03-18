#include<bits/stdc++.h>
using namespace std;

int firstIndex(int *arr, int start, int n, int k){
	if(n == start){
		return -1;
	}
	
	if(arr[start] == k){
		return start;
	}
	else{
		return firstIndex(arr, start + 1, n - 1, k);
	}

	

	
}

int main(){

	int arr[] = {1, 2, 2, 3, 1, 5, 3, 5, 4};
	int n = sizeof(arr)/sizeof(arr[0]);

	int k = 2;
	cout << firstIndex(arr, 0, n-1 , k);



	return 0;
}
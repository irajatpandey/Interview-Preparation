#include<bits/stdc++.h>
using namespace std;


int lastIndex(int *arr, int start, int n, int k){

	if(start == n){
		return -1;
	}
	int index = lastIndex(arr, start + 1, n, k);

	if(arr[start] == k){
		return start;
	}

	else return index;
}


int main(){
	int arr[] = {1, 2, 3, 5, 1, 2, 43, 45, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 1;
	cout << lastIndex(arr, 0, n, k);

	return 0;
}





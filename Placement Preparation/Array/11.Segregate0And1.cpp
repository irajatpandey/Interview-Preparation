#include<bits/stdc++.h>
#define long long ll
using namespace std;

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
void partition(int *arr, int n, int pivot){
	int i = 0, j = 0;
	while(i < n){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr[i], arr[j]);
				i++;
				j++;
			
		}
	}
}


int main(){


	int arr[] = {0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1};
	 // int arr[] = { 1, 2, 0, 0, 0, 3, 6 };
	int n = sizeof(arr)/sizeof(arr[0]);
	// Pivot Element will be 0
	partition(arr, n, 0);

	printArray(arr, n);
	return 0;
}

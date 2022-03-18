#include<bits/stdc++.h>
#define long long ll
using namespace std;

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
// void partition(int *arr, int n, int pivot){
// 	int i = 0, j = 0;
// 	while(i < n){
// 		if(arr[i] > pivot){
// 			i++;
// 		}
// 		else{
// 			swap(arr[i], arr[j]);
// 				i++;
// 				j++;
			
// 		}
// 	}
// }

void partition(int *arr, int n, int pivot){
	int i = 0, j = 0;
	while(i < n){
		if(arr[i] % 2){
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

	int arr[] = {7, 9, 4, 8, 3, 6, 2, 1, 5};

	int n = sizeof(arr)/sizeof(arr[0]);
	partition(arr, n, arr[n - 1]);
	printArray(arr, n);
	return 0;
}

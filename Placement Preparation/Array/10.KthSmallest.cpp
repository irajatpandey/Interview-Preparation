#include<bits/stdc++.h>
#define long long ll
using namespace std;

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}

int partition(int *arr, int n, int pivot){
	int i = 0, j = 0;
	while(i <= n){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr[i], arr[j]);
				i++;
				j++;
			
		}
	}
	return j - 1;
}
int kthSmallest(int *arr, int low, int high, int k){
	int pivot = arr[high];
	int pivotIndex = partition(arr, high, pivot);
	
	if(pivotIndex > k){  // search at right side
		return kthSmallest(arr, low, pivotIndex - 1 , k);	
	}	
	else if(pivotIndex < k){
		return kthSmallest(arr, pivotIndex + 1, high, k); // search at left side
	}
	else{
		return arr[pivotIndex]; // when pivotIndex == k
	}

}
int main(){

	int arr[] = {7, 9, 4, 8, 3, 6, 2, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	// printArray(arr, n);

	int smallOutput = kthSmallest(arr, 0, n - 1, k - 1);
	cout << smallOutput;

	return 0;
}

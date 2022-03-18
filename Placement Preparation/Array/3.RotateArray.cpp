#include<bits/stdc++.h>
#define long long ll
using namespace std;
void display(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

//  Naive Approach 
// Time Complexity: O(n * k);
void leftShift(int *arr, int n){
	int temp = arr[0];
	for(int i = 0; i < n - 1; i++){
		arr[i] = arr[i + 1];
	}

	arr[n - 1] = temp;	
}
void rotateArray1(int *arr, int n, int k){
	for(int i = 0; i < k; i++){
		leftShift(arr, n);
	}
}


// Optimized Approach

// Reverse first k elements in the array starting from the first index.
// Reverse the next (n-k) elements left in the array.
// Reverse the whole array.
// Time Complexity: O(n);


void rotateArray2(int *arr, int n, int k){
	reverse(arr, arr + k);
	reverse(arr + k, arr + n);

	reverse(arr, arr + n);
}

int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 2;
	// rotateArray1(arr, n, k);
	rotateArray2(arr, n, k);

	display(arr, n);

	return 0;
}

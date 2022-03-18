#include<bits/stdc++.h>
#define long long ll
using namespace std;

	
int main(){

 int arr[] = { 1, 2, 0, 0, 0, 3, 6 };
 int n = sizeof(arr) / sizeof(arr[0]);

 int next = n - 1;
// If we want to shift zeroes at left side then traverse from the end of an array
 // If we want to shift zeroes at right side then traverse from the start 
 
 for(int i = n - 1; i >= 0; i--){
 	if(arr[i] != 0){
 		swap(arr[i], arr[next--]);
 	}
 }

 for(int i = 0; i < n; i++){
 	cout << arr[i] << " ";
 }

 return 0;
}

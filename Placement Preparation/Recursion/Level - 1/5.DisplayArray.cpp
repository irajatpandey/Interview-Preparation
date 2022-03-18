#include <bits/stdc++.h>
using namespace std;



void printArray(int *arr, int start, int n){

	if(n == start){
		return;
	}
	cout << arr[start] << " " ;
	printArray(arr, start + 1, n);


}
int main(){

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr)/sizeof(arr[0]);

	printArray(arr, 0, n);

	return 0;
}
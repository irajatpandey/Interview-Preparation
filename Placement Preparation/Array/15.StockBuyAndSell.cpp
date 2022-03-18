#include<bits/stdc++.h>
#define long long ll
using namespace std;

int stockBuyAndSell_1(int *arr, int n){
	int profit = INT_MIN;

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			profit = max(profit, arr[j] - arr[i]);
		}
	}

	return profit;
}

int stockBuyAndSell_2(int *arr, int n){
	int profit = INT_MIN;
	int aux[n];

	aux[n - 1] = arr[n - 1];

	for(int i = n - 2; i >= 0; i--){
		aux[i] = max(arr[i], aux[i + 1]);
	}

	for(int i = 0; i < n; i++){
		profit = max(profit, aux[i] - arr[i]);
	}

	return profit;

}

int stockBuyAndSell_3(int *arr, int n){
	int profit = INT_MIN;
	int minSoFar = INT_MAX;

	for(int i = 0; i < n; i++){
		minSoFar = min(arr[i], minSoFar);
		profit = max(profit, arr[i] - minSoFar);
	}

	return profit;
}
	
int main(){

	int arr[] = {3, 1, 5, 3, 6, 4};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << stockBuyAndSell_1(arr, n) << endl;
	cout << stockBuyAndSell_2(arr, n) << endl;
	cout << stockBuyAndSell_3(arr, n) << endl;



	return 0;
}

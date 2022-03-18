#include<bits/stdc++.h>
#define long long ll
using namespace std;


int maxProductSubArray_bruteForce(int *arr, int n){
	int ans = arr[0];
	for(int i = 0; i < n; i++){
		int product = 1;
		for(int j = i; j < n; j++){
			product = product * arr[j];
			ans = max(product, ans);
		}
	}
	return ans;

}

int maxProductSubArray_Optimized(int *arr, int n){
	int leftToRightMax = arr[0];
	int rightToLeftMax = arr[n - 1];
	int product = 1;

	for(int i = 0; i < n; i++){
		product = product * arr[i];
		leftToRightMax = max(leftToRightMax, product);
		if(product == 0){
			product = 1;
		}
	}
	product = 1;
	for(int i = n - 1; i >= 0; i--){
		product = product * arr[i];
		rightToLeftMax = max(rightToLeftMax, product);
		if(product == 0){
			product = 1;
		}
	}

	return max(leftToRightMax, rightToLeftMax);
}

int main(){
	int arr[] = {2, 3, -2, 4};
	int n = sizeof(arr) / sizeof(arr[0]);

	int ans = maxProductSubArray_bruteForce(arr, n);
	cout << ans << endl;

	return 0;
}

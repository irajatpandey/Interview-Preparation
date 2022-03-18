#include<bits/stdc++.h>
#define long long ll
using namespace std;

// TC : O(n)
// SC : O(1)
int kadanesAlgo(int *arr, int n){
	int currentBestSum = arr[0];
	int overallBestSum = arr[0];

	for(int i = 1; i < n; i++){
		if(arr[i] + currentBestSum > arr[i]){
			currentBestSum = arr[i] + currentBestSum;
		}
		else{
			currentBestSum = arr[i];
		}

		overallBestSum = max(overallBestSum, currentBestSum);
	}
	return overallBestSum;
}
int maxCircularSubArraySum(int *arr, int n) {
	int ans1 = kadanesAlgo(arr, n);
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += arr[i];
		arr[i] = arr[i] * (-1);
	}


	int ans2 = kadanesAlgo(arr, n);
	// cout << ans1 << endl;
	// cout << ans2 << endl;
	// cout << totalSum + (ans2) << endl;



	if (totalSum + (ans2) == 0) return ans1;
	return max(ans1, (totalSum + (ans2)));


}

int main() {

	// int arr[] = {2, 1, -5, 4, -3, 1, -3, 4, 1};
	int arr[] = {8, -8, 9, -9, 10, -11, 12};
	int n = sizeof(arr) / sizeof(arr[0]);


	cout << maxCircularSubArraySum(arr, n);

	return 0;
}

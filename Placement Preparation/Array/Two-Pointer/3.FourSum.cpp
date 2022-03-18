#include<bits/stdc++.h>
#define long long ll
using namespace std;

int fourSum(int *arr, int n, int target){
	unordered_map<int,pair<int,int>> mp;

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			mp[arr[i] + arr[j]] = {i, j};
		}
	}

 
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int sum = arr[i] + arr[j];

			if(mp.find(sum) != mp.end()) return true;
		}
	}

	return false;
}  
int main() {

	int arr[] = {2, 2, 2, 2, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 8;

	cout << fourSum(arr, n, target) << endl;


	return 0;
}

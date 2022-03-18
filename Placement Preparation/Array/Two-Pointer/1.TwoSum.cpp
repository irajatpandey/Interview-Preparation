#include<bits/stdc++.h>
#define long long ll
using namespace std;

bool twoSum_1(int *arr, int n, int target){
	for(int i = 0; i < n; i++){
		int x = target - arr[i];

		for(int j = i; j < n; j++){
			if(arr[i] == x){
				return true; 
			}
		}
	}
	return false;

}
bool twoSum_2(int *arr, int n, int target){
	set<int> s(arr, arr + n);

	for(int i = 0; i < n; i++){
		if(s.find(target - arr[i]) != s.end())
			return true;

	}
	return false;

	
}
bool twoSum_3(int *arr, int n, int target){
	sort(arr, arr + n);

	int i = 0, j = n - 1;
	while(j > i){
		if(arr[i] + arr[j] > target){
			j--;
		}
		else if(arr[i] + arr[j] < target){
			i++;
		}
		else if(arr[i] + arr[j] == target){
			return true;
		}
	}
	return false;
	
}
int main(){

	int arr[] = {1, 4, 45, 6, 8, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 16;
	cout << twoSum_1(arr, n , target) << endl; 
	cout << twoSum_2(arr, n , target) << endl; 
	cout << twoSum_3(arr, n , target) << endl; 


	return 0;
}

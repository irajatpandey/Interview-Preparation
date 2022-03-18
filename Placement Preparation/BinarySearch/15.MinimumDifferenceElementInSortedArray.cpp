#include<bits/stdc++.h>
#define long long ll
using namespace std;

int floor_number(vector<int> &arr, int target){
	int start = 0, end = arr.size() - 1;
	int ans = -1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] == target){
			return arr[mid];
		}

		else if(arr[mid] > target){
			end = mid - 1;
		}

		else{
			ans = arr[mid];
			start = mid + 1;
		}
	} 
	return ans;
}	
int ceil_number(vector<int> &arr, int target){
	int start = 0, end = arr.size() - 1;
	int ans = -1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] == target){
			return arr[mid];
		}

		else if(arr[mid] > target){
			ans = arr[mid];
			end = mid - 1;
		}

		else{
			start = mid + 1;
		}
	} 
	return ans;
}
int main(){

	vector<int> arr = {1, 3, 8, 10, 15};
	int target = 12;
	int ans1 = floor_number(arr, target);
	int ans2 = ceil_number(arr, target);

	cout << min(ans1, ans2);
	return 0;
}

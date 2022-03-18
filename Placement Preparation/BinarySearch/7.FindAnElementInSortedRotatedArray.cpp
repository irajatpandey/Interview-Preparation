#include<bits/stdc++.h>
#define long long ll
using namespace std;


int findAnElementInSortedRotatedArray(vector<int> &arr, int target){
	int n = arr.size();
	int start = 0, end = n - 1;

	while(start <= end){
		// To Avoid Duplicates
		while(start < end && arr[start] == arr[start+1])  start++;
        while(end > start && arr[end] == arr[end-1])  end--;


        
		int mid = start + (end - start)/2;
		if(arr[mid] == target){
			return mid;
		}
		else if(arr[mid] < arr[end]){
			if(target >= arr[mid] && target <= arr[end]){
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
		else{
			if(target >= arr[start] and target <= arr[mid]){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}
	}
	return -1;
}
int main(){
	// vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
	// int target = 5;
	vector<int> arr = {1,3};
	int target = 3;
	cout << "Index of " << target << " is " << findAnElementInSortedRotatedArray(arr, target) << endl;

	return 0;
}

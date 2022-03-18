#include<bits/stdc++.h>
#define long long ll
using namespace std;
int numberOfTimesSortedArrayIsRotated(vector<int> &arr, int n){
 int start = 0, end = n - 1;
 while(start <= end){
 	if(arr[start] <= arr[end]){
 		return start;
 	}

 	int mid = start + (end - start)/2;

 	int prev = (mid + n  - 1) % n;
 	int next = (mid + 1) % n;

 	if(arr[prev] >= arr[mid] && arr[mid] <= arr[next]){
 		return mid;
 	}
 	else if(arr[start] <= arr[mid]){
 		start = mid + 1;

 	}
 	else if(arr[mid] <= arr[end]){
 		end = mid - 1;

 	}

 }
 return -1;
}
	
int main(){
	vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
	int n = arr.size();

	cout << numberOfTimesSortedArrayIsRotated(arr, n);

	return 0;
}

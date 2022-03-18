#include<bits/stdc++.h>
#define long long ll
using namespace std;


int firstOccurrence(vector<int> arr, int target){
	int end = arr.size();
	int start = 0;
	int ans = -1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] > target){
			end = mid - 1;
		}
		else if(arr[mid] < target){
			start = mid + 1;
		}

		else{
			ans = mid;
			end = mid - 1;


		}
	}

	return ans;
}

int lastOccurrence(vector<int> arr, int target){
	int end = arr.size();
	int start = 0;
	int ans = -1;

	while(start <= end){
		int mid = start + (end - start)/2;
		if(arr[mid] > target){
			end = mid - 1;

		}

		else if(arr[mid] < target){
			start = mid + 1;

		}

		else{
			ans = mid;

			start = mid + 1;
		}
	}
	return ans;
}
	
int main(){

	vector<int> arr = {2, 4, 10, 10, 10, 18, 20};
	int n = arr.size();

	cout << firstOccurrence(arr, 10) << endl;
	cout << lastOccurrence(arr, 10) << endl;

	//  Using STL

	auto it = lower_bound(arr.begin(), arr.end(), 10);
	cout << it - arr.begin() << endl;


	auto it2 = upper_bound(arr.begin(), arr.end(), 10);
	cout << it2 - arr.begin() << endl;

	return 0;
}

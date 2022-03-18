#include<bits/stdc++.h>
#define long long ll
using namespace std;

// Time Complexity : O(logn)
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

int countOccurence(vector<int> &arr, int target){
	int first_occurence = firstOccurrence(arr, target);
	int last_occurence = lastOccurrence(arr, target);

	return last_occurence - first_occurence + 1;

}
int main(){

	vector<int> arr = {2, 4, 10, 10, 10, 18, 20};
	int n = arr.size();

	cout << countOccurence(arr, 10);
	return 0;
}

#include<bits/stdc++.h>
#define long long ll
using namespace std;

// Time Complexity : O(logn)
// Space Complexity : O(1)
int searchInNearlySortedRotatedArray(vector<int> &arr, int target){
	int end = arr.size() - 1;
	int start = 0;

	while(start <= end){
		 // find middle index `mid` and compare arr[mid-1], arr[mid], and arr[mid+1]
        // with the target number
		int mid = start + (end - start)/2;


		// return `mid` if the middle element is equal to the target number
		if(arr[mid] == target){
			return mid;
		}

		// return `mid-1` if arr[mid-1] is equal to the target number
		else if(mid - 1 >= start && arr[mid - 1] == target){
			return mid - 1;
		}

		 // return `mid+1` if arr[mid+1] is equal to the target number
		else if(mid + 1 <= end && arr[mid + 1] == target){
			return mid + 1;
		}

         // if the middle element is greater than the target number,
        // reduce search space to the right subarray nums[low…mid-2]
		else if(arr[mid] > target){
			end = mid - 2;
		}

		 // if the middle element is less than the target number,
        // reduce search space to the right subarray arr[mid+2…high]
		else{
			start = mid + 2;
		}

	}
	  // invalid input or number is not present in the array
	return -1;
}

int main(){

	vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
	int target = 40;
	cout << searchInNearlySortedRotatedArray(arr, target);
	return 0;
}

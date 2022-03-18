// nums[] = [1, 4, 6, 8, 9]
// Number: 0 to 10
// Output:
// Number 0 —> ceil is 1, floor is -1
// Number 1 —> ceil is 1, floor is 1
// Number 2 —> ceil is 4, floor is 1
// Number 3 —> ceil is 4, floor is 1
// Number 4 —> ceil is 4, floor is 4
// Number 5 —> ceil is 6, floor is 4
// Number 6 —> ceil is 6, floor is 6
// Number 7 —> ceil is 8, floor is 6
// Number 8 —> ceil is 8, floor is 8
// Number 9 —> ceil is 9, floor is 9
// Number 10 —> ceil is -1, floor is 9

#include<bits/stdc++.h>
#define long long ll
using namespace std;

void solve(){
	vector<char> arr = {'a', 'c', 'f', 'h'};
	auto it = upper_bound(arr.begin(), arr.end(), 'f');
	cout << *it << endl;
}

int ceil_number(vector<int> &nums, int target){
	int start = 0, end = nums.size() - 1;
	int ans = -1;

	if(target > nums[nums.size() - 1]){
		return -1;
	}
	
	while(start <= end){
		int mid = start + (end - start)/2;
		if(nums[mid] == target){
			return nums[mid];
		}

		else if(nums[mid] > target){
			end = mid - 1;
		}

		else{
			start = mid + 1;
		}
	} 
		return nums[start];

}

int main(){

	vector<int> nums = {1, 4, 6, 8, 9};
	for(int i = 0; i <= 10; i++)
		cout << ceil_number(nums, i) << endl;
	// }	
	cout << endl;
	solve();

	return 0;
}

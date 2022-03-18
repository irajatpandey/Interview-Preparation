#include<bits/stdc++.h>
#define long long ll
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++)
        if (nums[i] != i + 1)
            return i + 1;

    return n + 1;
}

int firstMissingPositive_usingMap(vector<int>& nums){
   // use a range constructor to initialize the set from array elements
    unordered_set<int> distinct(nums.begin(), nums.end());
 
    // return first smallest missing positive number from the set
    int index = 1;
    while (true)
    {
        if (distinct.find(index) == distinct.end()) {
            return index;
        }
        index++;
    }
    return -1;
}




int main() {

    vector<int> nums{3, 4, 7, 1};
    cout << firstMissingPositive(nums) << endl;
    cout << firstMissingPositive_usingMap(nums);

    return 0;
}
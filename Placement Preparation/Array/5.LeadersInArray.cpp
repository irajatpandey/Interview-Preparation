#include<bits/stdc++.h>
#define long long ll
using namespace std;


// Time Complexity : O(n)
// Space Complexity : O(n)

vector<int> leadersInArray(int *arr, int n){

	int currentLeader = -1;
	vector<int> ans;
	for(int i = n - 1; i >= 0; i--){
		if(arr[i] >= currentLeader){
			currentLeader = arr[i];
			ans.push_back(currentLeader);
		}

	}
	reverse(ans.begin(), ans.end());
	return ans;
}
	
int main(){

	int arr[] = {16, 17, 4, 3, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> ans = leadersInArray(arr, n);
	for(auto it : ans){
		cout << it << " "; 
	}

	return 0;
}

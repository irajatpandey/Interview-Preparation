#include<bits/stdc++.h>
#define long long ll
using namespace std;

void combinationSum2(vector<int> &arr, int startIndex, int target, vector<int> &answerSoFar,vector<vector<int>> &ans){
	if(target == 0){
		ans.push_back(answerSoFar);
		return;
	}

	for(int i = startIndex; i < arr.size(); i++){

		if(i > startIndex && arr[i] == arr[i - 1]){
			continue;
		}

		if(arr[i] > target){
			break;
		}

		answerSoFar.push_back(arr[i]);

		combinationSum2(arr, i + 1, target - arr[i], answerSoFar, ans);
		answerSoFar.pop_back();
	}



}
	
int main(){

	vector<int> arr = {10,1,2,7,6,1,5};
	int n = arr.size();
	sort(arr.begin(), arr.end());
	int target = 8;
	vector<int> answerSoFar;
	vector<vector<int>> ans;

	combinationSum2(arr, 0, target, answerSoFar, ans);

	for(auto it : ans){
		for(auto j : it){
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}

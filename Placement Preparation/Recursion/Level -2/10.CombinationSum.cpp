#include<bits/stdc++.h>
#define long long ll
using namespace std;

void combinationSum(vector<int>& arr, int target, int index, vector<vector<int>>&ans, vector<int> &answerSoFar) {
	if(index == arr.size()){
		if(target == 0){
			ans.push_back(answerSoFar);
		}
		return;
	}

	if(arr[index] <= target){
		answerSoFar.push_back(arr[index]);
		combinationSum(arr, target - arr[index], index, ans, answerSoFar);
		answerSoFar.pop_back();
	}

	combinationSum(arr, target, index + 1, ans, answerSoFar);

}



// Another Approcach we can also use

void display(vector<int> &v){
	for(auto it : v){
		cout << it << " ";
	}
	cout << endl << endl;
}
void printCombinationSum(vector<int>& arr, int target, int startIndex, vector<vector<int>> &ans, vector<int> &answerSoFar){
	if(target <= 0){

		if(target == 0){
			ans.push_back(answerSoFar);
		}
		return;
	}


	for(int i = startIndex; i < arr.size(); i++){
		answerSoFar.push_back(arr[i]);
		printCombinationSum(arr, (target - arr[i]), i, ans, answerSoFar);
		answerSoFar.pop_back();
		
	}
}
	
int main(){

	vector<int> arr = {2,3,6,7};
	int n = arr.size();

	int target = 7;
	vector<int> answerSoFar;
	vector<vector<int>> ans;

	// combinationSum(arr, target, 0, ans, answerSoFar);
	printCombinationSum(arr, target,  0, ans, answerSoFar);


	for(auto it : ans){
		for(auto j : it){
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}

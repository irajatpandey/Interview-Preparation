#include<bits/stdc++.h>
#define long long ll
using namespace std;


void coinChange2Helper(vector<int> &coins, int startIndex, int target, vector<int> &answerSoFar, vector<vector<int>> &ans){
	if(coins.size() == startIndex){

		if(target == 0){
			ans.push_back(answerSoFar);
			
		}
		return;
	}

		if(target >= coins[startIndex]){
			answerSoFar.push_back(coins[startIndex]);
			coinChange2Helper(coins, startIndex, target - coins[startIndex], answerSoFar, ans);
			answerSoFar.pop_back();

		}
		coinChange2Helper(coins, startIndex + 1, target, answerSoFar, ans);
}

vector<vector<int>> coinChange2(vector<int> &coins, int target){
	vector<vector<int>> ans;
	vector<int> answerSoFar;
	coinChange2Helper(coins, 0, target, answerSoFar, ans);
	return ans;
}
int main(){
	 vector<int> coins{5, 2, 3, 6, 7};
     int target = 12;

     vector<vector<int>> ans;
     sort(coins.begin(), coins.end());

     ans = coinChange2(coins, target);
     
     for(auto i : ans){
          for(auto j : i){
               cout << j << " ";
          }
          cout << endl;
     }

	return 0;
}

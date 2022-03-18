// 1. You are given a number n, representing the count of coins.
// 2. You are given n numbers, representing the denominations of n coins.
// 3. You are given a number "amt".
// 4. You are required to calculate and print the combinations of the n coins (non-duplicate) using 
//      which the amount "amt" can be paid.
//  coins: [5, 2, 3, 5, 6, 7]
//  target - 12
//Output : [2,3,7], [5,7]

#include<bits/stdc++.h>
#define long long ll
using namespace std;

// Time Complexity : (2 ^ n) *k
// n size of coins vector
// k average length of each combination that holds the answer 
void coinChange1Helper(vector<int> coins, int startIndex,vector<int>&answerSoFar, int target,vector<vector<int>> &ans){
     if(startIndex == coins.size()){
          if(target == 0){
               ans.push_back(answerSoFar);
          }
          return;
     }

     if(target >= coins[startIndex]){
          answerSoFar.push_back(coins[startIndex]);
          coinChange1Helper(coins, startIndex + 1, answerSoFar,target - coins[startIndex], ans);
          answerSoFar.pop_back();
          coinChange1Helper(coins, startIndex + 1, answerSoFar,target, ans);
     }

     return;


}


vector<vector<int>> coinChange1(vector<int> &coins, int target){
     vector<vector<int>> ans;
     vector<int> answerSoFar;
     coinChange1Helper(coins, 0, answerSoFar, target, ans);
     return ans;
}
     
int main(){


     vector<int> coins{5, 2, 3, 6, 7};
     int target = 12;

     vector<vector<int>> ans;

     ans = coinChange1(coins, target);
     


     for(auto i : ans){
          for(auto j : i){
               cout << j << " ";
          }
          cout << endl;
     }

     return 0;
}

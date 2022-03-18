#include<bits/stdc++.h>
#define long long ll
using namespace std;

// Time complexity : O(2^n *n)
// Space complexity : O(n * n)
// This is iterative approach to find all the subset
vector<string> printSubset_Iterative(int arr[], int n){
	 int range = pow(2, n);
	 vector<string> ans;

	 for (int i = 0; i < range; i++){
	 	string set = "";
	 	int temp = i;

	 	for(int j = n - 1; j >= 0; j--){
	 		int rem = temp % 2;
	 		temp /= 2;

	 		if(rem == 1){
	 			set = "" + set;
	 		}
	 		else{
	 			set = to_string(arr[j])+ " " + set;
	 		}
	 	}
	 	// cout << set << endl;
	 	ans.push_back(set);
	 }

	 return ans;
}


// Time complexity : O(2^n *n)
// Space complexity : O(n ^ 2)

void printAllSubset_Recursive(int *arr, int n, string output){

	if(n == 0){
		cout << output << endl;
		return;
	}
	printAllSubset_Recursive(arr, n - 1, output);
	printAllSubset_Recursive(arr, n - 1, to_string(arr[n - 1]) + output);
}
int main(){

	int arr[] = {1,2,3};
	int n = 3;

	// vector<string> ans = printSubset(arr, n);
	// cout << "Total Subset "<< ans.size() << endl;

	// sort(ans.begin(), ans.end());
	// for(auto it : ans){
	// 	cout << it << endl;
	// }


	string output = "";
	printAllSubset(arr, n, output);

	return 0;
}

#include<bits/stdc++.h>
#define long long ll
using namespace std;


// Brute Force
// Time Complexity : O(n^2)
// Space Complexity : O(1)
int majoritElement_bruteForce(vector<int> &arr){
	pair<int,int> count_max;
	for(int i = 0; i < arr.size(); i++){
		int currentCount = 0;
		for(int j = i; j < arr.size(); j++){
			if(arr[i] == arr[j]){
				currentCount++;
				if(count_max.second < currentCount){
					count_max = {arr[i], currentCount};
				}
			}
		}
	}

	if(count_max.second > arr.size()/2)
		return count_max.first;

	return INT_MIN;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
int majoritElement_HashMap(vector<int> &arr){
	unordered_map<int,int> mp;

	for(int it : arr) mp[it]++;

	for(auto it : mp){
		if(it.second > arr.size()/2)
			return it.first;
	}

	return INT_MIN;
}



// Time Complexity : O(n)
// Space Complexity : O(1)
int majoritElement_mooresVotingAlgo(vector<int> &arr){
	int n = arr.size();
	int cnt = 0;
	int val1 = arr[0];
	for(int it : arr){
		if(it == val1){
			cnt++;
		}

		else 
			cnt--;

		if(cnt == 0){
			val1 = it;
			cnt = 1;
		}

	}

	cnt = 0;

	for(int it : arr){
		if(it == val1) cnt++;
	}

	if(cnt > n/2){
		return val1;
	}
	else{
		return INT_MIN;
	}

}




	
int main(){

	vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	cout << majoritElement_bruteForce(arr) << endl;
	cout << majoritElement_HashMap(arr) << endl;
	cout << majoritElement_mooresVotingAlgo(arr) << endl;


	return 0;
}

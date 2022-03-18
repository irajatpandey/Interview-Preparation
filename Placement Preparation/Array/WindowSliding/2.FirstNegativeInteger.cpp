// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
#include<bits/stdc++.h>
#define long long ll
using namespace std;

vector<int> firstNegativeInteger(int arr[], int n, int k){
	vector<int> ans; 

	int i = 0, j = 0;
	queue<int> q;
	while(j < n){
		if(arr[j] < 0) q.push(arr[j]);
		if(j - i + 1 < k){
			j++;
		}

		else if(j - i + 1 == k){
			if(q.size() > 0)
				ans.push_back(q.front());
			else if(q.size() == 0)
				ans.push_back(0);

			if(arr[i] < 0) q.pop();
			i++; j++;
		}
	}
	return ans;

}
int main(){

	int arr[] = {-8, 2, 3, -6, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 2;

	vector<int> ans = firstNegativeInteger(arr, n, k);

	for(auto it : ans){
		cout << it << " ";
	}

	return 0;
}

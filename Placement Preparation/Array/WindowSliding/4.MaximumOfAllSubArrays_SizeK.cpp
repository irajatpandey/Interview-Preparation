#include<bits/stdc++.h>
#define long long ll
using namespace std;

vector<int> maximumOfAllSubArraysSizeK(vector<int> arr, int k ) {
	int n = arr.size();
	deque<int> d;

	int j = 0, i = 0;
	vector<int> ans;


	while(j < n){

		while(d.size() > 0 && arr[j] > d.back()){
			d.pop_back();
		}

		d.push_back(arr[j]);
		if(j - i + 1 < k) j++;

		else if(j - i + 1 == k){
			ans.push_back(d.front());

			if(arr[i] == d.front()) d.pop_front();
			i++; j++;

		}
	}
	return ans;

}


int main() {

	vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	vector<int> ans = maximumOfAllSubArraysSizeK(arr, k);

	for (auto it : ans) cout << it << " ";

	return 0;
}

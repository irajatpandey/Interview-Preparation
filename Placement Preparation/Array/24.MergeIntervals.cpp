#include<bits/stdc++.h>
#define long long ll
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &v){
	int n = v.size();

	sort(v.begin(), v.end());

	stack<pair<int,int>> st;
	st.push({v[0][0], v[0][1]});
	for(int i = 1; i < n; i++){
		pair<int,int> ele = st.top();
		if(ele.second >= v[i][0]){
			st.pop();
			ele.second = max(ele.second, v[i][1]);
			st.push(ele);
		}
		else{
			st.push({v[i][0], v[i][1]});
		}

	}
	vector<vector<int>> ans;
	while(st.size() > 0){
		// cout << st.top().first  << " " << st.top().second << endl;
		vector<int> smallOutput = {st.top().first, st.top().second};
		ans.push_back(smallOutput);
		st.pop(); 
	}


	return ans;
}

int main() {

	vector<vector<int>> v{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	// output : [[1,6],[8,10],[15,18]]
	vector<vector<int>> ans = mergeIntervals(v);
	reverse(ans.begin(), ans.end());

	for(auto it : ans){
		cout << "[ ";
		for(auto item : it){
			cout << item << " ";
		}
		cout << "]\n";
	}

	return 0;
}

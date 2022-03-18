#include<bits/stdc++.h>
#define long long ll
using namespace std;

void prefixSum(vector<int> arr, int q){
	// arr[0] = 0;
	vector<int> prefix(arr.size() + 1);
	prefix[0] = 0;
	for(int i = 1; i <= arr.size(); i++){
		prefix[i] += prefix[i - 1] + arr[i];
	}
	for(int it : prefix) cout << it << " ";
	cout << endl;
	while(q--){
		int L, R; cin >> L >> R;
		// cout << "R " << prefix[R] << endl; 
		cout << prefix[R] - prefix[L - 1] << endl;
	}
}
	
int main(){
	int n; cin >> n;
	vector<int> arr(n + 1);

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	arr[0] = 0;

	int q; cin >> q;

	// while(q--){
	// 	int L, R; cin >> L >> R;
	// 	int sum = 0;
	// 	for(int i = L; i <= R; i++){
	// 		sum += arr[i];
	// 	}
	// 	cout << sum << endl;
	// }


	prefixSum(arr, q);

	return 0;
}

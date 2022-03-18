#include<bits/stdc++.h>
#define long long ll
using namespace std;

int trappingWater(vector<int> &buildings, int n){
	vector<int> maxLeft(n);
	vector<int> maxRight(n);

	maxLeft[0] = buildings[0];
	maxRight[n - 1] = buildings[n - 1];

	for(int i = 1; i < n; i++) 
		maxLeft[i] = max(maxLeft[i - 1], buildings[i]);

	for(int i = n - 2; i >= 0; i--){
		maxRight[i] = max(maxRight[i + 1], buildings[i]);
	}

	// for(auto it : maxLeft){
	// 	cout << it << " ";
	// }
	// cout << endl;
	// for(auto it : maxRight){
	// 	cout << it << " ";
	// }
	// cout << endl;
	vector<int> water(n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		water[i] = min(maxLeft[i], maxRight[i]) - buildings[i];
		ans += water[i];
	}

	return ans;

}
int main(){

	vector<int> buildings = {3, 0, 0, 2, 0 , 4};

	int n = buildings.size();

	cout << trappingWater(buildings, n) << endl;
	return 0;
}

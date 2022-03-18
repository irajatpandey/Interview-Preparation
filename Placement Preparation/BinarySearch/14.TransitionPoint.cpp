#include<bits/stdc++.h>
#define long long ll
using namespace std;


int main() {
	vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};

	auto it = lower_bound(arr.begin(), arr.end(), 10);
	cout << it - arr.begin() << endl;

	return 0;
}

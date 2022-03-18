#include<bits/stdc++.h>
#define long long ll
using namespace std;


int main() {

	vector<int> arr = {2, 3, 5, 6, 7, 8, 10, 11, 12, 15, 20, 23, 25, 27, 30, 32, 35, 37, 49, 61};
	int start = 0;
	int end = start + 1;
	int target = 15;
	while (arr[end] != target) {
		if (arr[end] < target) {
			start = end;
			end = end * arr[end];
		}
	cout << end << endl;
		
	}
	auto it = lower_bound(arr.begin() + start, arr.begin() + end, target);
	cout << *it << endl;



	return 0;
}

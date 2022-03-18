#include<bits/stdc++.h>
#define long long ll
using namespace std;

void rearrange_array(int *arr, int n) {

	for (int i = 0; i < n; i++) {
		arr[i] += (arr[arr[i]] % n) * n;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		arr[i] /= n;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";

	}
}
int main() {
	int arr[] = {4, 0, 2, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	rearrange_array(arr, n);
	return 0;
}

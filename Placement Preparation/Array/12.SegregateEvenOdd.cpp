#include<bits/stdc++.h>
#define long long ll
using namespace std;

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
void partition(int *arr, int n) {
	int i = 0, j = 0;
	while (i < n) {
		if (arr[i] % 2) {
			i++;
		}
		else {
			swap(arr[i], arr[j]);
			i++;
			j++;

		}
	}
}


int main() {


	int arr[] = {2, 3, 12, 34, 41, 35, 47, 48, 39, 65, 321, 8, 6, 4};

	int n = sizeof(arr) / sizeof(arr[0]);
	// Pivot Element will be 0
	partition(arr, n);

	printArray(arr, n);
	return 0;
}

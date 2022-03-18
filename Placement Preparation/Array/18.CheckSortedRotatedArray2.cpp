// https://practice.geeksforgeeks.org/problems/check-if-array-is-sorted-and-rotated-clockwise-1587115620/1/?track=SPC-Arrays&batchId=140
#include<bits/stdc++.h>
#define long long ll
using namespace std;

bool isSortedRotatedArray(int *arr, int n){

 	int x = 0, y = 0;
 
    // Traversing array 0 to last element.
    // n-1 is taken as we used i+1.
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1])
            x++;
        else
            y++;
    }
    cout << x << " " << y << endl;
 
    // If till now both x,y are greater then 1 means
    // array is not sorted. If both any of x,y is zero
    // means array is not rotated.
    if (x == 1 || y == 1) {
        // Checking for last element with first.
        if (arr[n - 1] < arr[0])
            x++;
        else
            y++;
 
        // Checking for final result.
        if (x == 1 || y == 1)
            return true;
    }
 
    // If still not true then definetly false.
    return false;
}
int main() {

	int arr[] = {3, 4, 5, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	bool flag = isSortedRotatedArray(arr, n);
	if (flag) cout << "True" << endl;
	else cout << "False" << endl;

	return 0;
}

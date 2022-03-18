#include <bits/stdc++.h>
using namespace std;

int kthLargestElement(int *arr, int n, int k){
    priority_queue<int> pq;

    for(int i = 0; i < n; i++){

        pq.push(arr[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }

    return pq.top();
}
int main() {

    int arr[] = {10, 12, 34, 45, 51, 62, 71, 36};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << kthLargestElement(arr, n, 2);


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}

// Time Complexity : nlogk
vector<int> kSortedArray(int *arr, int n, int k){
    vector<int> output;
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    for(int i = 0; i < n; i++){
        pq.push(arr[i]);

        if(pq.size() > k){
            output.push_back(pq.top());
            pq.pop();
        }
    }

    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }

    return output;
}

int main() {

    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    vector<int> output = kSortedArray(arr, n, k); 

    for(auto it : output){
        cout << it << " ";
    }

    return 0;
}
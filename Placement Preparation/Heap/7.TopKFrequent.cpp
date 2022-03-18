#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}

vector<int> topKFrequent(int *arr, int n, int k){\
    vector<int> output;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    priority_queue<p, vector<p>,greater<p>> pq;

    for(auto it : mp){
        pq.push({it.second, it.first});

        if(pq.size() > k){
            pq.pop();
        }
    }
    cout << "size " << pq.size() << endl;

    while(!pq.empty()){
        output.push_back(pq.top().second);
        // cout << pq.top().first <<endl;
        pq.pop();
    }

    return output;

}

int main() {

    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    vector<int> output = topKFrequent(arr, n, k);
    for(auto it : output){
        cout << it << " ";

    }

    return 0;
}
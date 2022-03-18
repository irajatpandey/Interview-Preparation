#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}

vector<int> frequencySort(int *arr, int n){
    vector<int> output;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    priority_queue<p> pq; // max heap

    for(auto it : mp){
        pq.push({it.second, it.first});
    }


    while(pq.size() > 0){
    	 int freq = pq.top().first;
    	 int key = pq.top().second;

    	 for(int i = 1; i <= freq; i++){
    	 	output.push_back(key);
    	 }

    	 pq.pop();

    }
 

    return output;

}

int main() {

    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> output = frequencySort(arr, n);
    for(auto it : output){
        cout << it << " ";

    }

    return 0;
}
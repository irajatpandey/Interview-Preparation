#include <bits/stdc++.h>
using namespace std;
 class compare_fun {
   public:
     bool operator()(pair<int, int>p1, pair<int, int>p2) {
       if (p1.second == p2.second)
         return p1.first<p2.first;
       return p1.second>p2.second;
     }
 };
 vector<int> frequencySort(vector<int> & arr) {
   vector<int> output;
   unordered_map<int, int> mp;
   int n = arr.size();
   for (int i = 0; i<n; i++) {
     mp[arr[i]]++;
   }

   priority_queue<pair<int, int>, vector<pair<int, int >> , compare_fun> pq; // min heap

   for (auto it: mp) {
     pq.push({
       it.first,
       it.second
     });
   }

   while (pq.size()>0) {
     int freq = pq.top().first;
     int key = pq.top().second;

     for (int i = 1; i <= key; i++) {
       output.push_back(freq);
     }

     pq.pop();

   }
   // reverse(output.begin(), output.end());  

   return output;
 }

 int main(){

     vector<int> v{2, 3, 1, 3, 2}; // output 1 3 3 2 2

     vector<int> output = frequencySort(v);

     for(auto it : output) {
         cout << it << " ";
     }
     cout << endl;


     return 0;
 }
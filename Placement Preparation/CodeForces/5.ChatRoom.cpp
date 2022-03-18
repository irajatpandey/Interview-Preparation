#include <bits/stdc++.h>
using namespace std;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}

int main() {

    string check =  "hello";
    unordered_map<char, int> mp;


    string s; cin >> s;
    
    int j = 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == check[j]) {
            cnt++;
            j++;

            if(cnt == 5){
                break;
            }

        }
    }

    if(cnt == 5){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }



    return 0;
}
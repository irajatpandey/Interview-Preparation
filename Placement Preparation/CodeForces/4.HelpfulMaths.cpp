// https://codeforces.com/problemset/problem/339/A
#include <bits/stdc++.h>
using namespace std;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}

int main() {

    string str; cin >> str;

    int one = 0, two = 0, three = 0;

    for(auto it : str){
        if(it == '1') one++;
        if(it == '2') two++;
        if(it == '3') three++;
    }   

    // cout << one << " " << two << " " << three << endl;
    string ans="";
    string t1 = "1+";
    string t2 = "2+";
    string t3 = "3+";

    for(int i = 0; i < str.size(); i++){
        while(one){
            ans += t1;
            one--;
        }
        while(two){
            ans += t2;
            two--;
        }
        while(three){
            ans += t3;
            three--;
        }
    }

    ans.pop_back();
    cout << ans;

    return 0;
}
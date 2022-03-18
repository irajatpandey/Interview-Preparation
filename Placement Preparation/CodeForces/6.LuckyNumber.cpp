#include <bits/stdc++.h>
using namespace std;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}

int main() {

    int n; cin >> n;
    bool f = true;

    if(n % 4 == 0 || n % 7 == 0 || n % 47 == 0 || n % 74 == 0){
        cout << "YES";
    }
    else{
    while(n > 0){
        int rem = n % 10;
      
        if(rem != 4 && rem != 7){
            cout << "NO";
            f = false;
            break;
        }
        n /= 10;
    }
    if(f) cout << "YES";
    }


    return 0;
}
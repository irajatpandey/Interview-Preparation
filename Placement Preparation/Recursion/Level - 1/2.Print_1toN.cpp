#include <bits/stdc++.h>
using namespace std;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}


void print(int n){

    if(n == 1){
        cout << n << " ";
        return;
    }
    print(n - 1);
    cout << n << " ";
}

int main() {

    int n = 10;
    print(n);


    return 0;
}
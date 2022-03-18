#include <bits/stdc++.h>
using namespace std;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}
int power(int a, int b){

   if(b == 0) {
    return 1;
   } 
   int smallOutput = power(a, b - 1);

    return smallOutput  * a;
    
}

int main() {

    int b = 2;
    int e = 10;

    cout << power(b, e);

    return 0;
}
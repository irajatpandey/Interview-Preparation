#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    // write your code here
    if(n == 0){
        return 1;
    }
    
    int ans = powerLogarithmic(x, n/2);
    int smallOutput = ans * ans;
    if(n % 2 == 1){
        smallOutput = smallOutput * x;
    }
    return smallOutput;
    
}

int main(){
    int x,n; cin >> x >>n;
    cout << powerLogarithmic(x,n);
}
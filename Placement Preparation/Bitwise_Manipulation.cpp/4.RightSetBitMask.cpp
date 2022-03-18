#include<bits/stdc++.h>
#define long long ll
using namespace std;
void decimalToBinary(int n){
	int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
}
void RSB(int n){
	decimalToBinary(n & (-n));
}
int main(){

	RSB(76);
	return 0;
}

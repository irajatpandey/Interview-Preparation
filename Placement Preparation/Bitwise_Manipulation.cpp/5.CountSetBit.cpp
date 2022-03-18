#include<bits/stdc++.h>
#define long long ll
using namespace std;
int countBit(int n){
	int count = 0;
	while(n){
		count += n & 1;
		n = n >> 1; // Right Shift
	}
	return count;
}
int countBit_KernighanAlgo(int n){
	int count = 0;
	while(n){
		int rightSetBitMask = n & -n;
		n = n - rightSetBitMask;
		count++;
	}
	return count;
}
int main(){

	int n = 76;
	cout << countBit(n) << endl;
	cout << countBit_KernighanAlgo(n) << endl;

	return 0;
}

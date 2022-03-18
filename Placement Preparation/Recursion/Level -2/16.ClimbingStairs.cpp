// https://leetcode.com/problems/climbing-stairs/
#include<bits/stdc++.h>
#define long long ll
using namespace std;

// Brute Force
// Time Complexity O(2^n)
int climbStairs(int n){

	if(n == 0){
		return 1;
	}
	if(n < 0){
		return 0;
	}

	int answer1 = climbStairs(n - 1);
	int answer2 = climbStairs(n - 2);

	return answer1 + answer2;

}	
int main(){

	int n = 5; // output : 8
	int smallOutput = climbStairs(n);
	cout << smallOutput << endl;

	return 0;
}

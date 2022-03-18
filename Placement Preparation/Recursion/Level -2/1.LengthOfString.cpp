#include<bits/stdc++.h>
#define long long ll
using namespace std;

int length(string str, int start, int end){
	if(start == end) return 0;

	int smallOutput = length(str, start + 1, end);
	return smallOutput + 1;
}
	
int main(){
	string str = "abcd";

	cout << length(str, 0, str.size()) << endl;

	return 0;
}

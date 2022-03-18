
// Given a string and a character 'c' we have to remove all the occurence of 'c' from the given string
// Input : abccdefcd, 'c'
// Output : abdefd

#include<bits/stdc++.h>
#define long long ll
using namespace std;


void removeCharacter(string &str, char c, int start, int end){
	if(start == end){ // base condition
		return;
	}
	if(str[start] == c){
		str.erase(start, 1); // this will actually reduce the size of a string
		removeCharacter(str, c, start, end); // after deleting the char we will call the function on the updated string 
	}
	else{
	 return removeCharacter(str, c, start + 1, end); // if the character does no match just call on the next smaller Input
	

	}


}
int main(){
	string str = "1231243254231324235234143534";
	char c = '1';

	removeCharacter(str, c, 0, str.size());

	for(auto it : str){
		cout << it << " ";
	}


	return 0;
}

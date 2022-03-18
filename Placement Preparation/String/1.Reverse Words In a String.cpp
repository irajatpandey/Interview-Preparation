// https://leetcode.com/problems/reverse-words-in-a-string/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseWord(string s){
	stack<string> st;
	string result = "";
	for(int i = 0; i < s.size(); i++){
		 string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
           st.push(word);
		
	}
	
	while(st.size() > 0){
		result += st.top(); st.pop();
		if(!st.empty()) result += " ";
	}
	return result;
	
	
	
}

int main() {
	// your code goes here
	string s = "The Sky is Blue";
	
	cout << reverseWord(s);
	return 0;
}
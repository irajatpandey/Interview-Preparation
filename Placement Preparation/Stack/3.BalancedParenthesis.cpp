#include <bits/stdc++.h>
using namespace std;

bool match(char a, char b){
    return ((a == '(' and b == ')') || (a == '{' and b == '}') || (a == '[' and b == ']'));
}
bool isBalanced(string str){
    
    stack<int> s;

    for(auto it : str){
        if(it == '(' || it == '{' || it == '['){
            s.push(it);
        }
        else{
             if(s.empty()){ return false;}
             else if(match(s.top(), it) == false){ 
                 return false;
             }
             s.pop();
            }
        }
        return s.empty() == true;

    }



int main() {

	string str = "[{()}]";
	cout << isBalanced(str);
	return 0;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int minimum = INT_MAX;
stack<int> s;

void push(int ele){
    if(s.size() == 0){
        s.push(ele);
        minimum = ele;
        return; 
    }

    else{
        if(minimum < ele){
            s.push(ele);
        }
        else{
            s.push((2 * ele) - minimum);
            minimum = ele;
        }
    }
}

void pop(){

    if(s.size() == 0) return;

    if(s.top() < minimum){
        minimum = (2 * minimum) -s.top();   
    }
    
    s.pop();


}

int main() {

    push(16);
    push(9);
    // cout << minimum << endl;

    push(3);
    // cout << minimum << endl;

    push(15);
    // cout << minimum << endl;

    // pop();
    cout << minimum << endl;






    return 0;
}
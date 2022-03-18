#include <bits/stdc++.h>
using namespace std;
queue<int> q1;
queue<int> q2;

void push(int data){
    q2.push(data);
    
    while(q1.size() > 0){
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1,q2);
}

int pop(){
    if(q1.size() > 0){
        int val =  q1.front();
        q1.pop();
        return val;
    }
    return INT_MIN;
}

int top(){
    return q1.front();
}

int main() {

    push(10);
    push(20);

    push(30);

    push(40);
    cout << top() << endl;
    cout << pop() << endl;
    cout << pop() << endl;



    return 0;
}
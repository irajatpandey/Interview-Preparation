#include <bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> supportingStack;



void pushInStack(int element){
    if(s.size() == 0 and supportingStack.size() == 0){
        supportingStack.push(element);
    }

    if(supportingStack.top() > element){
        supportingStack.push(element);
    }
    s.push(element);
}

void popInStack(){

    if(s.top() == supportingStack.top()){
        s.pop();
        supportingStack.pop();
    }
    else{
        s.pop();
    }

}


int minElement(){
    if(supportingStack.size())
    return supportingStack.top();
    else
        return -1;
}
int main() {

    pushInStack(10);
    pushInStack(20);

    pushInStack(30);
    pushInStack(40);

    pushInStack(3);



    cout << minElement() << endl;

    popInStack();
    cout << minElement() << endl;
    

    return 0;
}
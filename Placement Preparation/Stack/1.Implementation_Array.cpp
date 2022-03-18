#include <bits/stdc++.h>
#define MAXSIZE 10
using namespace std;

class Stack{

    private:
        int top; // top
        int *arr;
        int capacity; 
        
    public:
    Stack(){
        top = -1;
        capacity = MAXSIZE;
        arr = new int[capacity];
    }

    bool isFull(){
        return (capacity - 1) == top;
    }
    bool isEmpty(){
        return top == -1;
    }
    void push(int data){
        if(isFull()){
            cout << "Stack is Full \n";
            return;
        }

        arr[++top] = data;

    }

    int pop(){
        if((isEmpty())){
            cout << "Stack is Empty \n";
            return INT_MIN;
        }

       int x = arr[top--];
       return x;
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack is Empty \n";
            return INT_MIN;
        }
        return arr[top];
    }

    ~Stack(){
        if(top > -1){
            delete arr;
        }
    }
   
};

int main() {

    Stack s;

    int arr[] = {1, 2, 3, 4, 5,6 };

    for(int i = 0; i < 6; i++){
        s.push(arr[i]);
    }

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.pop() << endl;

    cout << s.pop() << endl;



    return 0;
}
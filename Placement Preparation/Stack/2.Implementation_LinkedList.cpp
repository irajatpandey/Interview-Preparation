#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int data;
        Stack *next;
        Stack *head;

    public:
    Stack(){
        head = NULL;
    }

    Stack(int data){
        this -> data = data;
        next = NULL;
    }

    void push(int data){
        Stack *node = new Stack(data);
        if(!head){
            head = node;
            return;
        }
        node -> next = head;
        head = node;
        return;   
    }

    void pop(){

        if(!head) return;
        Stack *next = head;
        head = head -> next;
        delete next;
        return;
    }

    int peek(){
        if(!head) return -1;

        return head -> data;
    }
};

int main() {

    Stack s;
    s.push(10);
    s.push(20);

    s.push(30);

    cout << s.peek() << endl;
    s.pop();

    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;



    return 0;
}
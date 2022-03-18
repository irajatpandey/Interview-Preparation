#include <bits/stdc++.h>
using namespace std;
#define MAX 10
class Queue{
    private:
        int *arr;
        int front;
        int rear;
    public:
        Queue(){
            front = -1;
            rear = -1;
            arr = new int[MAX];
        }

        void push(int x){
            if(MAX - 1 == rear){
                cout << "Queue Overflow\n";
                return;
            }
            if(front == -1){
                front++;
            }
                arr[++rear] = x;
        }

        void pop(){
            if(front == -1){
                cout << "Queue Empty\n";
                return;
            }
            front++;
        }
        
        int peek(){
            if(front == -1 || front > rear){
                cout << "Queue Empty\n";
            }

            return arr[front];
        }
};

int main() {

    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;


    return 0;
}
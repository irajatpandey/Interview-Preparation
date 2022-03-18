#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
        const int roll_number;
        int age;
    public:
        Student(int r):roll_number(r){}
        void print(){
            cout << roll_number << endl;
        }
};

int main() {

    Student s1(100);
    s1.print();

    return 0;
}
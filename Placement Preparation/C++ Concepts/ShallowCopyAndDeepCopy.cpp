#include <bits/stdc++.h>
using namespace std;

class Student{
    int age;
    public:
    char *name;
        Student(int age, char *name){
            this -> age = age;
            //this -> name = name; // Shallow Copy
            this -> name = new char[strlen(name) + 1]; // deep copy
            /*Deep Copy says that make a new array and then copy the content*/
            strcpy(this -> name,name);
        }

        void diplay(){
            cout << name << " " << age << endl;
        }

};

int main() {

    char name[] = "abcd";
    Student s1(10, name);
    s1.diplay();

    name[3] = 'P';

    Student s2(20, name);
    s2.diplay();

    s1.diplay();

    return 0;
}
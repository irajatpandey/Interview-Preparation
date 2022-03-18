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

        Student(Student const &s){
            this -> age = s.age;
            this -> name = new char[strlen(s.name) + 1]; // deep copy
            strcpy(this -> name,s.name);


        }

        void diplay(){
            cout << name << " " << age << endl;
        }

};

int main() {

    char name[] = "abcd";
    Student s1(10, name);
    s1.diplay(); 


    Student s2(s1); // copy constructor (shallow copy )
    s2.name[3] = 'P';
    s1.diplay();
    s2.diplay();


    return 0;
}
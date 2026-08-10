#include <iostream>

using namespace std; 

class Student{
    string name;
    float cgpa;

    void getPercentage(){
        cout << (cgpa*10) << endl; 
    }
};

int main(){
    Student s1; // object of student class 

    cout << sizeof(s1) << endl;
    return 0;
}

// encapsulation is the concept of binding data and methods together in a single unit called class and restricting access to some of the object's components. This is a means of preventing accidental interference and misuse of the methods and data. 

// impolemented via access specifiers (public , private , protected) and getter and setter methods  
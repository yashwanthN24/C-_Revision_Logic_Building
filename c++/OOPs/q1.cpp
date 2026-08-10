#include <iostream>

using namespace std;

class Person{
    protected:
    string name;
    int age;
    public :

        Person(string name , int age){
            this->age = age;
            this->name = name;
        }


};

class Student : public Person{
    
    private :
    int StudentID;

    public :
        Student(string name , int age , int StudentID) : Person(name , age){
            this->StudentID = StudentID;
        }

        void getStudentDetails(){
            cout << "Student ID : " << StudentID << endl;   
            cout << "Student name : " << this->name << endl; // error because name is private in Person class and not accessible in Student class
            cout << "Student age : " << age << endl; // error because age is private in Person class and not accessible in Student class    
        }
};

int main(){
    Student s1("John" , 20 , 12345);
    s1.getStudentDetails();
    return 0;
}
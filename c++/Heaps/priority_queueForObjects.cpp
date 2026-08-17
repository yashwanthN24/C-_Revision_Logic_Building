#include <iostream>
#include <queue>

using namespace std;


class Student{

    public:
        string name;
        int marks;

    Student(string name , int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &s) const {
        // return this->marks < s.marks;
        // return this->marks > s.marks;
        // return this->name < s.name; 
        return this->name > s.name;
    }

    //  > means min heap 

    //  < max heap by dewfult 

};

int main(){
    priority_queue<Student> pq;

    pq.push(Student("avin" , 29));
    pq.push(Student("brown" , 89));
    pq.push(Student("charlie" , 129));

    while(!pq.empty()){
        cout << pq.top().name << " " << pq.top().marks << endl;
        pq.pop();
    }
    
}
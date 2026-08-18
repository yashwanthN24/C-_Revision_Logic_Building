#include <iostream>
#include <forward_list> // for singly linkedlist implementation


using namespace std;


void printSinglyLinkedlIst(const forward_list<int> &fl){
    forward_list<int>::const_iterator it;
    for(it = fl.begin(); it != fl.end(); ++it){
        cout << *it << " ";
    }
}

int main(){

    forward_list<int> fl;   // creates a singly linkedlist


    fl.push_front(1);

    fl.push_front(2);
    fl.push_front(3);
    fl.push_front(4);

    // while(!fl.empty()){
    //     cout << fl.front() << endl;
    //     fl.pop_front();
    // }

    printSinglyLinkedlIst(fl);  

    cout << endl;

    fl.reverse(); // reverses the singly linkedlist 

    printSinglyLinkedlIst(fl);

    // while(!fl.empty()){
    //     cout << fl.front() << endl;
    //     fl.pop_front();
    // }

}
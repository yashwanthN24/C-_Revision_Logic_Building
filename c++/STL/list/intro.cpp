#include <iostream>
#include <list> // for linkedlist implementation


using namespace std;

void printList(list<int> &ll){
   list<int>::iterator it ;
   for(it = ll.begin() ; it != ll.end() ; it++){
        cout << *it << " ";
   }
}


int main(){
    list<int> ll;   // creates a linkedlist 

    ll.push_back(1);
    ll.push_back(2);

    ll.push_front(5);

    for(int ch : ll){
        cout << ch << " ";
    }

    cout << endl;   

    printList(ll);

    cout << endl;

    cout << ll.size() << endl; // size returns the number of elements in the linkedlist

    cout << ll.front() << endl; // front returns the first element of the linkedlist (Head node)

    cout << ll.back() << endl; // back returns the last element of the linkedlist (Tail node)

    ll.pop_back(); // removes the last element of the linkedlist

    ll.pop_front(); // removes the first element of the linkedlist  

    ll.insert(ll.begin() , 10); // inserts the element 10 at the beginning of the linkedlist

    ll.insert(ll.end() , 2 , 30); // inserts the element 30 at the end of the linkedlist 2 times

    printList(ll);  
}
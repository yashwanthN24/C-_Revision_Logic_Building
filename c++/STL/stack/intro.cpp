#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << endl;
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }   
    return 0;
}

// All STL containers vectors lists and stack are passed by value so they are copy if you want orginal changes toi the actual containerpass by reference
//  Ex : vector<int> &vec 
#include <iostream>
#include <vector>

using namespace std; 

int main(){
    vector<int> v1  = { 1 , 2 , 3};

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;

    v1.push_back(6);

    cout << v1.size() << endl;
    cout << v1.capacity() << endl; // array doubling each time array grows 

    v1.pop_back();

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;

    vector<int> v2;

    cout << v2.size() << endl;
    cout << v2.capacity() << endl;

    v2.push_back(1);

    cout << v2.size() << endl;
    cout << v2.capacity() << endl;

    v2.pop_back();

    cout << v2.size() << endl;
    cout << v2.capacity() << endl;


}
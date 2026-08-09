#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << endl;
    for(int i = 0 ; i<5 ; i++){
        v.push_back(i);

        cout << v.size() << endl;
        cout << v.capacity() << endl;
    }

    cout << endl;

    cout << v.size() << endl;

    cout << v.capacity() << endl;

    //  you will observe array doublng as vector is a dynamic array 

    // so if your fixed you will store 1000000 values reserv it before

    // v.reserve(10000000000000); // This creates a capacity of 1000000000 already before hand  so that further pushback operation will be much faster as they is no copy and resizing porcess of array
}
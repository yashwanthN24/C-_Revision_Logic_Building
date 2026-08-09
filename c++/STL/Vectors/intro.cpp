#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v1;  // creates an empty vector o size 0 elements (dynamic array same as arraylist in java)
    cout << v1.size() << endl;

    vector<int> v2 = { 1 , 2 , 3 , 4 , 5}; // to intilize with specific elements list
    cout << v2.size() << endl;

    vector<int> v3(10 , -1); // constructor based creates a vector of 10 elements each intialized with value -1 

    cout << v3.size() << endl;

    for(int i =0; i<v3.size(); i++){
        cout << v3[i] << " ";
    }
    cout << endl;

    cout << v2[0] << endl;
    cout << v2.at(4) << endl;

    cout << v2.front() << endl;
    cout << v2.back() << endl;
    cout << *v2.begin() << endl; // begin is pointer to first element of vector 
    cout << *(v2.end()-1) << endl; // end is a pointer to last element of vector + 1 

    for(int ch : v2){
        cout << ch << " ";
    }

}
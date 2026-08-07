#include <iostream>

using namespace std;

int main(){

    int arr[30]; 

    cout << arr[0] << endl;
    cout << arr[20] << endl;
    cout << arr[10] << endl;
    // actually out of bound but still c/c++ lets yse  access along this is not correct java enforeces out of bouds exceptions
    cout << arr[30] << endl;

    // all these print garbave value as in c local variables unintialiezed always store some grarbasage value
}
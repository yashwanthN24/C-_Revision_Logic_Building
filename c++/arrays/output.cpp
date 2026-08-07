#include <iostream>

using namespace std;

int main(){
    int arr[] = {1 , 2 , 3 , 4 , 5};
    cout << sizeof(arr) << endl;

    int length = sizeof(arr) / sizeof(int);

    for(int i = 0; i<length ; i++){
        cout << arr[i] << " " ;
    }



}
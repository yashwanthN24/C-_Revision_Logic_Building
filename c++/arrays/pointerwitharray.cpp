#include <iostream>

using namespace std;

void printarr(int *ptr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << (*ptr++)++ << " ";
    }
    cout << endl;
}

int main(){

    int arr[] = {10 , 2 , 29 , 727 , 872 , 2 };
    int n = sizeof(arr)/sizeof(int);
    printarr(arr , n);

    for(int i = 0 ; i<n ; i++){
        cout << *(arr+i) << " ";
    }

    int *p = arr;
    int *p2 = p + 3;
    cout << endl;
    cout << p2 -p << endl;
    cout << (p == arr) << endl;
    cout << (p2 == p) << endl;
    return 0 ;
}
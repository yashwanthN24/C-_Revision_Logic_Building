#include <iostream>
#include <algorithm>

using namespace std ; 

void printarr(int *arr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << *arr++ << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = { 12 , 8 , 34 , 0 , 98 , 1};
    int n = sizeof(arr)/sizeof(int);
    printarr(arr , n);
    // sort(arr , arr+5);
    // sort(arr , arr+6);
    printarr(arr , n);

    // sort(arr , arr + 3 );
    // printarr(arr , n);
    sort(arr , arr+6 , greater<int>());
    printarr(arr , n);

    return 0;

}
#include <iostream>

using namespace std;

void printarr(int arr[]){
    int n = sizeof(arr)/sizeof(int);

    for(int i = 0 ;i<n ; i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;

}

int main(){
    int arr[] = { 1 , 2 , 4 , 5 ,6};
    printarr(arr);
}
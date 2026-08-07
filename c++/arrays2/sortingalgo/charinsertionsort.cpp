#include <iostream>

using namespace std;

void printarr(char *arr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << *arr++ << " ";
    }
    cout << endl;
}
void printarr(int  *arr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << *arr++ << " ";
    }
    cout << endl;
}

void insertionsort(char *arr , int n ){

    for(int i = 1 ; i<n ; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev] < curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main(){
    char arr[] = {'f' , 'b' , 'a' , 'e' , 'c' , 'd'};
    int n = sizeof(arr)/sizeof(char);

    printarr(arr , n );
    insertionsort(arr , n);
    printarr(arr , n);
}
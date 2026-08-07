#include <iostream>

using namespace std; 

int linearsearch(int arr[] , int n , int key){

    for(int i = 0 ; i<n ; i++){
        if(arr[i] == key){
            return i ;
        }
    }

    return -1;
}

int main(){
    int arr[] = {12 , 34 , 54 , 78 , 90};

    int key = 54;

    int res = linearsearch(arr , sizeof(arr)/sizeof(int) , key);
    if(res != -1){
        cout << key << " Found at index : " << res ;
    }else{
        cout << key << " Not found " << endl;
    }

    return 0 ;
}
#include <iostream>

using namespace std; 


int main(){

    int arr[50]; 

    cout << sizeof(arr) << endl ; // 50* 4 = 200 as 50 elements and each element is 4byte as its a n integer data type 

    int length = sizeof(arr)/sizeof(int);
    cout << length << endl;

}
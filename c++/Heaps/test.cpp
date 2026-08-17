#include <iostream>


using namespace std; 

template<typename T , size_t N>
void printArray(T (&arr)[N]){
    cout << "[" ;
    for(size_t i = 0; i<N ; i++){
        cout << arr[i];
        if(i != N-1) cout << ", ";
    }
    cout << "]\n"; 
}


int main(){
    int arr[] = {1 , 2 , 4 , 5};
    printArray(arr);
}
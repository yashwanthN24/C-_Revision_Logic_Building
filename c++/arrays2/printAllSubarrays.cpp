#include <iostream>

using namespace std;

int main(){
    int arr[] = { 1 , 45 , 56 , 67 , 89};
    int n = sizeof(arr)/sizeof(int);

    for(int start = 0 ; start < n ; start++){
        for(int end = start ; end <n ; end++){
            for(int k = start ; k<=end ; k++){
                cout << " ( " << arr[k] << " ) " << " " ;
            }
            cout << endl;
        }
    }
}
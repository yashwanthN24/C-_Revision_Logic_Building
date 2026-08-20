#include <iostream>
#include <vector>


using namespace std;

bool checkArraySortedOrNot(vector<int> &arr){
    int n = arr.size()-2;
    for(int i = 0 ; i<n ; i++){
        if(arr[i]> arr[i+1]){
            cout << " Array is not sorted " << endl;
            return false;
        }
    }

    cout << "Array is sorted " << endl;
    return true;
}

int main(){

    vector<int> arr = { 1 , 62 , 56 , 78 , 90};

    checkArraySortedOrNot(arr);
}
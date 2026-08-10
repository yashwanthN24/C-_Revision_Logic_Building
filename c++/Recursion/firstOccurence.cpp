#include <iostream>
#include <vector>

using namespace std;

int firstOccurence(vector<int> &arr , int i , int key){
    if(i == arr.size()){
        return -1;
    }

    if(arr[i] == key){
        return i;
    }
    return firstOccurence(arr , i+1 , key);
}

int main(){
    vector<int> arr = {1 , 2 , 3 , 3 , 5};

    cout << firstOccurence(arr, 0 , 13 ) << endl;
}
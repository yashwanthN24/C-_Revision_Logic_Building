#include <iostream>

#include <vector>


using namespace std;

int linearSearch(vector<int> arr , int target ){

    for(int i = 0 ; i<arr.size() ; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = { 1 , 2 , 4 , 78 , 12};

    int target = 78;

    cout << linearSearch(arr  , target);
}
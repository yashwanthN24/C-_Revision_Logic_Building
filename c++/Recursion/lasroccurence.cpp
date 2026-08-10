#include <iostream>
#include <vector>

using namespace std;

int lastOccurence(vector<int> &arr , int i , int key){
    if(i == arr.size()){
        return -1;
    }

    int isFound = lastOccurence(arr , i+1 , key);

    if(isFound == -1 && arr[i] == key){
        return i;
    }
    return isFound; 
}

int main(){
    vector<int> arr = {1 , 2 , 3 , 3 , 5, 3 , 9};
    cout << lastOccurence(arr , 0 , 3) << endl;
}
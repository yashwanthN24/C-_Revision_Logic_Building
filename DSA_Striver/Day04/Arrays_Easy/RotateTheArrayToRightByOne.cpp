#include <iostream>
#include <vector>


using namespace std;

void RotateArrayToRightByone(vector<int> &arr){

    int n = arr.size();
    int lastEle = arr[n-1];

    for(int i = n-1 ; i>=1 ; i--){
        arr[i] = arr[i-1];
    }

    arr[0] = lastEle;


}

void printArray(vector<int> arr){

    for(int num : arr){
        cout << num << " ";
    }

    cout << endl;
}

int main(){

    vector<int> arr = { 1 , 2 , 3 , 4 , 5};

    printArray(arr);

    RotateArrayToRightByone(arr);

    printArray(arr);
}
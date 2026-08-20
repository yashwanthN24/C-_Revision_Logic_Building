/*

Example 1:
Input:
 nums = [1, 2, 3, 4, 5]  
Output:
 [2, 3, 4, 5, 1]  
Explanation:
 Initially, nums = [1, 2, 3, 4, 5]  
Rotating once to the left results in nums = [2, 3, 4, 5, 1].


Example 2:
Input:
 nums = [-1, 0, 3, 6]  
Output:
 [0, 3, 6, -1]  
Explanation:
 Initially, nums = [-1, 0, 3, 6]  
Rotating once to the left results in nums = [0, 3, 6, -1].



Observation first element always goes to last index 



*/


#include <iostream>
#include <vector>

using namespace std;

void RotateArrayToLeftByOne(vector<int> &arr){

    int n = arr.size();

    int firstEle = arr[0];

    for(int i = 1 ; i<n ; i++){
        arr[i-1] = arr[i];
    }

    arr[arr.size()-1] = firstEle;

}

void printArray(vector<int> arr){
    
    for(int num:arr){
        cout << num << " " ; 
    }

    cout << endl;

}

int main(){

    vector<int> arr = { -1 , 0 , 3 , 6};

    printArray(arr);

    RotateArrayToLeftByOne(arr);
    
    printArray(arr);

}
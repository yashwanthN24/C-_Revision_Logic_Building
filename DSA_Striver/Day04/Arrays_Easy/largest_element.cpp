#include <iostream>
#include <vector>

using namespace std;

void findLargest(vector<int> arr){
    int n = arr.size() , large = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        large = max(large , arr[i]);
    }

    cout << " Largest element in this array is : " << large << endl;

}

int main(){

    vector<int> arr = { 12 , 1 , 78 , 90 , 0};

    findLargest(arr);
}
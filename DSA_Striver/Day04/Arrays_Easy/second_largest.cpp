#include <iostream>
#include <vector>

using namespace std;

void findLargestAndSecondLargestAndSmallestAndSecondSmallest(vector<int> arr){

    int n = arr.size();

    int large = INT_MIN , sec_large = INT_MIN , small = INT_MAX , second_small = INT_MAX;

    for(int i = 0 ; i<n ; i++){
        if(arr[i] > large){
            sec_large = large;
            large = arr[i];
        }else if(arr[i] > sec_large && arr[i] != large){
            sec_large = arr[i];
        }

        if(arr[i]< small){
            second_small = small;
            small = arr[i];
        }else if(arr[i] < second_small && arr[i] != small){
            second_small = arr[i];
        }


    }

    cout << " largest = " << large << endl;
    cout << " smallest = " << small << endl;
    cout << " second largest = " << sec_large << endl;
    cout << " second smallest = " << second_small << endl;

}

int main(){

    // vector<int> arr = { 12 , 78 , 15 , 84 , 91};
    vector<int> arr = { 12 , 78 , 9 , 84 , 79};

    findLargestAndSecondLargestAndSmallestAndSecondSmallest(arr);

}
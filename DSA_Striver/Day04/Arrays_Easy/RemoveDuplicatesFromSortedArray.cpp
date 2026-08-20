#include <iostream>
#include <vector>
#include <set>

using namespace std;

void removeDuplicatesFromSortedArray(vector<int> &arr){

    set<int> s;

    int i = 0;
    
    for(int num : arr){
        if(!s.contains(num)){
            s.insert(num);
            arr[i++] = num;
        }
    }; 

    // count of unique elements = index 


    // TC: O(N)
    // SC: O(N)
}


void twoPointerApproach(vector<int> &arr){
    
    if(arr.empty()) return;
    
    int i =0; //pointer to first element index tracks unique element index (since array is sorted this is always unique first element 
    
    // iterate from second element to edn of list and see if its different from first unique element if so increamen and addd its right position
    for(int j = 1 ;j<arr.size(); j++){
        if(arr[i] != arr[j]){
            i++; // for cuurrent postion of unqie element 

            arr[i] = arr[j];

        }
       
    }
}


int main(){

    vector<int> arr = { 1 , 1 ,2 , 2 , 2 , 3 };

    // for(int num : arr){
    //     cout << num << " " ;
    // }

    // removeDuplicatesFromSortedArray(arr);

    // cout << endl;

    for(int num: arr){
        cout << num << " " ;
    }

    twoPointerApproach(arr);

    cout << endl;

    for(int num: arr){
        cout << num << " ";
    }
}
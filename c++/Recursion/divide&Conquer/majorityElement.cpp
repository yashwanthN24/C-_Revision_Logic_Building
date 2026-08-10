#include <iostream>

using namespace std;

int majorityElement(int *arr , int start , int end , int *freq){
    if(start == end){
        return -1;
    }
    int curElem = arr[start];
    freq[curElem] += 1;
    int foundIdx = majorityElement(arr , start+1 , end , freq);
    
    if(foundIdx == -1 && freq[curElem] > (end/2)){
        return curElem;
    }

    return foundIdx;


}


int main(){

    // int nums[] = { 3 , 2 , 3};
    // int nums[] = { 2 , 2 , 4  , 3 , 2 , 2};
    int nums[] = { 2 , 2 , 1 , 1  ,1 , 2 , 2};

    int n = sizeof(nums)/sizeof(nums[0]);
    cout << n << endl;
    int counts[n] = {0};
    cout << majorityElement(nums , 0 , n , counts) << endl;
}


/*


Need to find the majority element in the array that is the element that appears more than n/2 times in the array.    

So keeping a count array and as you recusuve call update count once you combace whil backtracking in recursion check the counts if curr recusive calls value has n/2 counts then return that value else return the value from the recursive call

*/
#include <iostream>

using namespace std; 

int maxSubarraySum(int *arr , int n){

    int maxSubarraySum = INT_MIN;
    for(int start = 0 ; start<n ; start++){
        for(int end = start ; end<n ; end++){
            int subarraySum = 0;
            for(int k = start ; k<=end ; k++){
                subarraySum += arr[k];
                maxSubarraySum = max(maxSubarraySum , subarraySum);
            }
            cout << subarraySum << " ";
        }
        cout << endl;
    }
    cout << "Maximum subarray sum = " << maxSubarraySum  << endl;
    return maxSubarraySum;
}

int maxSubarraySum2(int *arr , int n){

    int maxSubarraySum = INT_MIN;
    for(int start = 0 ; start<n ; start++){
        int subarraySum = 0;
        for(int end = start ; end<n ; end++){
            
                subarraySum += arr[end];
                maxSubarraySum = max(maxSubarraySum , subarraySum);
        }
        // cout << endl;
    }
    cout << "Maximum subarray sum = " << maxSubarraySum  << endl;
    return maxSubarraySum;
}

int maxSubarraySum3(int *arr , int n){

    int maxSubarraySum = INT_MIN;
    int cursum = 0 ;
    for(int i = 0 ; i<n ; i++){
        cursum += arr[i];
        maxSubarraySum = max(maxSubarraySum , cursum);
        if(cursum < 0)
            cursum = 0;
    }
    cout << "Maximum subarray sum = " << maxSubarraySum  << endl;
    return maxSubarraySum;
}

int main(){

    int arr[] = {1 , 2 , 3 , 5 , 8};
    int n = sizeof(arr)/sizeof(int);
    cout << maxSubarraySum3(arr , n);

    return 0;
}
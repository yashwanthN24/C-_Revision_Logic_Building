#include <iostream>
#include <bits/stdc++.h>


using namespace std;

void heapify(int i , vector<int> &arr , int  n){

    int leftchild = 2*i+1;
    int rightChild = 2*i+2;
    int maxIdx = i;

    if(leftchild < n && arr[leftchild] > arr[maxIdx]){
        maxIdx = leftchild;
    }

    if(rightChild < n && arr[rightChild] > arr[maxIdx]){
        maxIdx = rightChild;
    }

    if(maxIdx != i){
        swap(arr[maxIdx] , arr[i]);
        heapify(maxIdx , arr , n);
    }
}

void heapsort(vector<int> &arr){
    int n = arr.size();
    // Step1 convert n/2 to 0 nodes of CBT into max heap for ascending order 
    for(int i = n/2 -1 ; i>=0 ; i--){
        heapify(i , arr , n);
    }

    for(int i = n-1; i>=1 ; i--){
        swap(arr[0] , arr[i]);
        heapify(0 , arr , i);
    }
}

 int main(){

    // Heap Sorr TC: O(nlogn) same as merge sort but still we wont use this we prefer either merge sort or quick sort only eventhough all 3 of these have same TC : O(nlogn) where n is lenegth of the array 

    // Idea of Heap sort 

    // 1) Take the given array If you want to sort it in 
        //    - Ascending order : Then build max heap out of it 
        //    - Desecning order : Then build min heap out of it 

    // Rmember a heap can be constructed from any array as Heap is a Complete Binary tree that follow the properties 
    //  for parent index i  
    // leftnode is at 2*i + 1 ith index 
    // rightnode is at 2*i + 2 th index 

    // For any CBT (heap) if n is the size of the array then n/2 to n nodes will always be leaf nodes (I.e nodes having no child nodes )

    // take n/2th index for this leftnode must be 2*n/2 + 1 ( which evalaytes to n+1) which goes out of the array size showing that always n/2 to n indexed nodes are always leaves 

    // so since we have a CBT from an Array (Heap) to make it max heap for asecding order we can call heapify for nodes n/2-1 to 0 (These nodes are non-leaf nodes fixing these makes the whole tree as max heap reursively )

    vector<int> vec = { 1 , 4 , 3  , 6 , 7};


    heapsort(vec);

    for(int i : vec){
        cout << i << " " ;
    }

    // for descending order just change heapify logic for min heap iinstead of maxheap < and > 


    // summery of heapsort 

    // 1) convert the arrya into max heap by calling heapify for root 0th index node 
        // for non-leaf node i.e n/2 to 0 nodes call heapify 

        // we get max heap from this now swpa first element with last element of heap size then keep reducing the heap sisze and repeat this proess
 }
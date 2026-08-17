#include <iostream>
// #include <vector>
#include <bits/stdc++.h>    

using namespace std;

class Heap{
    public :
    vector<int> vec;

    void push(int data){
        // pushback to the vector 

        vec.push_back(data);

        // fix heap 

        int childindex = vec.size() - 1;
        int parentIdx = (childindex - 1) / 2;

        // since its max heap in c++ parent is always greater than child so if itsopposite we keep sawpin nodes 

        while(childindex > 0 && vec[childindex] > vec[parentIdx]){
            swap(vec[childindex] , vec[parentIdx]);
            childindex = parentIdx;
            parentIdx = (childindex - 1) / 2;
        }   
    }

    void heapify(int i){

        int leftchild = 2*i+1;
        int rightChild = 2*i+2;
        int maxIdx = i;

        if(leftchild < vec.size() && vec[leftchild] > vec[maxIdx]){
            maxIdx = leftchild;
        }

        if(rightChild < vec.size() && vec[rightChild] > vec[maxIdx]){
            maxIdx = rightChild;
        }

        if(maxIdx != i){
            swap(vec[maxIdx] , vec[i]);
            // call for child nodes dix heapify
            heapify(maxIdx);
        }
        
    }

    void pop(){

        swap(vec[0] , vec[vec.size()-1]); // swap first and last node 

        // remove the last index last node 

        vec.pop_back();

        // fix heap calling heapify from root i.e 0
        heapify(0);
    }

    int top(){
        // highest element of max heap 
        return vec[0];
    }

    bool empty(){
        // return vec.size() == 0
        return vec.empty(); //both are same
    }

};

int main(){

    Heap h;

    h.push(80);
    h.push(50);
    h.push(0);
    h.push(12); 

    cout << h.top() << endl;

    h.pop(); 

    cout << h.top() << endl;

    while(!h.empty()){
        cout << h.top() << endl;
        h.pop();
    }


    cout << endl;

    Heap pq;

    pq.push(12);
    pq.push(42);
    pq.push(78);
    pq.push(1);
    pq.push(90);

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }

    // for min heap just change the condition > to < 

}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}   

void reverseKElementQ(queue<int> &q , int k){
    // cornercases
    // 1 when k > queue size  
    // 2 when k is 0 or 1 as reverseing 1 element is same as the same quue no dufference
    // is queue is empty ntg to reverse 
    if(q.empty() || k > q.size() || k <= 1){
        return ;
    }   

    // create a stack to reverse the K elements 
    stack<int> s;

    //pop &  push k element into stack  
    for(int i = 0 ; i < k ; i++){
        s.push(q.front());
        q.pop();
    }

    // push back k element pushed from the stack back to the queue 

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // push the remaining elements from the queue to the back of the queue
    int size = q.size(); 
    for(int i = 0 ; i<size - k;i++){
        q.push(q.front());
        q.pop();
    }

    
}


int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    printQueue(q);

    reverseKElementQ(q , 3);  
    
    printQueue(q);
}
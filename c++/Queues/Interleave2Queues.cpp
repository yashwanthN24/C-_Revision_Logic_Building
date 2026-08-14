#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void interleaveQueue(queue<int> q1){
    queue<int> firstHalf;
    int size = q1.size()/2;

    for(int i = 0 ; i < size ; i++){
        firstHalf.push(q1.front());
        q1.pop();
    }   

    // int n = firstHalf.size();

    // for(int i = 0 ; i<n ; i++){
    //     q1.push(firstHalf.front());
    //     firstHalf.pop();
    //     q1.push(q1.front());
    //     q1.pop();
    // }   

    while(!firstHalf.empty()){
        q1.push(firstHalf.front());
        firstHalf.pop();
        q1.push(q1.front());
        q1.pop();
    }


    // all stl containers are passed by value so changing them wont change orginalk in main 
    // so [pass by reference like queue<int> &q to actually deal with the orginalk container in main and change it] or [return the changed container and assign it to the orginal container in main does copy of the container and return it to main and assign it to the orginal container in main]
    printQueue(q1);

    cout << "After interleaving the queue: " << endl;
    cout << q1.front() << endl;  
}


int main(){
    queue<int> q1;
    for(int i = 1; i <= 10; i++){
        q1.push(i);
    }
    interleaveQueue(q1);


    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }

}
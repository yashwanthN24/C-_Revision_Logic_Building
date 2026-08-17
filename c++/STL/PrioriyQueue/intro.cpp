#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq; // provides a max heap by default max element at top when poped 

    pq.push(12);
    pq.push(4);
    pq.push(67);
    pq.push(121);

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }

    cout << endl;

    priority_queue<string> pq2;

    pq2.push("an");
    pq2.push("ball");
    pq2.push("cat");
    pq2.push("ls");

    while(!pq2.empty()){
        cout << pq2.top() << endl;
        pq2.pop();
    }   

    cout << endl;

    priority_queue<string , vector<string> , greater<string>> pq21; // for min heap we can use priority_queue<string , vector<string> , greater<string>> pq2;  this will give us the min element at the top when poped i.e smallest element will be at the top when poped

    pq21.push("an");
    pq21.push("ball");
    pq21.push("cat");
    pq21.push("ls");

    while(!pq21.empty()){
        cout << pq21.top() << endl;
        pq21.pop();
    }   



}

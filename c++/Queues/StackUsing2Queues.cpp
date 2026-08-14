#include <iostream>
#include <queue>

using namespace std;


class Stack{

    queue<int> q1;
    queue<int> q2;

    public: 

        void push(int data){
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(data);

            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }

        void pop(){
            if(q1.empty()){
                cout << "Queue is empty" << endl;
                return ;
            }
            q1.pop();
        }

        int top(){
            if(q1.empty()){
                cout << "Queue is empty" << endl;
                return -1; // or throw an exception
            }
            return q1.front();
        }

        bool isEmpty(){
            return q1.empty();
        }       

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    // cout << s.top() << endl; // Output: 30
    // s.pop();
    // cout << s.top() << endl; // Output: 20
    // s.pop();
    // cout << s.top() << endl; // Output: 10
    // s.pop();
    // cout << s.isEmpty() << endl; // Output: 1 (true)
    // return 0;

    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    }   
};
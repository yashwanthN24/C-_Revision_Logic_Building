#include <iostream>
#include <stack>

using namespace std;

class Queue{

    stack<int> s1;
    stack<int> s2;  

    public:

        void push(int data){

            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(data);  


            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }


        }


        void pop(){
            if(s1.empty()){
                cout << "Queue is empty" << endl;
                return ;
            }
            s1.pop();
        }

        int Front(){
            if(s1.empty()){
                cout << "Queue is empty" << endl;
                return -1; // or throw an exception
            }
            return s1.top();
        }

        bool isEmpty(){
            return s1.empty();
        }   

};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.isEmpty()){
        cout << q.Front() << " ";
        q.pop();
    }   
}
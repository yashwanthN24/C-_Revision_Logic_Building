#include <iostream>

using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node* next;

        Node(T data){
            this->data = data;
            this->next = NULL;
        }   
};

template <class T>
class Queue{

    Node<T>* front;
    Node<T>* rear;
    int size;

    public:
        Queue(){
            front = NULL;
            rear = NULL;
            size = 0;
        }

        void push(T data){
            Node<T>* newNode = new Node<T>(data);
            if(front == NULL){
                front = newNode;
                rear = newNode;
            }else{
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        void pop(){
            if(front == NULL){
                cout << "Queue is empty" << endl;
                return ;
            }
            Node<T>* temp = front;
            front = front->next;
            delete temp;
            size--;
        }

        T Front(){
            // if(front == NULL){
            //     cout << "Queue is empty" << endl;
            //     return -1; // or throw an exception
            // }
            return front->data;
        }

        T getRear(){
            if(rear == NULL){
                cout << "Queue is empty" << endl;
                return -1; // or throw an exception
            }
            return rear->data;
        }

        int getSize(){
            return size;
        }   

        bool isEmpty(){
            return size == 0;
        }

};

int main(){
    Queue<int> s;

    s.push(1);

    s.push(2);
    s.push(3);

    cout << s.Front() << endl;
    

    while(!s.isEmpty()){
        cout << s.Front() << endl;
        s.pop();
    }   

    Queue<string> s2;

    s2.push("Hello");
    s2.push("World");   

    cout << s2.Front() << endl;
    

    


    
}
#include <iostream>

using namespace std;

template <class T>
class CircularQueue{

    T *arr;
    int front;
    int rear;
    int capacity;
    int curSize;

    public:
        CircularQueue(int size){
            arr = new T[size];
            front = 0;
            rear = -1;
            capacity = size;
            curSize = 0;
        }

        ~CircularQueue(){
            delete[] arr;
        }

        void push(T data){
            if(curSize == capacity){
                cout << "Queue is full" << endl;
                return ;
            }
            
            rear = (rear + 1) % capacity;
            arr[rear] = data;
            curSize++;  

        }

        void pop(){
            if(curSize == 0){
                cout << "Queue is empty" << endl;
                return ;
            }

            front = (front + 1) % capacity;
            curSize--;
        }

        T Front(){
            if(curSize == 0){
                cout << "Queue is empty" << endl;
                return -1; // or throw an exception
            }
            return arr[front];
        }   


        bool isEmpty(){
            return curSize == 0;
        }   

        int getfront(){
            return front;
        }

        int getRear(){
            return rear;
        }   


};

int main(){
    CircularQueue<int> q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    q.pop();

    cout << "Front: " << q.getfront() << endl;  

    q.push(14); // Queue is full
    while(!q.isEmpty()){
        cout << q.Front() << endl;
        q.pop();
    }                   

}
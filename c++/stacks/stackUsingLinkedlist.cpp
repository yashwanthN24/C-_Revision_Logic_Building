#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    Node<T>* topNode;
    int count;

public:
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int size() {
        return count;
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);

        newNode->next = topNode;
        topNode = newNode;

        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        Node<T>* temp = topNode;
        topNode = topNode->next;

        delete temp;
        count--;
    }

    T top() {
        if (isEmpty()) {
            throw runtime_error("Stack Empty");
        }

        return topNode->data;
    }

    void display() {
        Node<T>* temp = topNode;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top = " << s.top() << endl;

    s.pop();

    s.display();

    cout << "Size = " << s.size() << endl;

    Stack<string> str;

    str.push("Hello");
    str.push("World");

    str.display();

    cout << str.top() << endl;

    return 0;
}
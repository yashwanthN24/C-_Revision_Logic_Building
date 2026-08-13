#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Stack {
private:
    list<T> data;

public:

    bool isEmpty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }

    void push(T value) {
        data.push_front(value);
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        data.pop_front();
    }

    T top() {
        if (isEmpty()) {
            throw runtime_error("Stack Empty");
        }

        return data.front();
    }

    void display() {
        for (T value : data) {
            cout << value << " ";
        }

        cout << endl;
    }
};

int main() {

    Stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.display();

    cout << s.top() << endl;

    s.pop();

    s.display();

    Stack<char> ch;

    ch.push('A');
    ch.push('B');
    ch.push('C');

    ch.display();

    return 0;
}
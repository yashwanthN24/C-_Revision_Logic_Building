#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert node at end
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Merge two sorted linked lists
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != nullptr)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Merge K sorted linked lists
Node* mergeKLists(vector<Node*>& lists) {
    if (lists.size() == 0)
        return nullptr;

    Node* result = lists[0];

    for (int i = 1; i < lists.size(); i++) {
        result = mergeTwoLists(result, lists[i]);
    }

    return result;
}

// Print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main() {

    // List 1 : 1 -> 3
    Node *l1 = nullptr, *t1 = nullptr;
    insertAtTail(l1, t1, 1);
    insertAtTail(l1, t1, 3);

    // List 2 : 6 -> 8
    Node *l2 = nullptr, *t2 = nullptr;
    insertAtTail(l2, t2, 6);
    insertAtTail(l2, t2, 8);

    // List 3 : 9 -> 10
    Node *l3 = nullptr, *t3 = nullptr;
    insertAtTail(l3, t3, 9);
    insertAtTail(l3, t3, 10);

    vector<Node*> lists = {l1, l2, l3};

    Node* ans = mergeKLists(lists);

    printList(ans);

    return 0;
}
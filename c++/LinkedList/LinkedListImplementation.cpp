#include <iostream>

using namespace std;

class Node{
    public: 
        int data;
        Node* next; 

    Node(int value){
        this->data = value ;
        this->next = nullptr;
    }
};

class LinkedList{

    public : 
       Node *head;
       Node *tail;

    LinkedList(){
        head = tail = nullptr;
    }

    ~LinkedList(){
        Node* temp = head;
        while(temp != nullptr){
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    } 

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            return ;
        }

        newNode->next = head;
        head = newNode;

    }

    void pop_front(){
        if(head == nullptr){
            return ;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            return ;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void insert(int val , int pos){
        if(pos == 0){
            push_front(val);
            return ;        
        }

        Node* newNode = new Node(val);
        int i = 0 ; Node *temp = head ; Node* prev = nullptr;
        while(temp != nullptr && i !=pos){
            prev = temp;
            temp = temp->next;
            i++;
        }

        prev->next = newNode;
        newNode->next = temp;
    }

    void pop_back(){
        if(head == nullptr){
            return ;
        }

        if(head == tail){
            delete head;
            head = tail = nullptr;
            return ;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }   

    int recursiveSearch(Node* node , int key){
        if(node == nullptr){
            return -1;
        }

        if(node->data == key){
            return 0;
        }

        int index = recursiveSearch(node->next , key);
        if(index == -1){
            return -1;
        }
        return index + 1;
    }

    int rsearch(int key){
        return recursiveSearch(head , key);
    }

    void reverse(){
        Node* prev = nullptr;
        Node* curr = head;

        while(curr != nullptr){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        tail = head;
        head = prev;
    }

    int size(){
        int count = 1;
        Node* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void remobeNthNodeFromEnd(int n){
        Node* prev = nullptr;
        Node* curr = head;

        int i = 1;
        while(i < size() - n){

            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next = curr->next;
        delete curr;
    }

    bool detectCycleLoop(){

        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }

        return false;

    } 

    // void removeCycleFromList(Node* head) or below one aso fine

    void removingCycleFromList(){
        // check if cycle exits 
        Node *slow = head;
        Node *fast = head;

        bool hasCycle = false;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                hasCycle = true;    
                break;
            }
        }     

        if(!hasCycle){
            return ;
        }   


        // find lastnode 

        slow = head; 

        // loop on Tail node back to head (special case)
        if(slow == fast){
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = nullptr;
            return ;
        }

        Node *prev = nullptr;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        // last node of the cycle should make it point to nullptr
        prev->next = nullptr;
    }

    Node* intersectionOfTwoLists(Node* head1 , Node* head2){
        Node* temp1 = head1;
        Node* temp2 = head2;

        while(temp1 != temp2){
             temp1 = temp1 == nullptr ? head2 : temp1->next;
             temp2 = temp2 == nullptr ? head1 : temp2->next;
        }

        return temp1; // anything is fine as both are same node intersectio temp2 also same 
    }

    Node* getMid(Node* head){
        
        Node* slow = head ; 
        Node* fast = head;
        Node* prev = nullptr;

        while(fast!=nullptr && fast->next !=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev !=nullptr){
            prev->next = nullptr;
        }

        return slow;
    }


    Node* merge(Node* left , Node* right){
        LinkedList* ll = new LinkedList; // bad use dummy node method

        Node* l = left; 
        Node* r = right ;

        while(l != nullptr &&  r != nullptr){
            if(l->data < r->data){
                ll->push_back(l->data);
                l = l->next;
            }else{
                ll->push_back(r->data);
                r = r->next;
            }

           
        }


         while(l != nullptr){
                ll->push_back(l->data);
                l = l->next;
            }

            while(r != nullptr){
                ll->push_back(r->data);
                r = r->next;
            }
        return ll->head;

    }

    Node* mergeSort2Linkedlist(Node* head){

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        Node* rightHalfHead = getMid(head);
        Node* left = mergeSort2Linkedlist(head);
        Node* right = mergeSort2Linkedlist(rightHalfHead);

        return merge(left , right );

    }


    Node* zigzagList(){
        // get midNode 
        Node* rightHalfHead =  getMid(head);

        // reverse right half 
        Node  *cur = rightHalfHead , *prev = nullptr , *next = nullptr;

        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        Node* reverseRightHalfHead = prev;

        // alternate merging 

        Node *leftHead = head , *rightHead = reverseRightHalfHead , *tail = rightHead;

        while(leftHead!= nullptr && rightHead != nullptr){
            Node *nextLeft = leftHead->next;
            leftHead->next = rightHead;
            Node *nextRight = rightHead->next;
            rightHead->next = nextLeft;

            tail = rightHead;

            leftHead = nextLeft;
            rightHead = nextRight;

        }

        if(rightHead != nullptr){
            tail->next = rightHead;
        }

        return head;


    }

    Node* deleteNNodesAfterMNodes(int M , int N){
        Node* temp = head;
        int i = 0 ;
        
        Node *prev = nullptr ,*temp2 = head;
        // traverse M nodes 
        while(i<M && temp2->next !=nullptr){
            prev = temp2;
            temp2 = temp2->next;
            i++;
        }

        // track how many to deletes 
        int j = 0;
        Node* t = temp2;
        while(j<N && t->next != nullptr){
            t = t->next;
            j++;
        }

        while(temp2 != t){
             Node* cur = temp2;
             temp2 = temp2->next;
             delete cur;

        }

        prev->next = t;

        return head;


    }

    Node* deleteNNodesAfterMNodesFinal(int M, int N) {

    if (head == nullptr)
        return head;

    // If M = 0, delete the entire list
    if (M == 0) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return nullptr;
    }

    Node* curr = head;

    while (curr != nullptr) {

        // Step 1: Keep M nodes
        for (int i = 1; i < M && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr)
            break;

        // Step 2: Delete next N nodes
        Node* temp = curr->next;

        for (int i = 0; i < N && temp != nullptr; i++) {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }

        // Step 3: Connect the kept part with the remaining list
        curr->next = temp;

        // Step 4: Continue from the remaining list
        curr = temp;
    }

    return head;
}

    Node* segregateEvenOdd(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *evenHead = nullptr, *evenTail = nullptr;
    Node *oddHead = nullptr, *oddTail = nullptr;

    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = nullptr;   // Detach current node

        if (curr->data % 2 == 0) {
            if (evenHead == nullptr) {
                evenHead = evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (oddHead == nullptr) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = nextNode;
    }

    if (evenHead == nullptr)
        return oddHead;

    evenTail->next = oddHead;

    return evenHead;
    }

    void printList(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }



};

int main(){
    LinkedList list;
    // list.push_back(1);
    // list.push_back(2);
    // list.push_back(3);
    // list.push_front(0);
    // list.insert(10 , 2);
    // list.insert(100 , 20);
    // list.insert(104 , 0);
    // list.insert(14 , 1);
    // list.pop_front();
    // list.printList(); // Output: 0 1 2 3 null
    // list.reverse();

    // list.printList(); // Output: 3 2 1 0 null
    // list.remobeNthNodeFromEnd(2);
    // list.printList(); // Output: 3 2 0 null 
    // cout << list.detectCycleLoop() << endl;



    // LinkedList ll;

    // ll.push_back(2);
    // ll.push_back(6);
    // ll.push_back(9);
    // ll.push_back(3);

    // LinkedList l2;

    // l2.push_back(1);
    // l2.push_back(10);
    // l2.push_back(11);
    // l2.push_back(4);

    // l2.printList();
    // cout << endl;
    // l2.head =  l2.mergeSort2Linkedlist(l2.head);
    // l2.printList();


    LinkedList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);

    ll.printList();

    ll.deleteNNodesAfterMNodesFinal(2 , 2);

    ll.printList();

    ll.head = ll.segregateEvenOdd(ll.head);

    ll.printList();

    return 0;
}

// https://chatgpt.com/c/6a7c6569-dfa4-83e8-978b-a1749649a467
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
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.insert(10 , 2);
    list.insert(100 , 20);
    list.insert(104 , 0);
    list.insert(14 , 1);
    list.pop_front();
    list.printList(); // Output: 0 1 2 3 null
    list.reverse();

    list.printList(); // Output: 3 2 1 0 null
    list.remobeNthNodeFromEnd(2);
    list.printList(); // Output: 3 2 0 null 
    cout << list.detectCycleLoop() << endl;
    return 0;
}
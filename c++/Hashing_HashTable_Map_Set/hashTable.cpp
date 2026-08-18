#include <iostream>

using namespace std;

template<class T , class V>
class Node{
    public : 
        T key;
        V value;
        Node* next;

        Node(T key , V value){
            this->key = key;
            this->value = value;
            this->next = NULL;
        }


       
};

template<class T , class V>
class HashTable{


         int hashFunction(const T& key) {
        return std::hash<T>{}(key) % totsize;
        }  

        void rehash(){ // O(n)
            int oldsize = totsize;
            totsize *= 2;
            Node<T, V> **oldtable = table;
            table = new Node<T, V>*[totsize];
            for(int i = 0 ; i < totsize ; i++){
                table[i] = NULL;
            }
            currentsize = 0;

            for(int i = 0 ; i < oldsize ; i++){
                Node<T, V>* current = oldtable[i];
                while(current != NULL){
                    insert(current->key , current->value);
                    current = current->next;
                }
            }

            //  delete old table linkedlist at eah index 
            for(int i = 0 ; i < oldsize ; i++){
                Node<T, V>* current = oldtable[i];
                while(current != NULL){
                    Node<T, V>* temp = current;
                    current = current->next;
                    delete temp;
                }
            }

            // delete entire old table array 
            delete[] oldtable;
        }   

    public :
        int totsize;
        int currentsize;
        Node<T, V> **table;

        HashTable(int size = 5){
            totsize = size;
            currentsize = 0;
            table = new Node<T, V>*[totsize];
            for(int i = 0 ; i < totsize ; i++){
                table[i] = NULL;
            }
        }

        

        ~HashTable() {
            for(int i = 0; i < totsize; i++) {
                Node<T,V>* curr = table[i];

                while(curr) {
                    Node<T,V>* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
            }

            delete[] table;
        }

        void insert(T key , V value){ // O(1)  unless rehash happens when lameda> 1so worst can O(n) because of rehash 
            int idx = hashFunction(key);
            Node<T, V>* newNode = new Node<T, V>(key, value);
            newNode->next = table[idx];
            table[idx] = newNode; // addfirst into linkedlist i.e at head of the linked list for that index
            currentsize++;

            double lambda = currentsize /(double) totsize;

            if(lambda > 1){
                rehash();
            }
        }

        void remove(T key){ // O(lameda)
            int idx = hashFunction(key);
            Node<T, V>* current = table[idx];
            Node<T, V>* prev = NULL;

            while(current != NULL){
                if(current->key == key){
                    if(prev == NULL){
                        table[idx] = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                    currentsize--;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }

        // same as count method which return 1 if key is present else 0 
        V search(T key){ // O(lameda)
            int idx = hashFunction(key);
            Node<T, V>* current = table[idx];

            while(current != NULL){
                if(current->key == key){
                    return current->value;
                }
                current = current->next;
            }
            throw std::runtime_error("Key not found");
        }

        bool exists(T key){ // O(lameda) i.e O(1) only as lamda also constant onlyt 
            int idx = hashFunction(key);
            Node<T, V>* current = table[idx];

            while(current != NULL){
                if(current->key == key){
                    return true;
                }
                current = current->next;
            }
            return false;
        }   
        
       void printHashTable() {
    for (int i = 0; i < totsize; i++) {
        cout << i << " : ";

        Node<T,V>* curr = table[i];

        while (curr != nullptr) {
            cout << "(" << curr->key << ", " << curr->value << ") -> ";
            curr = curr->next;
        }

        cout << "NULL\n";
    }
}


};

int main(){

    HashTable<string , int> ht;

    ht.insert("yash" , 23);
    ht.insert("test" , 12);
    ht.insert("guis" , 83);
    ht.insert("zuis" , 73);
    ht.insert("xuis" , 53);

    cout << ht.search("yash") << endl;
    cout << ht.search("test") << endl;
    cout << ht.search("guis") << endl;
    cout << ht.search("zuis") << endl;
    cout << ht.search("xuis") << endl;

    ht.remove("test");
    cout << "After removing test:" << endl;
    cout << "Exists test: " << ht.exists("test") << endl;
    cout << "Exists yash: " << ht.exists("yash") << endl;   


    cout << endl;

    ht.printHashTable();

    cout << endl;

    HashTable<char , int> ht2;

    ht2.insert('a' , 12);
    ht2.insert('y' , 52);
    ht2.insert('c' , 5);
    ht2.insert('w' , 15);
    ht2.insert('l' , 115);
    ht2.insert('k' , 185);
    ht2.insert('j' , 195);

    ht2.remove('a');

    ht2.printHashTable();


    
}
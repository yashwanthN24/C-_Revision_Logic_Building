#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

class Node{
    public:    
       unordered_map<char , Node*> children;
        bool endOfWord;

        Node(){
            endOfWord = false;
        } 
};

// in c++ string,.size(_) is same as string.length() as size() is avaialabel for all container in stl   
class Trie{

    public: 
       Node* root;

       Trie(){
            root = new Node();
       }

    void insert(string word){
        // O(L)

        Node* curr = root;
        for(int i = 0 ;i<word.length() ; i++){
            char ch = word[i];

            if(!curr->children.contains(ch)){
                curr->children[ch] = new Node();
            }
            curr = curr->children[ch];


            
        }
        curr->endOfWord = true;

    }

    bool search(string word){
        Node* curr = root;

        // we search character by character and level by leel in trie
        for(int i = 0 ; i<word.length() ; i++){
            char ch = word[i];

            if(!curr->children.contains(ch)){
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->endOfWord;
    }
};

int main(){
    Trie t;

    vector<string> words = {"the" , "a" , "there" , "their" , "any" , "thee"};


    for(string word : words){
        t.insert(word);
    }

    cout << t.search("their") << endl ; 

    cout << t.search("there") << endl;

    cout << t.search("any") << endl;

    cout << t.search("a") << endl;

    cout << t.search("ant") << endl;

    return 0;

}
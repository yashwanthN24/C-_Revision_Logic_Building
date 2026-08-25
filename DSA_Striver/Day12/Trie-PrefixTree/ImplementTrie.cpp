#include <bits/stdc++.h>

using namespace std;
class Trie {
    
    class Node{

        public: 
        unordered_map<char , Node*> children; 
        bool endOfWord;

        Node(){
            endOfWord = false;
        }
    };

    Node* root ;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;

        for(int i = 0 ; i<word.length() ; i++){
            char ch = word[i];
            if(!curr->children.contains(ch)){
                curr->children[ch] = new Node();
            }

            curr = curr->children[ch];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for(char ch: word){
            if(!curr->children.contains(ch)){
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char ch : prefix){
            if(!curr->children.contains(ch)){
                return false;
            }
            curr= curr->children[ch];
        }

        return true;// as we are checing prefix so we dont realluy care endof word as even the etire string can be a prefix of itself 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Node{
    public:
        unordered_map<char, Node *> children;
        bool endofword ;

        Node(){
            endofword = false;
        }
};

class Trie{
    private : 
        void printTrieHelper(Node* node, string word) {
        if (node->endofword) {
            cout << word << endl;
        }
        for (auto it : node->children) {
            printTrieHelper(it.second, word + it.first);
        }
    }
    public:
        Node *root; 

        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node *temp = root;

            for (int i = 0; i < word.length(); i++){
                char c = word.at(i);
                if(temp->children.count(c) == 0){
                    temp->children[c] = new Node();
                }
                temp = temp->children[c];
            }
            temp->endofword = true;
        }

        

        void printTrie() {
        printTrieHelper(root, "");
        }


        bool search(string name){
            Node *temp = root;

            for (int i = 0; i < name.length(); i++){
                char ch = name.at(i);
                if(temp->children.count(ch)){
                    temp = temp->children[ch];
                }else{
                    return false;
                }
            }

            return temp->endofword;
        }


};

int main(){
    Trie t;
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    for (int i = 0; i < words.size(); i++){
        t.insert(words[i]);
    }

    t.printTrie();

    cout << t.search("the") << endl;
}
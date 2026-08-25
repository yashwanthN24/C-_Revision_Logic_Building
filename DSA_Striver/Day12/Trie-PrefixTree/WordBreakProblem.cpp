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

bool helper(Trie &t , string key){
    if(key.length() == 0){
        return true; // 0 size empty string is always present in trie i.e "" Root node
    }

    for(int i = 0;i<key.length();i++){
        string first = key.substr(0 , i+1);
        string second = key.substr(i+1);

        // check if firt string exits and rest of substring exist fi so return true 
        if(t.search(first) && helper(t , second)){
            return true;
        }
    }    

    // so none of the sbstingare part of the dictioary
    return false;
}

bool workBreak(const vector<string> &dict  , string key){
    Trie t ;
    for(string str : dict){
        t.insert(str);
    }

    return helper(t , key);

}

int main(){

    vector<string> dict = {"i" , "like" , "sam" , "samsung" , "mobile" , "ice"};

    cout << workBreak(dict ,  "ilikesamsung") << endl; //1(true)
    cout << workBreak(dict ,  "ilikesung") << endl;// 0 (false)
    cout << workBreak(dict ,  "ilikesam") << endl;// 1 (true)
}

// only arrays decayse to pointer beit any array even string[] arrary but stl contains like vector are objects so the are pass by value meaning copy is made by he function if you want actuall object manupulat pass by reference using &
// Only avaialbe in c++
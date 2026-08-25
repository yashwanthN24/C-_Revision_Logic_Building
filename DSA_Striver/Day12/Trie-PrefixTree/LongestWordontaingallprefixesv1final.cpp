#include <bits/stdc++.h>

using namespace std;

class Trie {

    class Node {

    public:

        unordered_map<char, Node*> children;

        bool endOfWord;

        Node() {
            endOfWord = false;
        }
    };

    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {

        Node* curr = root;

        for(char ch : word) {

            if(curr->children.count(ch) == 0)
                curr->children[ch] = new Node();

            curr = curr->children[ch];
        }

        curr->endOfWord = true;
    }

    void findLongest(Node* curr, string current, string& longest) {

        if(current.length() > longest.length()|| (current.length() == longest.length() && current < longest)) // to store lexographically small value if there is a tie two words apple and apply in this case 
            longest = current;

        for(auto &p : curr->children) {

            char ch = p.first;

            // Only go if this prefix is also a word
            if(p.second->endOfWord)
                findLongest(p.second, current + ch, longest);
        }
    }

    string longestWord() {

        string longest = "";

        findLongest(root, "", longest);

        return longest;
    }
};

int main() {

    Trie trie;

    vector<string> words = {
        "a",
        "ap",
        "app",
        "appl",
        "apple",
        "apply",
        "banana"
    };

    for(string word : words)
        trie.insert(word);

    cout << trie.longestWord() << endl;

    return 0;
}
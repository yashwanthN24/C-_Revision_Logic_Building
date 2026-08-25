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

        // If current word is longer
        if(curr->endOfWord && current.length() > longest.length())
            longest = current;

        for(auto &p : curr->children) {

            char ch = p.first;

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
        "apple",
        "app",
        "bat",
        "banana",
        "cat"
    };

    for(string word : words)
        trie.insert(word);

    cout << trie.longestWord() << endl;

    return 0;
}
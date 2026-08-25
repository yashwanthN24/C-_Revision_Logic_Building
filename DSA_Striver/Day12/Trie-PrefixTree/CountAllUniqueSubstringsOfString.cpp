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

        for (char ch : word) {

            if (curr->children.count(ch) == 0) {
                curr->children[ch] = new Node();
            }

            curr = curr->children[ch];
        }

        curr->endOfWord = true;
    }

    int countNodes(Node* curr) {

        int count = 0;

        for (auto it : curr->children) {

            count++;

            count += countNodes(it.second);
        }

        return count ;
    }

    int countUniqueSubstrings(string s) {

        // Insert every suffix
        for (int i = 0; i < s.length(); i++) {

            string suffix = s.substr(i);

            insert(suffix);
        }

        // Every Trie node = one unique substring
        return countNodes(root)  + 1; // + 1 as we include even ""  as substring ;
    }
};

int main() {

    Trie t;

    // string s = "ababa";
    string s = "apple";

    cout << t.countUniqueSubstrings(s) << endl;

    return 0;
}
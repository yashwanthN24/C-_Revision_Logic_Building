#include <bits/stdc++.h>
using namespace std;

class Trie {

    class Node {
    public:
        unordered_map<char, Node*> children;

        bool endOfWord;
        int wordCount;
        int prefixCount;

        Node() {
            endOfWord = false;
            wordCount = 0;
            prefixCount = 0;
        }
    };

    Node* root;

public:

    Trie() {
        root = new Node();
    }

    // Insert one occurrence of word
    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {

            if (curr->children.count(ch) == 0) {
                curr->children[ch] = new Node();
            }

            curr = curr->children[ch];

            // One more word has this prefix
            curr->prefixCount++;
        }

        // Word ends here
        curr->wordCount++;
        curr->endOfWord = true;
    }

    // Search exact word
    bool search(string word) {
        Node* curr = root;

        for (char ch : word) {

            if (curr->children.count(ch) == 0) {
                return false;
            }

            curr = curr->children[ch];
        }

        return curr->endOfWord;
    }

    // Check prefix
    bool startsWith(string prefix) {
        Node* curr = root;

        for (char ch : prefix) {

            if (curr->children.count(ch) == 0) {
                return false;
            }

            curr = curr->children[ch];
        }

        return true;
    }

    // Count exact word
    int countWordsEqualTo(string word) {
        Node* curr = root;

        for (char ch : word) {

            if (curr->children.count(ch) == 0) {
                return 0;
            }

            curr = curr->children[ch];
        }

        return curr->wordCount;
    }

    // Count words starting with prefix
    int countWordsStartingWith(string prefix) {
        Node* curr = root;

        for (char ch : prefix) {

            if (curr->children.count(ch) == 0) {
                return 0;
            }

            curr = curr->children[ch];
        }

        return curr->prefixCount;
    }

    // Delete ONE occurrence of word
    void erase(string word) {
        Node* curr = root;

        // First check if word exists
        for (char ch : word) {

            if (curr->children.count(ch) == 0) {
                return;
            }

            curr = curr->children[ch];
        }

        // Word doesn't exist
        if (curr->wordCount == 0) {
            return;
        }

        // Go through word again
        curr = root;

        for (char ch : word) {

            curr = curr->children[ch];

            // One word removed from this prefix
            curr->prefixCount--;
        }

        // Remove one occurrence
        curr->wordCount--;

        // No occurrence remains
        if (curr->wordCount == 0) {
            curr->endOfWord = false;
        }
    }
};

int main() {

    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");

    cout << trie.search("apple") << endl;
    cout << trie.search("appl") << endl;

    cout << trie.startsWith("app") << endl;

    cout << trie.countWordsEqualTo("apple") << endl;
    cout << trie.countWordsEqualTo("app") << endl;

    cout << trie.countWordsStartingWith("app") << endl;

    trie.erase("apple");

    cout << trie.countWordsEqualTo("apple") << endl;
    cout << trie.countWordsStartingWith("app") << endl;

    trie.erase("apple");

    cout << trie.countWordsEqualTo("apple") << endl;
    cout << trie.search("apple") << endl;

    return 0;
}

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

    string ans;

    void solve(Node* curr, string word) {

        for(auto child : curr->children) {

            char ch = child.first;
            Node* node = child.second;

            if(node->endOfWord) {

                word.push_back(ch);

                if(word.length() > ans.length() ||
                  (word.length() == ans.length() && word < ans)) {
                    ans = word;
                }

                solve(node, word);

                word.pop_back();
            }
        }
    }

public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {

        Node* curr = root;

        for(char ch : word) {

            if(curr->children.count(ch) == 0) {
                curr->children[ch] = new Node();
            }

            curr = curr->children[ch];
        }

        curr->endOfWord = true;
    }

    string longestWord() {

        ans = "";
        solve(root, "");

        return ans;
    }
};
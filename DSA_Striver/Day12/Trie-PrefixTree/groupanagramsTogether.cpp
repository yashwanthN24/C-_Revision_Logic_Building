#include <bits/stdc++.h>
using namespace std;

class Trie {

    class Node {
    public:
        unordered_map<char, Node*> children;
        vector<string> words;

        Node() {}
    };

    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {

        string key = word;
        sort(key.begin(), key.end());

        Node* curr = root;

        for(char ch : key) {

            if(curr->children.count(ch) == 0)
                curr->children[ch] = new Node();

            curr = curr->children[ch];
        }

        curr->words.push_back(word);
    }

    void collect(Node* curr, vector<vector<string>>& ans) {

        if(curr->words.size() > 0)
            ans.push_back(curr->words);

        for(auto &p : curr->children)
            collect(p.second, ans);
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        for(string word : strs)
            insert(word);

        vector<vector<string>> ans;

        collect(root, ans);

        return ans;
    }
};

int main() {

    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    Trie trie;

    vector<vector<string>> ans = trie.groupAnagrams(strs);

    for(auto group : ans) {

        for(string word : group)
            cout << word << " ";

        cout << endl;
    }

    return 0;
}
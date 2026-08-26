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

// https://chatgpt.com/c/6a8e6123-9a60-83e9-b456-5b07e7258db6


// https://chatgpt.com/share/6a8e02d6-265c-83ee-8265-c0a3fe98a528?ogimg=plain

// https://chatgpt.com/share/6a8de7c9-72bc-83ee-b722-55fc244991b7?ogimg=plain

// https://chatgpt.com/share/6a8de7c9-72bc-83ee-b722-55fc244991b7?ogimg=plain

// https://chatgpt.com/share/6a8d8a57-a570-83ee-81af-129260ed5272?ogimg=plain

// https://chatgpt.com/share/6a8d8a57-a570-83ee-81af-129260ed5272?ogimg=plain

// https://chatgpt.com/share/6a8d6ada-f364-83e8-991e-3a39acffaf4d?ogimg=plain

// https://chatgpt.com/share/6a8caa1b-06f8-83ee-be16-b275ca74e97e?ogimg=plain

// https://chatgpt.com/share/6a8caa1b-06f8-83ee-be16-b275ca74e97e?ogimg=plain

// https://chatgpt.com/share/6a8ca99a-6658-83e8-9f3b-774a9c33e24f?ogimg=plain

// https://chatgpt.com/share/6a8c9df5-b944-83e8-86e4-13e2c170193d?ogimg=plain


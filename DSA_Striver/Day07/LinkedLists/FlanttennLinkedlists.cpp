#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = nullptr;
        child = nullptr;
    }
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
        child = nullptr;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};

class Solution {
public:

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* flattenLinkedList(ListNode* &head) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        ListNode* temp = head;

        // Put all head nodes into heap
        while (temp != nullptr) {
            pq.push(temp);
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (!pq.empty()) {

            ListNode* node = pq.top();
            pq.pop();

            curr->child = node;
            curr = node;

            if (node->child != nullptr) {
                pq.push(node->child);
            }
        }

        curr->child = nullptr;

        return dummy->child;
    }
};
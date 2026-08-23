
  struct ListNode {
    int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // roate right by k places means 

      
        if (head == nullptr || head->next == nullptr)
            return head;

        // find length
        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        k = k % n;

        if (k == 0)
            return head;

        // reverse whole list
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* newHead = prev;

        // reverse first k nodes
        curr = newHead;
        prev = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            count++;

            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* firstHead = prev;
        ListNode* firstTail = newHead;

        // reverse remaining nodes
        prev = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // connect
        firstTail->next = prev;

        return firstHead;
    }
};
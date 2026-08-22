struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



class Solution {
public:
    ListNode* getMid(ListNode* head){
        ListNode* slow = head , *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {

        ListNode* midNode    = getMid(head);

        // reverse right half
        ListNode* curr = midNode , *prev = nullptr ;

        while(curr!=nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* rightHead = prev;
        ListNode* left = head;

        while(rightHead != nullptr){
            if(rightHead->val != left->val){
                return false;
            }
            left = left->next;
            rightHead = rightHead->next;
        }

        return true;
       
    }
};
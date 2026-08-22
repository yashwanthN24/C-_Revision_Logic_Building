
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {

        if(head == nullptr) return 0;

        ListNode* slow = head , *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                int count =1;
                
                ListNode* temp = slow; 

                // ount unitl we meet he same node again 
                while(temp->next != slow){
                    count++;
                    temp = temp->next;
                }

                return count;
            }
        }

        return 0;
    }
};
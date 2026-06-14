/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head-> next){
            return 0;
        }
        ListNode*slow = head,*fast =head->next;

        while(fast&&fast->next&&slow!=fast){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(slow==fast){
            return 1;
        }
        return 0;
    }
};
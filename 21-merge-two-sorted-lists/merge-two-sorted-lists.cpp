/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode*Head= new ListNode(0);
        ListNode*Tail=Head;
        while(head1&&head2){
        if(head1->val<head2->val){
            Tail->next=head1;
            head1=head1->next;
            Tail=Tail->next;
            Tail->next =NULL;
        }
        else{
            Tail->next=head2;
            head2=head2->next;
           Tail= Tail->next;
           Tail->next=NULL;
        }
        }

        if(!head1) {
            Tail->next =head2;
            
        }
        else{
            Tail->next =head1;
        }
        ListNode*Temp =Head;
        Head=Head->next;
        delete Temp;
        return Head;
    }
};
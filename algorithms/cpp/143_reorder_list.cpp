/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* fast=head, *slow=head;
        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
            
        slow->next=reverseList(slow->next);
        fast=slow;
        slow=slow->next;
        fast->next=NULL;
        while(head && slow) {
            fast=head->next;
            head->next=slow;
            slow=slow->next;
            head->next->next=fast;
            head=fast;
        }
        
        }
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre=NULL, *pos=NULL;
        while(head) {
            pos=head->next;
            head->next=pre;
            pre=head;
            head=pos;
        }
        return pre;
        }
};

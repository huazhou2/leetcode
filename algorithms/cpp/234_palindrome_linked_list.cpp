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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        int count=1;
        ListNode* slow=head, *fast=head;
        while (fast->next && fast->next->next) { 
        fast=fast->next->next;
        slow=slow->next;}
        fast=slow->next;
        slow->next=NULL;
        ListNode * head2=reverselist(fast);
        while (head2) {
            if (head->val!=head2->val) return false;
            else 
            {head=head->next;
            head2=head2->next;}
        }
        return true;
        }
        
    ListNode* reverselist(ListNode* head) {
        ListNode* pre=NULL, *next=NULL;
        while(head) {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }

};

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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode* fast=head, *slow=head;
        while(fast->next && fast->next->next ) {
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow) break;}
            if (!fast->next || !fast->next->next) return NULL;
        ListNode * target=head;
        do {slow=slow->next;target=target->next;} while(slow!=fast);
        fast=head;
        while(fast!=target) {
            fast=fast->next;
            target=target->next;}
            return target;
    }
};

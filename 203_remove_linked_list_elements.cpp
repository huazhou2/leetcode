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
    ListNode* removeElements(ListNode* head, int val) {

        if (!head) return NULL;
        while(head->val==val) {
            if (!head->next) return NULL;
            else
            head=head->next;}
        ListNode* current=head->next;
        ListNode* prev=head;
        while(current) {
            if (current->val == val) 
                prev->next=current->next;
                
            else 
                prev=current;
                current=current->next;
        }
        return head;
                
        }
};

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
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next)  return head;
        ListNode* current=head->next;
        ListNode* temp;
        head->next=NULL;
        while(current) {
            temp=current->next;
            current->next=head;
            head=current;
            current=temp;
            
        }
        return head;
        }
};

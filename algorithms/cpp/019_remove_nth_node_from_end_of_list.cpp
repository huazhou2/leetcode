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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *slow=head;
        for (int i=0;i<n;i++) 
            fast=fast->next;
        if (!fast) return head->next;
            while (fast && (fast=fast->next)) {
                slow=slow->next;}
            ListNode* temp=slow->next;
            if (!temp) return NULL;
            slow->next=temp->next;
            delete temp;
            return head;
}
};

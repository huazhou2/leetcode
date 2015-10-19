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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* cur=head;
        int length=1;
        while (cur->next) {
            length++;
            cur=cur->next;}
        k=k%length;
        ListNode* tail=cur;
        cur=head;
        if (k==0) return head;
        int count=0;
        while (count<length-k-1) {
            cur=cur->next;
            count++;}
        tail->next=head;
        tail=cur->next;
        cur->next=NULL;
        return tail;
        }
};

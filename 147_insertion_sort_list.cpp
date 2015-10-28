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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur=head->next;
        while (cur) {
            ListNode* temp=head;
            while (temp!=cur) {
                if (temp->val<=cur->val)  temp=temp->next;
                else {
                    swap(temp,cur);temp=temp->next;}
            }
            cur=cur->next;
        }
        return head;
    }
    void swap(ListNode* node1, ListNode* node2) {
            int temp=node2->val;
            node2->val=node1->val;
            node1->val=temp;
    }
            
};

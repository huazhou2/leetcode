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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* rhead=head->next;
        ListNode* prev=new ListNode(-1), *post=head->next;
        prev->next=head;
        while(prev->next && post) { 
            ListNode* temp=post->next;
            ListNode* cur=prev->next;
            post->next=cur;
            prev->next=post;
            cur->next=temp;
            prev=cur;
            if (prev->next) post=temp->next;
        }
        return rhead;
    }
};

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        priority_queue<ListNode*,vector<ListNode*>, cmp> que;
        for (int i=0;i<lists.size();i++)
            if (lists[i]) que.push(lists[i]);
        ListNode* newhead=new ListNode(-1);
        ListNode* cur=newhead;
        while (!que.empty()) {
            cur->next=que.top();
            cur=cur->next;
            que.pop();
            if (cur->next) que.push(cur->next);
        }
        cur=newhead;
        newhead=newhead->next;
        delete cur;
        return newhead;}
private:
       
        struct cmp {
            bool operator () (const ListNode* a, const ListNode* b)  {
                return a->val>=b->val;
            }
        };
};

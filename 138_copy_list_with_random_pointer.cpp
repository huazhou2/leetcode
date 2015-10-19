/**
 *  * Definition for singly-linked list with a random pointer.
 *   * struct RandomListNode {
 *    *     int label;
 *     *     RandomListNode *next, *random;
 *      *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 *       * };
 *        */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode* newhead=new RandomListNode(head->label);
        RandomListNode* cur=head,*newcur=newhead;
        unordered_map<RandomListNode*, RandomListNode*> map;
        map[head]=newhead;
        while (cur->next) {
            newcur->next=new RandomListNode(cur->next->label);
            cur=cur->next;
            newcur=newcur->next;
            map[cur]=newcur;
        }
        cur=head;
        newcur=newhead;
        while (cur) {
            newcur->random=map[cur->random];
            cur=cur->next;
            newcur=newcur->next;
        }
        return newhead;
    }
};

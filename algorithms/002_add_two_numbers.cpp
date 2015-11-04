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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//boarder case
        if (!l1) return l2;
        else if (!l2) return l1;
        int carry=0;
	//create new dummy head
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        while (l1 || l2 || carry) {//need to check if carry there
            int temp=carry;
            if (l1) {
                temp+=l1->val;
                l1=l1->next;}
            if (l2) {
                temp+=l2->val;
                l2=l2->next;}
            cur->next=new ListNode(temp%10);
            cur=cur->next;
            carry=temp/10;
        }
        return dummy->next;
        }
};

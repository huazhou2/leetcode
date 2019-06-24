/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode * fast=head;
        int count=0;
        while (fast) { count++;fast=fast->next;}
        return buildTree(head,0,count-1);
    }
    TreeNode* buildTree(ListNode *& list,int start, int end) {
        if (start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode* leftchild=buildTree(list,start,mid-1);
        TreeNode* parent=new TreeNode(list->val);
        parent->left=leftchild;
        list=list->next;
        parent->right=buildTree(list,mid+1,end);
        return parent;
    }
};

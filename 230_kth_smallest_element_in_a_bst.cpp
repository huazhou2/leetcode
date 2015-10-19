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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        int result;
        int count=0;
        dfs(root,k,count,result);
        return result;
    }
    void dfs(TreeNode* root, int k, int &count, int &value) {
        if (!root) return;
        dfs(root->left,k,count,value);
        count++;
        if (count==k) {value=root->val;return;}
        dfs(root->right,k,count,value);
    }
};

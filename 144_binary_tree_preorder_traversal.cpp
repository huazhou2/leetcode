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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root,result);
        return result;
    }

    void preorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        nums.push_back(root->val);
        preorder(root->left,nums);
        preorder(root->right,nums);
    }
};

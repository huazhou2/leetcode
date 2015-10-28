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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return (isMirror(root->left,root->right));
    }
    bool isMirror(TreeNode* lhs, TreeNode* rhs) {
        if (!lhs && ! rhs ) return true;
        else if (lhs && rhs) return (lhs->val==rhs->val && isMirror(lhs->left,rhs->right) && isMirror(lhs->right,rhs->left));
        else return false;
    }
};

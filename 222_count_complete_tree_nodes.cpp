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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* left=root, *right=root;
        int height=1;
        while(left->left) {
            left=left->left;
            right=right->right;
            height++;}
        if (right) return pow(2,height)-1;
        else return (1+countNodes(root->left)+countNodes(root->right));
    }
};

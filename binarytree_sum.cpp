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
    int sumNumbers(TreeNode* root) {
        int result;
        dfs(root, result,0);
        return result;
    }
    void dfs(TreeNode* root, int& result, int path) {
        if (!root) return;
        path=path*10+root->val;
        if (!root->left && !root->right)  {
            result+=path;
            return;}
        dfs(root->left, result,path);
        dfs(root->right,result,path);
        path=(path-root->val)/10;
    }
};

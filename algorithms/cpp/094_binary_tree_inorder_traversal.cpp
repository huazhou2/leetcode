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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root,result);
        return result;
    }
    void dfs(TreeNode* root, vector<int>& path) {
        if (!root) return;
        dfs(root->left,path);
        path.push_back(root->val);
        dfs(root->right,path);
    }
};

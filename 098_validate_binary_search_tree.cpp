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
    bool isValidBST(TreeNode* root) {
    vector<int> path;
    dfs(root, path);
    for (int i=1;i<path.size();i++) 
        if (path[i]<=path[i-1]) return false; 
    return true;
    }
    void dfs(TreeNode* root, vector<int>& path) {
        if (!root) return;
        dfs(root->left,path);
        path.push_back(root->val);
        dfs(root->right,path);
    }
};

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if (!root) return result;
        vector<int> path;
        dfs(root,sum,path,result,0);
        return result;
    }
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int> > & result, int total) {
        total+=root->val;
        path.push_back(root->val);
        if (!root->left && !root->right) 
            {
            if (total==sum) result.push_back(path);
           total-=root->val;
            path.erase(path.end()-1);
            return; }
        else {
            if (root->left)  dfs(root->left,sum,path,result,total);
            if (root->right) dfs(root->right,sum, path, result,total);
        }
        total-=root->val;
        path.erase(path.end()-1);
	}
};


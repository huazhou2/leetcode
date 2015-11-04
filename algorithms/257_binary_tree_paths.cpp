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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int> > result;
        vector<int> temp;
        dfsTree(root, result, temp);
        vector<string> final;
        if (!root) return final;
        for (int i=0;i<result.size();i++) {
            string temp("");
                for (int j=0;j<result[i].size();j++) 
                    j==0?temp+=to_string(result[i][j]):temp+=("->"+to_string(result[i][j]));
            final.push_back(temp);
            }
        return final;
        }
    void dfsTree(TreeNode* root, vector<vector<int> >& result, vector<int>& temp) {
        if (!root) return;
        temp.push_back(root->val);
        if (root->left || root->right) {
            if (root->left) 
            dfsTree(root->left,result,temp);
            if (root->right) 
            dfsTree(root->right,result,temp);
        temp.pop_back();
        }
    
        else {result.push_back(temp);temp.pop_back();return;}
        
        }
};

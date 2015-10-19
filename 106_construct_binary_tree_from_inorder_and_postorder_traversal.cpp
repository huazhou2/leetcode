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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return NULL;
        return dfs(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int s1, int e1,int s2,int e2) {
        if (s1>e1) return NULL;
        TreeNode* root=new TreeNode(postorder[e2]);
        int index=s1;
        for (;index<=e1;index++)
            if (inorder[index]==postorder[e2]) break;
        root->left=dfs(inorder,postorder,s1,index-1,s2,s2+index-1-s1);
        root->right=dfs(inorder,postorder,index+1,e1,s2+index-s1,e2-1);
        return root;
    }
};

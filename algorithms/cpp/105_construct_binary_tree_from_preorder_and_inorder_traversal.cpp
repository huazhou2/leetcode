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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.empty()) return NULL;
            return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2) {
        TreeNode* root=new TreeNode(preorder[s1]);
        if (s1>e1) return NULL;
        int index;
        for (int i=s2;i<=e2;i++) {
            if (inorder[i]==preorder[s1]) {
                index=i;
                break;}
        }
        root->left=dfs(preorder,inorder, s1+1,index-s2+s1, s2, index-1);
        root->right=dfs(preorder,inorder, index-s2+s1+1,e1, index+1, e2);
        return root;
    }
};

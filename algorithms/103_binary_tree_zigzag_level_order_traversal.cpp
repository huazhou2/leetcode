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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        int count=0;
        while (!que.empty()) {
            int siz=que.size();
            count=(count+1)%2;
            vector<int> level(siz,0);
            if (count) {
                for (int i=0;i<siz;i++) {  
                    TreeNode * temp=que.front();
                    level[i]=temp->val;
                    if (temp->left) que.push(temp->left);
                    if (temp->right) que.push(temp->right);
                    que.pop();
                    }
                }
            else {
                for (int i=0;i<siz;i++) {
                    TreeNode* temp=que.front();
                    level[siz-i-1]=temp->val;
                    if (temp->left) que.push(temp->left);
                    if (temp->right) que.push(temp->right);
                    que.pop();
                }
                }
                result.push_back(level);
                }
        return result;
    }
};

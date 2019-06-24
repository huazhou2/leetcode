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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        deque<TreeNode*> que;
        que.push_back(root);
        while(!que.empty()) {
            int size=que.size();
            for (int i=0;i<size;i++) {
                TreeNode* temp=que.front();
                if (i==size-1) result.push_back(temp->val);
                if (temp->left) que.push_back(temp->left);
                if (temp->right) que.push_back(temp->right);
                que.pop_front();
            }
        }
        return result;
    }
};

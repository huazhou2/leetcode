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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result = {};
        if (root==NULL) return result;
        vector<int> row;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            int size=queue.size();
            for (int i=0;i<size;i++) {
            row.push_back(queue.front()->val);
            if (queue.front()->left) queue.push_back(queue.front()->left);
            if (queue.front()->right) queue.push_back(queue.front()->right);
            queue.pop_front();
            }
            result.push_back(row);
            row.clear();
        }
            
        return result;   
    }
};

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) return result;
        deque<TreeNode*> queue;
        queue.push_back(root);
        stack<vector<int> > temp_result;
        vector<int> row;
        while (!queue.empty()) {
            int size=queue.size();
            for (int i=0;i<size;i++) {
                row.push_back(queue.front()->val);
                if (queue.front()->left) queue.push_back(queue.front()->left);
                if (queue.front()->right) queue.push_back(queue.front()->right);
                queue.pop_front();
            }
            temp_result.push(row);
            row.clear();
            }
        while(!temp_result.empty()) {
            result.push_back(temp_result.top());
            temp_result.pop();
        }
        return result;
        }
};

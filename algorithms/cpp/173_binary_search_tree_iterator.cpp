/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) { 
        start=root;
        treeTraverse(root,data);
        index=0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (index<data.size()) return true;
        else return false;
    }

    /** @return the next smallest number */
    int next() {
        if (hasNext()) return data[index++];
        else return 0;
    }
    void treeTraverse(TreeNode* root, vector<int>& result) {
        if (!root) return;
        else 
        {   treeTraverse(root->left,result);
            result.push_back(root->val);
            treeTraverse(root->right,result);
        }
    }
private:
    TreeNode* start;
    vector<int> data;
    int index;
};

/**
 *  * Your BSTIterator will be called like this:
 *   * BSTIterator i = BSTIterator(root);
 *    * while (i.hasNext()) cout << i.next();
 *     */

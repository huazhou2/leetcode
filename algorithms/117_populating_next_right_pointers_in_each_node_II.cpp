/**
 *  * Definition for binary tree with next pointer.
 *   * struct TreeLinkNode {
 *    *  int val;
 *     *  TreeLinkNode *left, *right, *next;
 *      *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 *       * };
 *        */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
                TreeLinkNode* cur=root->next;
                while (cur) {
                    if (cur->left)  {
                        if (root->right) root->right->next=cur->left;
                        else root->left->next=cur->left;
                        break;
                    }
                    else if (cur->right) {
                        if (root->right) root->right->next=cur->right;
                        else root->left->next=cur->right;
                        break;
                    }
                    else cur=cur->next;
                    }
            if (root->right)
                {root->left->next=root->right;
                connect(root->right);}
            connect(root->left);}
        else if (root->right) {
            TreeLinkNode* cur=root->next;
            while (cur) {
                if (cur->left)  {
                    root->right->next=cur->left;
                    break;
                    }
                else if (cur->right) {
                    root->right->next=cur->right;
                    break;
                    }
                else cur=cur->next;
            }
            connect(root->right);}
            }
};

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         
        return buildTree(nums,0,nums.size()-1);
        
        
    }
    TreeNode* buildTree(vector<int>& nums, int low, int high) {
        
        if (low>high) return NULL;
        if (low==high) {TreeNode* root=new TreeNode(nums[low]); return root;}
        else {
            int mid=(low+high)/2;
            TreeNode* root=new TreeNode(nums[(low+high)/2]); 
            root->left=buildTree(nums,low,mid-1);
            root->right=buildTree(nums,mid+1,high);
            return root;
        }
    }
};

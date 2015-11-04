#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
     vector<int> result;
     if (!root) return result;
     TreeNode* dummy=new TreeNode(-1);
     dummy->left=root;
     TreeNode* pre;
     TreeNode* cur=dummy;
     while (cur) {
         if (!cur->left) 
             cur=cur->right;
         else {
             pre=cur->left;
             while (pre->right && pre->right !=cur) 
                pre=pre->right;
            if (!pre->right) {
                pre->right=cur;
                cur=cur->left;}
            else {
                reverse(cur->left,pre);
                TreeNode* temp=pre;
                while (temp!=cur->left) {
                    result.push_back(temp->val);
                    temp=temp->right;}
                result.push_back(temp->val);
                reverse(pre,cur->left);
                pre->right=NULL;
                cur=cur->right;
                }
            }
         }
    return result;
     }
    void reverse(TreeNode* start, TreeNode* end) {
        if (start==end) return;
        TreeNode* pre=start;
        TreeNode* cur=start->right;
        TreeNode* next;
        while (pre!=end) {
            next=cur->right;
            cur->right=pre;
            pre=cur;
            cur=next;
        }
    }
};
void print(const vector<int>& nums) {
	if (nums.empty()) return;
	for (int i=0;i<nums.size();i++) 
		cout<<nums[i]<<"  ";
	cout<<endl;}

int main() {
	//test added in remote
	TreeNode* root=new TreeNode(1);
	root->right=new TreeNode(2);
	TreeNode* cur=root->right;
	cur->left=new TreeNode(3);
	Solution m;
	vector<int> result=m.postorderTraversal(root);
	print(result);
	}

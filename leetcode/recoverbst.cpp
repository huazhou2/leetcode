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
    void recoverTree(TreeNode* root) {
        if (!root) return;
	TreeNode* prev,*first,*second;
	prev=first=second=NULL;
        dfs(root,prev,first,second);
        int temp=second->val;
        second->val=first->val;
        first->val=temp;
    }
    void dfs(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
        if (!root) return;
	dfs(root->left,prev,first,second);
	if (prev && prev->val>root->val) {
		if (!first) first=prev;
		second=root;}
	prev=root;
	dfs(root->right,prev,first,second);
	}
};

void print(const TreeNode* root) {
	if (!root) return;
	print(root->left);
	cout<<root->val<<"  ";
	print(root->right);
	}

int main() {
	TreeNode* a=new TreeNode(0);
	TreeNode* b=new TreeNode(1);
	a->left=b;
	//b->left=c;
	print(a);
	cout<<endl;
	Solution m;
	m.recoverTree(a);
	print(a);
	cout<<endl;
}	

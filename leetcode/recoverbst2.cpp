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
	TreeNode *first,*second;
	first=second=NULL;
        morrisTraverse(root,first,second);
        int temp=second->val;
        second->val=first->val;
        first->val=temp;
    }
    void morrisTraverse(TreeNode* root, TreeNode*& first, TreeNode*& second) {
        if (!root) return;
	TreeNode* cur=root,*pre;
	while (cur) {
	if (!cur->left) {
		if (cur->right && cur->val>cur->right->val)
			{	
			if (!first)
				first=cur; 
				second=cur->right;}
		cur=cur->right; }
	else {
		pre=cur->left;
		while (pre->right && pre->right != cur) 
			pre=pre->right;
		if (!pre->right) {
			pre->right=cur;
			cur=cur->left;}
		else {
			pre->right=NULL;
			if (cur->right && cur->val>cur->right->val)
				{if (!first)
					first=cur; 
				second=cur->right;}
			cur=cur->right;}
	}
	}

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

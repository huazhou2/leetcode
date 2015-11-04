#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v): val(v),left(NULL), right(NULL) {};
	};

void MorrisTraverse(TreeNode* root) {
	if (!root) return;
	TreeNode* cur=root, *pre;
	while (cur) {
	if (!cur->left) {
		cout<<cur->val<<"  ";
		cur=cur->right;}
	else {
		//find predecessor
		pre=cur->left;
		while (pre->right && pre->right !=cur)
			pre=pre->right;
		if (!pre->right)
			{
			pre->right=cur;
			cur=cur->left;}
		else {
			pre->right=NULL;
			cout<<cur->val<<"  ";
			cur=cur->right;
		}
		}
	}
}

int main() {
	TreeNode* a=new TreeNode(2); 
	TreeNode* b=new TreeNode(1); 
	TreeNode* c=new TreeNode(3); 
	a->left=b;
	a->right=c;
	MorrisTraverse(a);
	cout<<endl;
	}

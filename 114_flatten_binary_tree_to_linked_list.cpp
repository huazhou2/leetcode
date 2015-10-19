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
    void flatten(TreeNode* root) {
        if (!root) return;
        if (!root->left) flatten(root->right);
        else {
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        TreeNode * temp2=root->right;
        while (temp2->right) temp2=temp2->right;
        temp2->right=temp;
        flatten(root->right);}
    }
};

void print (TreeNode* root) {
	if (!root) return;
	cout<<root->val<<" -> ";
	print(root->left);
	print(root->right);
		}

int main() {
	TreeNode *a=new TreeNode(1);
	TreeNode *b=new TreeNode(2);
	TreeNode *c=new TreeNode(3);
	a->left=b;
	b->left=c;
	print(a);
	Solution m;
	m.flatten(a);
	cout<<endl;
	print(a);
	cout<<endl;
		}


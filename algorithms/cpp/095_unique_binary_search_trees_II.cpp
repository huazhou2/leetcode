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
    vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> result;
	if (n==0) 
	result.push_back(NULL);
	else
        result=dfs(0,n-1);
        return result;
    }
    vector<TreeNode*> dfs(int left, int right) {
        vector<TreeNode*> result;
        if (left==right) {
            TreeNode* root=new TreeNode(left+1);
            result.push_back(root);
            return result;
        }
        for (int mid=left;mid<=right;mid++) {
            vector<TreeNode*> lside,rside;
            if (mid!=left) 
            lside=dfs(left,mid-1);
            if (mid!=right)
            rside=dfs(mid+1,right);
            int lsize,rsize;
            if (mid==left) lsize=1;
            else lsize=lside.size();
            if (mid==right) rsize=1;
            else rsize=rside.size();
            for (int j=0;j<lsize;j++) {
                for (int k=0;k<rsize;k++) {
                    TreeNode* temp=new TreeNode(mid+1);
                    if (mid!=left) 
                    temp->left=lside[j];
                    if (mid!=right)
                    temp->right=rside[k];
                    result.push_back(temp);
                }
            }
        }
    return result;
        }
};

void print_node(TreeNode* result) {
	if (!result) return;
	cout<<result->val<<"->";
	print_node(result->left);
	print_node(result->right);
	}
void print(vector<TreeNode*> result) {
	if (!result.empty()) {
	for (int i=0;i<result.size();i++) {
		print_node(result[i]);
		cout<<endl;
	}
}
}
	
	

int main() {
	Solution m;
	vector<TreeNode*> result= m.generateTrees(10);	
	print(result);
	}

#include <iostream>
#include <limits>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result=std::numeric_limits<int>::min();
        dfs(root,result);
        return result;
        }
    int dfs(TreeNode* root, int& maxi) {
        if (!root) return 0;
        int lhs=dfs(root->left,maxi);
        int rhs=dfs(root->right,maxi);
        int m=root->val;
        if (lhs>=0) m=m+lhs;
        if (rhs>=0) m=m+rhs;
        if (m>=maxi) maxi=m;
        return max(lhs,rhs)>=0? max(lhs,rhs)+root->val:root->val;
    }
};

int main() {
	TreeNode * root=new TreeNode(2);
	TreeNode * a=new TreeNode(-1);
	TreeNode * b=new TreeNode(3);
	TreeNode * c=new TreeNode(3);
	root->left=a;
	root->right=b;
	a->left=c;
	Solution m;
	cout<<m.maxPathSum(root)<<endl;	}
	

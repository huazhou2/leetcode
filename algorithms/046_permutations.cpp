#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(nums,path,result);
        return result;
    }
    void dfs(vector<int>&nums, vector<int>& path, vector<vector<int> >& result) {
        if (nums.empty()) result.push_back(path);
        for (vector<int>::iterator  it=nums.begin();it!=nums.end();it++) {
            path.push_back(*it);
	    vector<int> temp=nums;
            nums.erase(it);
            dfs(nums,path,result);
            path.pop_back();
		nums=temp;
        }
    }
};

void print(vector<vector<int> >& result) {
	if (!result.empty()) {
	for (int i=0;i<result.size();i++) {
		for (int j=0;j<result[i].size();j++) 
			cout<<result[i][j]<<"  ";
		cout<<endl;
	}
	}
}

int main() {
	int num[]={1,2,3,8,11,17,14,6};
	vector<int> nums(num,num+sizeof(num)/sizeof(int));
	Solution m;
	vector<vector<int> > result=m.permute(nums);
	print(result);
	}
	

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> path;
        std::sort(nums.begin(),nums.end());
        for (int i=0;i<=nums.size();i++) 
            dfs(nums,0,i,0,path,result);
        return result;
    }
    void dfs(vector<int>& nums, int start,int length, int deep, vector<int>& path, vector<vector<int> >& result)     {
        if (deep==length) result.push_back(path);
        for (int i=start;i<nums.size();i++) {
            if (i>start && nums[i-1]==nums[i]) continue;
            path.push_back(nums[i]);
            dfs(nums,i+1,length,deep+1,path,result);
            path.pop_back();
        }
        return;
        }
};

	void print(const vector<vector<int> >& nums) {
		if (!nums.empty()) {
		for (int i=0;i<nums.size();i++) {
			for (int j=0;j<nums[i].size();j++)
				cout<<nums[i][j]<<"  ";
			cout<<endl;}
		}
	}

int main() {
	int a[]={15,16,17,20,19,18,10,11,12,14,9,7,8,4,5,6,3,2,1};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution m;
	vector<vector<int> > result=m.subsetsWithDup(nums);
	print(result);
	}

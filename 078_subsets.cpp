class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> path;
        result.push_back(path);
        sort(nums.begin(),nums.end());
        for (int count=1;count<=nums.size();count++) {
            dfs(nums,count,0,-1,path,result);
        }
        return result;
    }
    void dfs(vector<int>& nums, int count, int deep, int start, vector<int>& path, vector<vector<int> >& result) {
            if (deep==count) {result.push_back(path);return;}
            for (int i=start+1;i<nums.size();i++) {
                path.push_back(nums[i]);
                dfs(nums,count,deep+1,i,path,result);
                path.pop_back();
            }
            return;
        }
};

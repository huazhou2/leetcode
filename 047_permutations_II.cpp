class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        if (nums.empty()) return result;
        vector<int> path;
        vector<int> visited(nums.size(),0);
        dfs(nums,visited,path,result,0);
        return result;
    }
    void dfs(vector<int>& nums, vector<int>& visited, vector<int>& path, vector<vector<int> >& result, int deep) {
        if (deep==nums.size()) result.push_back(path);
        unordered_set<int> used;
        for (int i=0;i<visited.size();i++) {
            if (!visited[i]) {
                unordered_set<int>::iterator it=used.find(nums[i]);
                if (it == used.end()) {
                    used.insert(nums[i]);
                    path.push_back(nums[i]);
                    visited[i]=1;
                    dfs(nums,visited,path,result,deep+1);
                    visited[i]=0;
                    path.pop_back();
                }
                }
            } 
        }
};

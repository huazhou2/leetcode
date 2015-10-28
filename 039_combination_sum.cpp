class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates,0,target,0,path,result);
        return result;
    }
    void dfs(vector<int>& candidates, int sum, int target, int start, vector<int>&path, vector<vector<int> > & result) {
        if (sum>target) return;
        if (sum==target) result.push_back(path);
        for (int i=start;i<candidates.size();i++) {
            if (sum+candidates[i]>target) break;
            path.push_back(candidates[i]);
            dfs(candidates, sum+candidates[i],target, i, path,result);
            path.pop_back();
        }
        return;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,-1,path,result);
        return result;
    }
    void dfs(vector<int>& candidates, int target, int sum, int start, vector<int>& path, vector<vector<int> >& result) {
        if (sum>target) return;
        if (sum==target) {
            bool add=true;
            for (int index=0;index<result.size();index++) {
                if (path.size()==result[index].size() && path==result[index] ) {add=false; break;}
            }
            if (add) result.push_back(path);
        }
        for (int i=start+1;i<candidates.size();i++) {
            if (sum+candidates[i]>target) break;
            path.push_back(candidates[i]);
            dfs(candidates,target, sum+candidates[i],i,path,result);
            path.pop_back();
        }
        return;
        }
};

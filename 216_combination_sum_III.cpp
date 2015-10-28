class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(result,path,n,0,0,k,0);
        return result;
    }
    void dfs(vector<vector<int> >& result, vector<int>& path, int target, int sum, int deep, int count, int start) {
        if (deep==count) {
            if (sum==target) result.push_back(path);
            return;}
        for (int i=start+1;i<10;i++) {
            if (sum+i>target) break;
            path.push_back(i);
            dfs(result,path,target, sum+i,deep+1,count,i);
            path.pop_back();
            }
        
        }
};

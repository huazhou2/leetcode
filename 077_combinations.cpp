class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(result,path,n,0,k,0);
        return result;
    }
    void dfs(vector<vector<int> >& result, vector<int>& path, int n, int deep, int deep_limit,int start) {
        if (deep==deep_limit) result.push_back(path);
        for (int i=start+1;i<=n;i++) {
            path.push_back(i);
            dfs(result,path,n,deep+1,deep_limit,i);
            path.pop_back();
        }
        return;
        }
};

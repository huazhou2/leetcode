class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        dfs(n,0,0,path,result);
        return result;
    }
    void dfs(int total, int leftsum, int rightsum, string& path, vector<string>& result) {
        if (leftsum==rightsum && leftsum==total) result.push_back(path);
        if (leftsum>=rightsum) {
            
            if (leftsum<total) {
                path+='(';
                dfs(total,leftsum+1,rightsum,path,result);
                path.erase(path.end()-1);}
            if (leftsum>rightsum) {
                path+=')';
                dfs(total,leftsum,rightsum+1,path,result);
                path.erase(path.end()-1);}
            }
        else return;
        }
};

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        string path("");
        dfs(num,target,0,0,path,result);
        return result;
    }
    void dfs(string num, int target, long cur, long diff, string path, vector<string>& result) {
        if (num.empty() && target==cur)  result.push_back(path);
        for (int i=1;i<num.size();i++) {
            string left=num.substr(0,i);
            string right=num.substr(i);
            long long val=stoll(left);
            if (left.size()>1 && left[0]=='0') return;
            if (path.empty())
            dfs(right,target, val, val, left, result);
            else {
            dfs(right,target, cur+val, val, path+'+'+left, result);
            dfs(right,target, cur-val, val, path+'-'+left, result);
            dfs(right,target, cur-diff+val*diff, val*diff, path+'*'+left, result);
            }
        }
    }
};

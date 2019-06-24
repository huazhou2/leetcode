class Solution {
public:
    vector<string> addOperators(string num, int target) {
    vector<string> result;
    if (num.empty()) return result;
    string path("");
    dfs(num,2,1,0,num[0]-'0',0,target,path,result);
    return result;
    }
    void dfs(string& num, int presign, int start, long prev, long cur, long total, int target, string& path, vector<string>& result) {
        if (start==num.size()) {
            int final;
            switch (presign) {
                case 1:
                    final=prev*cur+total;
                    break;
                case 2:
                    final=prev+cur+total;
                    break;
                case 3:
                    final=prev+cur+total;
                    break;
            }
            if (final==target) result.push_back (path+num.back());
            else return;
            }
        switch (presign) {
            case 1:
                dfs(num,1,start+1,prev*cur,num[start]-'0',total,target,path+num[start]+'*', result);//multiply
                dfs(num,2,start+1,0,num[i]-'0',total+prev*cur,target,path+num[start]+'+', result); //add
                dfs(num,3,start+1,0,num[i]-'0',total+prev*cur,target,path+num[start]+'-', result); //minus
                if (cur!=0)
                dfs(num,1,start+1,prev,cur*10+cur, total,path+num[start], result); //extend
                break;
            case 2:
                dfs(num,1,start+1,cur,num[i]-'0',total,target,path+num[start]+'*', result);//multiply
                dfs(num,2,start+1,0,num[i]-'0',total+cur,target,path+num[start]+'+', result); //add
                dfs(num,3,start+1,0,num[i]-'0',total+cur,target,path+num[start]+'-', result); //minus
                if (cur!=0)
                dfs(num,2,start+1,0,cur*10+cur, total,path+num[start], result); //extend
                break;
            case 3:
                dfs(num,1,start+1,-cur,num[i]-'0',total,target,path+num[start]+'*', result);//multiply
                dfs(num,2,start+1,0,num[i]-'0',total-cur,target,path+num[start]+'+', result); //add
                dfs(num,3,start+1,0,num[i]-'0',total-cur,target,path+num[start]+'-', result); //minus
                if (cur!=0)
                dfs(num,3,start+1,0,cur*10+cur, total,path+num[start], result); //extend
                break; 
        }
}
 };

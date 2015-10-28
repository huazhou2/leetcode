class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        s="#"+s;
        vector<bool> possible(s.size(),false);
        possible[0]=true;
        for (int i=1;i<s.size();i++) {
            for (int k=0;k<i;k++) {
                possible[i]=possible[k] && (wordDict.find(s.substr(k+1,i-k)) != wordDict.end());
                if (possible[i]) break;
            }
        }
        return possible[s.size()-1];
    }
};

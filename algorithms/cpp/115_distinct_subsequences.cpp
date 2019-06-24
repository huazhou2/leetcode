class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.empty()) return 1;
        if (s.empty()) return 0;
        vector<vector<int> > panel(t.size()+1,vector<int>(s.size()+1,0));
        for (int j=0;j<=s.size();j++) panel[0][j]=1;
        for (int i=1;i<=t.size();i++) {
            for (int j=1;j<=s.size();j++) 
                if (t[i-1]==s[j-1]) panel[i][j]=panel[i][j-1]+panel[i-1][j-1];
                else panel[i][j]=panel[i][j-1];
        }
        return panel.back().back();}
};

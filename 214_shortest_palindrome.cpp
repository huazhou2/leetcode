class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return "";
        string orig(s);
        reverse(s.begin(),s.end());
        string t=orig+"#"+s;
        vector<int> next(t.size(),0);
        for (int i=1;i<t.size();i++) {
            int j=next[i-1];
            while (j>0 && t[i]!=t[j])
            j=next[j-1];
            if (t[i]==t[j])
            j++;
            next[i]=j;
        }
        return s.erase(s.size()-next.back())+orig;
    }
};

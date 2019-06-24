class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if (strs.empty()) return result;
        if (strs.size()==1) return strs[0];
        for (int i=0;;i++) {
            for (int j=0;j<strs.size()-1;j++) {
                if (i>=strs[j].size()) return result;
                if (strs[j][i] != strs[j+1][i]) return result;
            }
        result=result+strs[0][i];
                }
    return result;
        
    }
};

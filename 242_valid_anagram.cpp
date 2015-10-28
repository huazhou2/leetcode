class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!= t.size()) return false;
        for (int i=0;i<s.size();i++) {
            auto pos=t.find(s[i]);
            if (pos==string::npos) return false;
            else t.erase(pos,1);
        }
        return true;
        
    }
};

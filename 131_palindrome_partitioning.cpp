class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        vector<string> temp;
        if (s.empty()) return result;
        findPalindrome(s,temp,result);
        return result;
    }
    void findPalindrome(string s, vector<string>& temp, vector<vector<string> >& result) {
        if (s.empty()) {result.push_back(temp);return;}
        for (int i=1;i<=s.size();i++) {
            string front(s.substr(0,i)), back(s.substr(i));
            if (isPalindrome(front)) {
                temp.push_back(front);
                findPalindrome(back, temp,result);
                temp.pop_back();
            }
            }
    }
    bool isPalindrome(string& s) {
        if (s.empty()) return false;
        for (int i=0;i<s.size()/2;i++) 
            if (s[i] != s[s.size()-i-1]) return false; 
        return true;
    }
};

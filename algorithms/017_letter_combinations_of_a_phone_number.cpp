class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string result;
        vector<string> trans={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> set;
        if (digits.empty()) return set;
        procedure(trans,digits,0, result, set);
        return set;
        }
    void procedure(vector<string> & trans, string& digits, int deep, string &result, vector<string> & set )    {
        if (deep==digits.size()) {
            set.push_back(result);
            return;}
        int curdig=digits[deep]-'1';
        for (int i=0;i<trans[curdig].size();i++) {
            result.push_back(trans[curdig][i]);
            procedure(trans,digits,deep+1, result,set);
            result.resize(result.size()-1);
        }
    }
};

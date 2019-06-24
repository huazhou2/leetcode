class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        for (int i=0;i<s.size();i++) {
            int temp=s[s.size()-i-1]-'A'+1;
            result+= temp*pow(26,i);
        }
        return result;
    }
};

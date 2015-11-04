class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> result;
        if (s.size()==1) return s[0]-'0'? 1:0;
        result.push_back(s[0]-'0'? 1:0);
        int sum=0,temp=0;
        sum=10*(s[0]-'0')+s[1]-'0';
        temp= (s[1]-'0'? result[0]:0) + (sum>=10 && sum<=26? 1:0);
        if (s.size()==2)  return temp;
        else result.push_back(temp);
        for (int i=2;i<s.size();i++) {
            if (result[i-2]+result[i-1]==0) return 0;
            else {
                temp=s[i]-'0'>0?result[i-1]:0;
                sum=10*(s[i-1]-'0')+s[i]-'0';
                temp=temp+((sum<=26 && sum>=10)?result[i-2]:0);
                result.push_back(temp);
            }
            }
        return result.back();
    }
};

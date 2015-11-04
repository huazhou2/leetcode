class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size()<11) return result;
        unordered_map<long,int> map;
        for (int i=0;i<s.size()-9;i++) {
            long temp=str2long(s.substr(i,10));
            unordered_map<long,int>::iterator it;
            if (map.find(temp)==map.end()) map[temp]=1;
            else {
                map[temp]++;
                if (map[temp]==2)
                result.push_back(s.substr(i,10));
                }
        }
        return result;
            }
    long str2long(string s) {
        long result=0;
        for (int i=0;i<s.size();i++) {
            switch(s[i]) {
                case 'A':
                result =result*10+1;
                break;
                case 'T':
                result=result*10+2;
                break;
                case 'C':
                result=result*10+3;
                break;
                case 'G':
                result=result*10+4;
                default:
                break;}
        }
        return result;
        }
};

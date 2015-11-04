
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string,char> map1;
        unordered_map<char,string> map2;
        if (pattern.empty())
            if (str.empty()) return true;
            else return false;
        int start=0;
        str=str+' ';
        int i=0;
        for (;i<pattern.size();i++) {
            string temp("");
            for (int j=start;j<str.size();j++) {
                if (str[j]==' ') {
                    temp=str.substr(start,j-start);
                    start=j+1;
                    break;}
                }
            if (temp=="") return false;
            unordered_map<string,char>::iterator it=map1.find(temp);
            if (it!=map1.end()) {
                if (it->second != pattern[i]) return false;
            }
            else map1[temp]=pattern[i];
            unordered_map<char,string>::iterator iter=map2.find(pattern[i]);
            if (iter!=map2.end()) {
                if (iter->second !=temp) return false;
            }
            else map2[pattern[i]]=temp;
            }
        return start==str.size();
        }
};

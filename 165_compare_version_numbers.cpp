class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1,s2;
        s1=0;
        s2=0;
        if (version1.empty() && version2.empty()) return 0;
        if (version1.size()>0) s1=stoi(version1);
        if (version2.size()>0) s2=stoi(version2);
        if (s1>s2) return 1;
        else if (s1<s2) return -1;
        else {
            auto pos=version1.find(".");
            if (pos>version1.size()) version1="";
            else version1=version1.substr(pos+1);
             pos=version2.find(".");
            if (pos>version2.size()) version2="";
            else version2=version2.substr(pos+1);
            return compareVersion(version1, version2);
        }
    }
};

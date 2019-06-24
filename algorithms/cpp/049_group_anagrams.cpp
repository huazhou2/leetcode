class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        if (strs.empty()) return result;
        std::sort(strs.begin(),strs.end());
        unordered_map<string,vector<string> > mymap;
        for (int i=0;i<strs.size();i++) {
          string temp(strs[i]);
          std::sort(temp.begin(),temp.end());
          mymap[temp].push_back(strs[i]);}
        for (unordered_map<string,vector<string> >::iterator it=mymap.begin(); it!=mymap.end();it++) 
            result.push_back(it->second);
        return result;
    }
};

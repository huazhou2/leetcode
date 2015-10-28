class Solution {
public:
    bool isIsomorphic(string s, string t) { 
        
        
        return isIsomorphic2(s,t) && isIsomorphic2(t,s);}
private:
    bool isIsomorphic2(string s, string t) {
        if (s.size() != t.size())
                return false;
        unordered_map<char,int> charMap;
        int dist;
        for (int i=0;i<s.size();i++){
                dist=s[i]-t[i];
                auto map_it=charMap.find(s[i]);
                if (map_it != charMap.end() && dist !=map_it->second)
                        return false;
                charMap[s[i]]=dist;
                }
        return true;
     
    }
};

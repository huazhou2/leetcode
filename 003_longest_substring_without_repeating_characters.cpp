class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0,left=0; //use left position to identify the leftmost window coordinate
        unordered_map<char,int> map; //map to store the index
        for (int i=0;i<s.size();i++) {
            unordered_map<char,int>::iterator it=map.find(s[i]);
  if (it!=map.end() && it->second>=left) {  //check if new element has repeats within current window,
                                                                      //it should be to the right of leftmost position of window 
    int temp=i-left;
                max=max>temp?max:temp;
                left=it->second+1;
            }
            map[s[i]]=i;
            }
        int last=s.size()-left;
        max=max>last?max:last;
        return max;
            }
};

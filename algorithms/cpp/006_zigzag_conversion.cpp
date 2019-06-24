class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        string result("");
        for (int i=0;i<numRows;i++) {
           int gap=2*(numRows-i%(numRows-1)-1);
           for (int j=i;j<s.size();j=j+2*(numRows-1)) {
               result=result+s[j];
               if (i>0 && i<numRows-1 && j+gap<s.size())
               result=result+s[j+gap];
           }
        }
        return result;
    }
};

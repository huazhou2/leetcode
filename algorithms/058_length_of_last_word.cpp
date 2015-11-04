class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        bool flag=0;
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i]==' ') {
                if (!flag) continue;
                else break;
            }
            else {
                if (!flag)  {flag=1; count++;}
                else count++;
            }
        }
        return count;
        }
};

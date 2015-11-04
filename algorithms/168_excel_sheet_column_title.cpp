class Solution {
public:
    string convertToTitle(int n) {
        string result="";
        do {
            n=n-1;
            result=char(n%26+int('A'))+result;
            n=n/26;
            } while(n);
        return result;
        }
};

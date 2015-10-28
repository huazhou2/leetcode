class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result=0;
        vector<bool> m1,n1;
        int count=0;
        while(m) {
            m1.insert(m1.begin(),m%2);
            m=m/2;}
        while(n) {
            n1.insert(n1.begin(),n%2);
            n=n/2;}
        if (n1.size()>m1.size()) return 0;
        for (int i=0;i<m1.size();i++) {
            if (m1[i] && n1[i]) result+= pow(2,m1.size()-1-i);
            if (!m1[i] && !n1[i]) continue;
            if (m1[i]+n1[i]==1) break;
        }
        return result;

    }
};

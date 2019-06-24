class Solution {
public:
    void reverseWords(string &s) {
        bool flag=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]==' ') 
                if (!flag) flag=1;
                else {s.erase(i,1);i--;}
            else flag=0;
            }
        if ( !s.empty() && s[0]==' ') s.erase(0,1);
        if (!s.empty() && s.back()==' ') s.erase(s.size()-1,1);
        if (s.size()>2) {
        reverseString(s,0,s.size()-1);
        int prev=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]==' ') {reverseString(s,prev,i-1);prev=i+1;}
            
        }
        reverseString(s,prev,s.size()-1);
        }
    }

    void reverseString(string &s, size_t start, size_t end) { 
        char temp;
        
        for (start;start<=(end+start)/2;start++,end--) {
            temp=s[end];
            s[end]=s[start];
            s[start]=temp;
        }
    }
};

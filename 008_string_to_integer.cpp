class Solution {
public:
    int myAtoi(string str) {
        vector<char> result;
        int sign=1;
        if (str=="") return 0;
        bool flag=0;
       
        for (int i=0;i<str.size();i++) {
            if (str[i]==' ') continue;
            if (!flag) {
            if (str[i]=='-') {sign=-1;flag=1;}
             if (str[i]=='+') {flag=1;}
            if (str[i]<='9' && str[i]>='0') {
                flag=1; result.push_back(int(str[i]-'0'));}
            if (str[i]=='.') break;
        }
        else {
            if (str[i]<='9' && str[i]>='0') {
                flag=1; result.push_back(int(str[i]-'0'));}
        else break;
           
        }}
        int final=0;

        for (int i=0;i<result.size();i++) {
            final+= result[i]*pow(10,result.size()-1-i);
        }
        return sign*final;
    }
};

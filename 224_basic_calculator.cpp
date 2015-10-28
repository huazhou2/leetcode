ass Solution {
public:
    int calculate(string s) {
        strip(s);
        long result=0;
        stack<char> operation;
        stack<long> number;
        char sign='+';
        bool num_flag=false;
        int cur=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]<='9' && s[i]>='0') {
                if (!num_flag) {cur=s[i]-'0';num_flag=true;}
                else cur=cur*10+s[i]-'0';
            }
            else {
            if (num_flag) {num_flag=false;
           
                if (sign=='+') result+=cur;
                else if (sign=='-') result-=cur;
                cur=0;}
            }
            if (s[i]=='(') 
                {operation.push(sign);
                number.push(result);
                result=0;
                sign='+';
                }
            if (s[i]==')') {
                if (operation.top()=='+') result+=number.top();
                else if (operation.top()=='-') result= number.top()-result;
                operation.pop();
                number.pop();
            }
            if (s[i]=='+' || s[i]=='-') sign=s[i];
        }
        if (sign=='-') result-=cur;
        else if (sign='+') result+=cur;
        return result;
    }
        
    void strip(string& s) {
        int size_n=s.size();
        for (int i=0;i<size_n;i++) 
            if (s[size_n-i-1]==' ') s.erase(size_n-i-1,1);
        }
};

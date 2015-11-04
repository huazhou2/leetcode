class Solution {
public:
    int calculate(string s) {
        queue<char> operation,work_op;
        queue<int> number,work_num;
        bool num_flag=false,work=false;
        int cur=0;
        char sign='+';
        s=s+'+';
        for (int i=0;i<s.size();i++) {
            if (s[i]<='9' && s[i]>='0') {
                if (num_flag) cur=cur*10+s[i]-'0';
                else {
                    num_flag=true;
                    cur=s[i]-'0';} }
            if (s[i]==' ') continue;
            if (s[i]=='+' || s[i]=='-') {
                if (work_op.empty()){
                number.push(cur);
                }
                else {
                work_num.push(cur);
                int temp=work_num.front();
                work_num.pop();
                while(!work_op.empty()) {
                    temp=work_op.front()=='*'? temp*work_num.front():temp/work_num.front();
                    work_op.pop();
                    work_num.pop();
                }
                number.push(temp);
                }
                operation.push(s[i]);
                cur=0;
                num_flag=false;   
                }
            if (s[i]=='*' || s[i]=='/') {
                work_op.push(s[i]);
                work_num.push(cur);
                cur=0;
                num_flag=false;
            }
            }
      int result=number.front();
      number.pop();
      while (!number.empty()) {
            result=operation.front()=='+'? result+number.front():result-number.front();
            number.pop();
            operation.pop();
      }
      return result;
    }
};

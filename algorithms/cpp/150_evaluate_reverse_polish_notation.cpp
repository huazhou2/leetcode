class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operand;
        for (int i=0;i<tokens.size();i++) {
            if (tokens[i].size()==1 && !isdigit(tokens[i][0])) {
                    int right=operand.top();
                    operand.pop();
                    int left=operand.top();
                    operand.pop();
                    int result;
                    switch (tokens[i][0]) {
                        case '+':
                            result=left+right;
                            break;
                        case '-':
                            result=left-right;
                            break;
                        case '*':
                            result=left*right;
                            break;
                        case '/':
                            result=left/right;
                            break;
                    }
            operand.push(result);
            }
            else {
                int temp=0;
                bool sign=false;
                int j=0;
                if (tokens[i][0]=='+' || tokens[i][0]=='-') {
                    j=1;
                    sign=tokens[i][0]=='-';
                }
                for (;j<tokens[i].size();j++) 
                    temp=10*temp+tokens[i][j]-'0';
                temp=sign?(-temp):temp;
                operand.push(temp);
            }
        }
             return operand.top();   
    }
};

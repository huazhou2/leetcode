class Solution {
public:
    bool isValid(string s) {
        
                stack<char> paren;
                for (int i=0; i<s.size();i++) {
                        if (s[i] == '(' || s[i] == '{' || s[i]=='[')
                                paren.push(s[i]);
                        else
                                if (paren.empty()) return false;
                                else
                                {
                                      if ( paren.top() =='(' && s[i]==')' || paren.top() == '{' && s[i]=='}' || paren.top()=='[' && s[i]==']')
                                        paren.pop();
                                        else
                                return false;
                                }
        }
        if (paren.empty()) 
        return true;
        else 
        return false;
    }
};

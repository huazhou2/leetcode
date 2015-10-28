class Solution {
public:
    int longestValidParentheses(string s) {
       stack<int> index;
       index.push(-1);
       int max=0;
       for (int i=0;i<s.size();i++) {
           if (s[i]=='(') index.push(i);
           else {
               if (index.top()==-1 || s[index.top()]==')') 
                    index.push(i);
               else  index.pop();
               if (max<i-index.top()) max=i-index.top();
           }
       }
       return max;
    }
};

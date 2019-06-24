class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int index=0;
        int temp=0;
        for (;index<input.size();index++) {
            if (isdigit(input[index])) temp=temp*10+input[index]-'0';
            else break;
        }
        if (index==input.size()) {result.push_back(temp); return result;}
        for (int i=0;i<input.size();i++) {
            if (isdigit(input[i])) continue;
            else {
                vector<int> left=diffWaysToCompute(input.substr(0,i));
                vector<int> right=diffWaysToCompute(input.substr(i+1));
                for (int j=0;j<left.size();j++) {
                    for (int  k=0;k<right.size();k++) {
            
                        switch(input[i]) {
                            case '+': 
                            result.push_back(left[j]+right[k]);
                            break;
                            case '-':
                            result.push_back(left[j]-right[k]);
                            break;
                            case '*':
                            result.push_back(left[j]*right[k]);
                            break;
                                }
                    }
                }
                }
            }
        
        return result;
    }
};

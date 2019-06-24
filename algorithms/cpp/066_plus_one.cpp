class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> res;
        int carry=1;
        for (int i=0;i<digits.size();i++) {
            int sum=(digits[digits.size()-1-i]+carry)%10;
            carry=(digits[digits.size()-1-i]+carry)/10;
            res.push(sum);
        }
        if (carry) res.push(1);
        vector<int> result;
        while(!res.empty()) {
            result.push_back(res.top());
            res.pop();
        }
        return result;
    }
};

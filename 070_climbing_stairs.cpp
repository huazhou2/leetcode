class Solution {
public:
    int climbStairs(int n) {
        vector<int> result;
        result.push_back(1);
        result.push_back(2);
        for (int i=3;i<=n;i++) {result.push_back(result[i-3]+result[i-2]);}
        return result[n-1];
        
    }
};

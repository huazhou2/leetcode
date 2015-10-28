class Solution {
public:
    int numSquares(int n) {
        vector<int> result(n+1,std::numeric_limits<int>::max());
        result[0]=0;
        for (int i=0;i<=n;i++) {
            for (int j=1;i+j*j<=n;j++) {
                result[i+j*j]=min(result[i+j*j], result[i]+1);
            }
        }
        return result.back();
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size()==0) return 0;
        vector<int> temp= triangle.back();
        for (int i=triangle.size()-2;i>=0;i--) {
            for (int j=0;j<=i;j++) {
                temp[j]=min(triangle[i][j]+temp[j], triangle[i][j]+temp[j+1]);
            }
        }
        return temp[0];
        }
};

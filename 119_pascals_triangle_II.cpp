class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > res={vector<int> (rowIndex+1), vector<int> (rowIndex+1)};
        for (int i=0;i<=rowIndex;i++) {
            res[i&1][0]=res[i&1][rowIndex]=1;
            for (int j=1;j<rowIndex;j++) {
                res[i&1][j]=res[(i+1) &1][j-1]+res[(i+1)&1][j];
            }
    }
    return res[rowIndex&1];
    }
};

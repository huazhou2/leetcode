class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[i].size();j++) {
                if (!matrix[i][j]) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        if (!row.empty()) {
        for (unordered_set<int>::iterator it=row.begin(); it !=row.end();it++) {
            for (int j=0;j<matrix[0].size();j++) 
                matrix[*it][j]=0;
        }
        }
        if (!col.empty()) {
        for (unordered_set<int>::iterator it=col.begin(); it!=col.end();it++) {
            for (int j=0;j<matrix.size();j++)
                matrix[j][*it]=0;
        }
        }
    }
};

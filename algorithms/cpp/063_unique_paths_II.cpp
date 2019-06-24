class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int value=obstacleGrid[0][0]?0:1;
        for (int i=1;i<obstacleGrid.size();i++) {
            if (obstacleGrid[i][0]==1) value=0;
            obstacleGrid[i][0]=value;
        }
        value=obstacleGrid[0][0]?0:1;
        for (int j=1;j<obstacleGrid[0].size();j++) {
            if (obstacleGrid[0][j]==1) value=0;
            obstacleGrid[0][j]=value;
        }
        obstacleGrid[0][0]=1-obstacleGrid[0][0];
        for (int i=1;i<obstacleGrid.size();i++) 
            for (int j=1;j<obstacleGrid[i].size();j++) 
                if (obstacleGrid[i][j]==0) 
                obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                else obstacleGrid[i][j]=0;
                
        return obstacleGrid.back().back();
            }
};

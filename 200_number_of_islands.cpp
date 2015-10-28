class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int number=0;
        for (int i=0;i<grid.size();i++) {
                for (int j=0;j<grid[0].size();j++) {
                        if (grid[i][j] != '1')  continue;
                        number++;
                        dfs(grid,i,j);
                }
        }
        return number;
    }
    
    void dfs(vector<vector<char> >& grid, int i, int j) {
        if (i<0 || j<0 || i >= grid.size() || j>= grid[0].size()) return;
        if (grid[i][j] != '1') return;
        else {
            grid[i][j]='2';
            dfs(grid,i-1,j);
            dfs(grid,i,j-1);
            dfs(grid,i+1,j);
            dfs(grid,i,j+1);
        }
    }
};

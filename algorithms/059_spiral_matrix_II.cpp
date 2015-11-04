class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n<=0) {
            vector<vector<int> > matrix;
            return matrix;}
        vector<vector<int> > matrix(n,vector<int>(n,0));
        int row=0, col=0,count=0,limit=n*n;
        int direction=1;
        int i=0,j=-1;
        while (count<limit) {
            switch (direction) {
                case 1:
                if (matrix[0].size()-col-1-j>0) j++;
                else {
                    direction =2;
                    i++;
                    row++;}
                break;
                case 2:
                if (i<matrix.size()-row) i++;
                else {direction =3;
                        j--;
                        col++;}
                        break;
                break;
                case 3:
                if (j>=col) j--;
                else {direction =4;
                        i--;}
                        break;
                case 4:
                if (i>row) i--;
                else {
                    direction =1;
                    j++;}
                    break;
            }
            matrix[i][j]=++count;
                }
            return matrix;
        }
};

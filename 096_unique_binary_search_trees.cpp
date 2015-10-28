class Solution {
public:
    int numTrees(int n) {
    vector<int> mat;
    if (n<=2) return n;
    mat.push_back(1);
    mat.push_back(1);
    mat.push_back(2);
    for (int i=3;i<=n;i++) {
        int result=0;
        for (int j=0;j<=(i-1)/2;j++) result+=mat[j]*mat[i-1-j];
        result<<=1;
        if (i%2) result=result-mat[i/2]*mat[i/2];
        mat.push_back(result);
    }
    return mat.back();
    }
};

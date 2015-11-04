class Solution {
public:
    int totalNQueens(int n) {
        vector<pair<int, int> > temp;
        int result=0;
        solveNQ(n,0,temp,result);
        return result;
    }
   void solveNQ(int n,int deep, vector<pair<int,int> > & temp, int& result) {
        if (deep==n) result=result+1;
        for (int i=0;i<n;i++) {
                if (isCorrect(i,temp)) {
                        temp.push_back(make_pair(deep,i));
                        solveNQ(n,deep+1,temp,result);
                        temp.pop_back();
                }
                }
        }
    bool isCorrect(int col, vector<pair<int, int> > & result) {
            if (result.empty()) return true;
            int size=result.size();
            for (int i=0;i<result.size();i++) {
                    int t1=result[i].first;
                    int t2=result[i].second;
                    bool correct=(abs(size-t1)!=abs(col-t2)) && col!=t2;
                    if (!correct) return false;
            }
            return true;
    }
};
